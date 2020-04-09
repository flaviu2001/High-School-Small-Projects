#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "meow";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005, M = 1000000007;

int n, m, test, all, c[nmax], newc[nmax], up[5][nmax], suffix[nmax], suffix2[nmax], suffix3[nmax], prefix[nmax], prefix2[nmax], prefix3[nmax], keep[nmax];
vector<int> v[nmax], g[nmax];
stack<int> s[nmax];

void add(int &x, ll y)
{
    x = (x+(y%M))%M;
}

void sub(int &x, ll y)
{
    x = (x-(y%M)+M)%M;
}

void dfs(int x)
{
    up[0][x] = (s[c[x]-1].empty() ? -1 : s[c[x]-1].top());
    up[1][x] = (s[c[x]].empty() ? -1 : s[c[x]].top());
    up[4][x] = (s[c[x]+1].empty() ? -1 : s[c[x]+1].top());
    s[c[x]].push(x);
    prefix[x] = prefix3[c[x]-1];
    add(prefix3[newc[x]], prefix3[newc[x]-1]);
    for (auto y : v[x])
        dfs(y);
    s[c[x]].pop();
    sub(prefix3[newc[x]], prefix3[newc[x]-1]);
}

void dfs2(int x)
{
    up[2][x] = (s[c[x]-1].empty() ? -1 : s[c[x]-1].top());
    up[3][x] = (s[newc[x]].empty() ? -1 : s[newc[x]].top());
    s[newc[x]].push(x);
    prefix2[x] = prefix3[newc[x]-1];
    add(prefix3[newc[x]], prefix3[newc[x]-1]);
    for (auto y : v[x])
        dfs2(y);
    s[newc[x]].pop();
    sub(prefix3[newc[x]], prefix3[newc[x]-1]);
}

void dinamica()
{
    for (int i = 0; i <= max(n, m); ++i){
        suffix[i] = suffix2[i] = suffix3[i] = 0;
        prefix[i] = prefix2[i] = prefix3[i] = 0;
        up[0][i] = up[1][i] = up[2][i] = up[3][i] = up[4][i] = 0;
        g[i].clear();
    }
    prefix3[0] = 1;
    dfs(0);
    dfs2(0);
    for (int i = n-1; i >= 0; --i)
        g[c[i]].push_back(i);
    for (auto x : g[m])
        suffix3[x] = 1;
    for (int i = 0; i < n; ++i)
        if(newc[i] == m)
            suffix2[i] = 1;
    for (int i = m; i >= 1; --i){
        if(i != m)
            for (auto x : g[i])
                if(up[1][x] != -1 && up[4][x] < up[1][x])
                    add(suffix3[up[1][x]], suffix3[x]);
        for (auto x : g[i])
            if(up[2][x] != -1)
                add(suffix2[up[2][x]], suffix3[x]);
        for (auto x : g[i])
            suffix[x] = suffix3[x];
        for (auto x : g[i])
            if(up[1][x] != -1)
                add(suffix3[up[1][x]], suffix3[x]);
        for (auto x : g[i])
            if(up[0][x] > up[1][x])
                add(suffix3[up[0][x]], suffix3[x]);
    }
    for (int i = n-1; i >= 0; --i)
        if(up[3][i] != -1 && newc[i] != m)
            add(suffix2[up[3][i]], suffix2[i]);
    all = 0;
    for (auto x : g[1])
        if(up[1][x] == -1)
            add(all, suffix3[x]);
}

void process()
{
    for (int t = 0; t < n; ++t){
        sub(all, 1ll*prefix[t]*suffix[t]);
        add(all, 1ll*prefix2[t]*suffix2[t]);
        keep[t] = all;
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> test;
    for (int i = 1; i < n; ++i){
        int x;
        fin >> x;
        v[x].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        fin >> c[i];
    int sol = 0, rem = test, t = 1;
    while(rem){
        if(rem >= n){
            for (int i = 0; i < n; ++i)
                fin >> newc[i];
            dinamica();
            process();
            for (int i = 0; i < n; ++i)
                add(sol, 1ll*(t+i)*keep[i]);
            for (int i = 0; i < n; ++i)
                c[i] = newc[i];
            t += n;
            rem -= n;
        }else{
            for (int i = 0; i < n; ++i)
                newc[i] = c[i];
            for (int i = 0; i < n && t+i <= test; ++i)
                fin >> newc[i];
            dinamica();
            process();
            for (int i = 0; i < n && t <= test; ++i, ++t)
                add(sol, 1ll*t*keep[i]);
            rem = 0;
        }
    }
    fout << sol << "\n";
    return 0;
}
