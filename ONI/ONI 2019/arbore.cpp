#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, B = 250, nmax = 100005, VMAX = 1000001;

int n, test, e[nmax], first[nmax], last[nmax], p, add[nmax], v[nmax];
vector<int> g[nmax];
bitset<VMAX> ok[nmax/B+5];

void dfs(int x, int pred = 0)
{
    e[++p] = x;
    first[x] = p;
    for (auto y : g[x])
        if(y != pred)
            dfs(y, x);
    last[x] = p;
}

void resetBucket(int a)
{
    for (int i = max((a/B)*B, 1); i/B == a/B && i <= n; ++i)
        ok[a/B][v[i]] = 0;
    for (int i = max((a/B)*B, 1); i/B == a/B && i <= n; ++i){
        v[i] += add[a/B];
        ok[a/B][v[i]] = 1;
    }
    add[a/B] = 0;
}

int main()
{
    ifstream fin ("arbore.in");
    ofstream fout ("arbore.out");
    fin >> n >> test;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    e[0] = e[1];
    while(test--){
        int t;
        fin >> t;
        if(t == 1){
            int nod, val;
            fin >> nod >> val;
            int a = first[nod], b = last[nod];
            if(a == 1)
                a = 0;
            if(a/B == b/B){
                if(b-a+1 == B)
                    add[a/B] += val;
                else{
                    for (int i = a; i <= b; ++i){
                        ok[a/B][v[i]] = 0;
                        v[i] += val;
                    }
                    resetBucket(a);
                }
            }else{
                if(a != 0 && a/B == (a-1)/B){
                    for (int i = a; i/B == a/B && i <= n; ++i){
                        ok[a/B][v[i]] = 0;
                        v[i] += val;
                    }
                    resetBucket(a);
                    a = ((a+B)/B)*B;
                }
                if(b != n && b/B == (b+1)/B){
                    for (int i = b; i/B == b/B && i >= 1; --i){
                        ok[b/B][v[i]] = 0;
                        v[i] += val;
                    }
                    resetBucket(b);
                    b = (b/B)*B;
                }else b = ((b+B)/B)*B;
                while(a != b){
                    add[a/B] += val;
                    a += B;
                }
            }
        }else{
            int val, ans = -1;
            fin >> val;
            for (int b = 0; b*B <= n; ++b)
                if(val-add[b] >= 0 && ok[b][val-add[b]]){
                    for (int i = max(b*B, 1); i/B == b && i <= n; ++i)
                        if(v[i]+add[b] == val){
                            ans = e[i];
                            break;
                        }
                    break;
                }
            fout << ans << "\n";
        }
    }
    return 0;
}
