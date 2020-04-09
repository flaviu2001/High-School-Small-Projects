#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "2sat";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100015, offset = 100005;

int n, m, ordine[nmax*2], p, p2, belong[nmax*2];
bool val[nmax], vis[nmax*2], ok[nmax*2];
vector<int> v[nmax*2], vt[nmax*2], has[nmax*2];

void dfs(int x)
{
    vis[x+offset] = 1;
    for (auto y : v[x+offset])
        if(!vis[y+offset])
            dfs(y);
    ordine[++p] = x;
}

void dfst(int x)
{
    vis[x+offset] = 0;
    belong[x+offset] = p2;
    has[p2].push_back(x);
    for (auto y : vt[x+offset])
        if(vis[y+offset])
            dfst(y);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[-x+offset].push_back(y);
        v[-y+offset].push_back(x);
        vt[y+offset].push_back(-x);
        vt[x+offset].push_back(-y);
    }
    for (int i = -n; i <= n; ++i)
        if(i != 0 && !vis[i+offset])
            dfs(i);
    vector<int> r;
    for (int i = p; i >= 1; --i)
        if(vis[ordine[i]+offset]){
            ++p2;
            r.push_back(ordine[i]);
            dfst(ordine[i]);
        }
    for (auto x : r)
        if(!ok[belong[x+offset]]){
            int now = belong[x+offset], now2 = belong[-x+offset];
            ok[now] = ok[now2] = 1;
            for (auto y : has[now])
                if(y > 0)
                    val[y] |= 0;
                else val[-y] |= 1;
            for (auto y : has[now2])
                if(y > 0)
                    val[y] |= 1;
                else val[-y] |= 0;
        }
    for (int i = 1; i <= n; ++i)
        if(belong[i+offset] == belong[-i+offset] && val[i]){
            fout << "-1\n";
            return 0;
        }
    for (int i = 1; i <= n; ++i)
        fout << val[i] << " ";
    return 0;
}
