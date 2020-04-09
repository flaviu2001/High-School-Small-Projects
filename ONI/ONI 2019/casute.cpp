#include <bits/stdc++.h>

using namespace std;

const int nmax = 3005, M = 666013;
int n, m, c[nmax], c2[nmax], where[nmax];
short ans[nmax][nmax];
unordered_map<int, int> mp;
vector<int> v[nmax], vt[nmax];
bool ok[nmax], q[nmax];

void propagate(int nod, short mx, int source)
{
    ok[nod] = 1;
    ans[source][nod] = mx;
    for (auto x : vt[nod])
        if(!ok[x])
            propagate(x, mx, source);
}

int main()
{
    ifstream fin ("casute.in");
    ofstream fout ("casute.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fin >> c[i];
        c2[i] = c[i];
    }
    sort(c2+1, c2+n+1);
    for (int i = 1; i <= n; ++i)
        mp[c2[i]] = i;
    for (int i = 1; i <= n; ++i){
        c[i] = mp[c[i]];
        where[c[i]] = i;
    }
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        vt[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans[i][j] = n+1;
    for (int u = 1; u <= n; ++u){
        memset(ok, 0, sizeof(ok));
        memset(q, 0, sizeof(q));
        short mx = c[u];
        ok[u] = 1;
        propagate(u, mx, u);
        for (auto x : v[u])
            q[c[x]] = 1;
        while(mx < n){
            ++mx;
            if(q[mx]){
                int now = where[mx];
                propagate(now, mx, u);
                for (auto x : v[now])
                    q[c[x]] = 1;
            }
        }
    }
    int sol = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j){
            int x = (ans[i][j] == n+1 ? 0 : where[ans[i][j]]);
            sol = (sol*(n+1)+x)%M;
        }
    fout << sol << "\n";
    return 0;
}
