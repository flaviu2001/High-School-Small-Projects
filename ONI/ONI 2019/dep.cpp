#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "dep";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 300, M = 666013;

int n, m, t, ordine[nmax], no, mapto[nmax], c[nmax], floyd[nmax][nmax], p, f[nmax][nmax], sz[nmax], pd[nmax];
vector<int> v[nmax], vt[nmax], g[nmax], arb[nmax];
bool vis[nmax], ok[nmax][nmax];

void dfs(int x)
{
    vis[x] = 1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!vis[v[x][i]])
            dfs(v[x][i]);
    ordine[++no] = x;
}

void dfst(int x)
{
    vis[x] = 0;
    mapto[x] = no;
    ++c[no];
    for (unsigned i = 0; i < vt[x].size(); ++i)
        if(vis[vt[x][i]])
            dfst(vt[x][i]);
}

void dfs2(int x)
{
    vis[x] = 1;
    for (unsigned i = 0; i < g[x].size(); ++i)
        if(!vis[g[x][i]])
            dfs2(g[x][i]);
    ordine[++p] = x;
}

void dfs3(int x)
{
    vis[x] = 1;
    sz[x] = c[x];
    f[x][0] = 1;
    for (auto y : arb[x]){
        dfs3(y);
        sz[x] += sz[y];
        int pd2[nmax] = {0};
        for (int i = 0; i <= t; ++i)
            if(f[x][i] != 0)
                for (int j = 0; j <= sz[y] && j+i <= t; ++j)
                    pd2[i+j] = (pd2[i+j] + f[x][i]*f[y][j])%M;
        for (int i = 0; i <= t; ++i)
            f[x][i] = pd2[i];
    }
    for (int i = t; i >= 0; --i)
        if(i < c[x])
            f[x][i] = 0;
        else f[x][i] = f[x][i-c[x]];
    f[x][0] = 1;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> t;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        vt[y].push_back(x);
        floyd[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    no = 0;
    for (int i = n; i; --i)
        if(vis[ordine[i]]){
            ++no;
            dfst(ordine[i]);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if(mapto[i] != mapto[j] && floyd[i][j] && !ok[mapto[i]][mapto[j]]){
                g[mapto[i]].push_back(mapto[j]);
                ok[mapto[i]][mapto[j]] = 1;
            }
    n = no;
    memset(floyd, 0, sizeof(floyd));
    for (int i = 1; i <= no; ++i)
        for (auto x : g[i])
            floyd[i][x] = 1;
    for (int aux = 1; aux <= n; ++aux)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if(i != j && floyd[i][aux] && floyd[aux][j] && !floyd[i][j])
                    floyd[i][j] = 1;
    for (int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs2(i);
    reverse(ordine+1, ordine+n+1);
    for (int i = 1; i < n; ++i){
        int nxt = -1;
        for (int j = i+1; j <= n; ++j)
            if(floyd[ordine[i]][ordine[j]]){
                nxt = ordine[j];
                break;
            }
        if(nxt != -1)
            arb[nxt].push_back(ordine[i]);
    }
    memset(vis, 0, sizeof(vis));
    pd[0] = 1;
    for (int i = n; i >= 1; --i)
        if(!vis[ordine[i]]){
            dfs3(ordine[i]);
            int pd2[nmax] = {0}, x = ordine[i];
            for (int i = 0; i <= t; ++i)
                if(pd[i] != 0)
                    for (int j = 0; j <= sz[x] && j+i <= t; ++j)
                        pd2[i+j] = (pd2[i+j] + pd[i]*f[x][j])%M;
            for (int i = 0; i <= t; ++i)
                pd[i] = pd2[i];
        }
    fout << pd[t] << "\n";
    return 0;
}
