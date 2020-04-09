#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 250005;

int n, p, test, depmax, c[nmax], dep[nmax], e[nmax], f[nmax], l[nmax], aib[nmax], ans[nmax*2];
vector<int> v[nmax], g[nmax];
vector<pi> ev[nmax];

void update(int idx, int val)
{
    while(idx <= n){
        aib[idx] += val;
        idx += (idx & (-idx));
    }
}

int read(int idx)
{
    int sum = 0;
    while(idx){
        sum += aib[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

void dfs(int x)
{
    e[++p] = x;
    f[x] = p;
    g[dep[x]].push_back(x);
    for (auto y : v[x]){
        dep[y] = dep[x]+1;
        depmax = max(depmax, dep[y]);
        dfs(y);
    }
    l[x] = p;
}

int main()
{
    ifstream fin ("arb.in");
    ofstream fout ("arb.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> c[i];
    for (int i = 2; i <= n; ++i){
        int x;
        fin >> x;
        v[x].push_back(i);
    }
    dfs(1);
    fin >> test;
    for (int i = 1; i <= test; ++i){
        int x, d;
        fin >> x >> d;
        ev[min(dep[x]+d, depmax)].push_back({x, i});
    }
    for (int t = 0; t <= depmax; ++t){
        for (auto x : g[t])
            update(f[x], c[x]);
        for (auto x : ev[t])
            ans[x.ss] = read(l[x.ff])-read(f[x.ff]-1);
    }
    for (int i = 1; i <= test; ++i)
        fout << ans[i] << "\n";
    return 0;
}
