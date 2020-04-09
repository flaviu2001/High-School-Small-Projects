#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "prietene";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int test, queries, d[155], qu[155], pq, vq, ad[155][155];
set<int> v[155], vt[155];
bitset<150> b[150], full;

void construct(int x)
{
    pq = 0;
    vq = 1;
    qu[1] = x;
    d[x] = 1;
    while(pq != vq){
        int k = qu[++pq];
        if(d[k] == 3)
            return;
        for (auto y : v[k])
            if(d[y] == 0){
                qu[++vq] = y;
                d[y] = d[k]+1;
                b[x][y] = 1;
            }
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test;
    while(test--){
        int n, m;
        fin >> n >> m;
        for (int i = 0; i < n; ++i)
            b[i].reset();
        for (int i = 0; i < n; ++i){
            v[i].clear();
            vt[i].clear();
        }
        memset(ad, 0, sizeof(ad));
        for (int i = 1; i <= m; ++i){
            int x, y;
            fin >> x >> y;
            --x, --y;
            v[x].insert(y);
            vt[y].insert(x);
        }
        full.set();
        for (int i = 0; i < n; ++i){
            memset(d, 0, sizeof(d));
            construct(i);
            for (auto x : v[i]){
                ++ad[i][x];
                for (auto y : v[x])
                    ++ad[i][y];
            }
        }
        fin >> queries;
        while(queries--){
            char q;
            int x, y;
            fin >> q;
            if(q == 'q'){
                fin >> x >> y;
                --x, --y;
                full.set(x, 0);
                full.set(y, 0);
                fout << ((b[x]&full) == (b[y]&full) ? "YES\n" : "NO\n");
                full.set(x);
                full.set(y);
            }else if (q == 'a'){
                fin >> x >> y;
                --x, --y;
                v[x].insert(y);
                vt[y].insert(x);
                for (auto z : v[y]){
                    b[x][z] = 1;
                    ++ad[x][z];
                }
                for (auto z : vt[x]){
                    b[z][y] = 1;
                    ++ad[z][y];
                }
                ++ad[x][y];
                b[x][y] = 1;
            }else{
                fin >> x >> y;
                --x, --y;
                v[x].erase(v[x].find(y));
                vt[y].erase(vt[y].find(x));
                for (auto z : v[y]){
                    --ad[x][z];
                    if(ad[x][z] == 0)
                        b[x][z] = 0;
                }
                for (auto z : vt[x]){
                    --ad[z][y];
                    if(ad[z][y] == 0)
                        b[z][y] = 0;
                }
                --ad[x][y];
                if(ad[x][y] == 0)
                    b[x][y] = 0;
            }
        }
    }
    return 0;
}
