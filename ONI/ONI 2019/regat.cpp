#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, test, tests[nmax], ft[nmax], tt[nmax], d[nmax], e[nmax*2], first[nmax], last[nmax], p, lazy[nmax*8], solsp[nmax], pos[nmax];
pi aint[nmax*8];
vector<int> sols[nmax];
vector<pi> v[nmax];
bool ok[nmax];

void dfs(int x)
{
    ok[x] = 1;
    e[++p] = x;
    pos[x] = p;
    first[x] = p;
    for (auto y : v[x])
        if(!ok[y.ff]){
            d[y.ff] = d[x]+y.ss;
            tt[y.ff] = y.ss;
            dfs(y.ff);
        }
    last[x] = p;
}

pi max(pi x, pi y)
{
    return x.ff > y.ff ? x : y;
}

void build(int nod, int st, int dr)
{
    if(st == dr)
        aint[nod] = {d[e[st]], st};
    else{
        int m = (st+dr)/2;
        build(nod*2, st, m);
        build(nod*2+1, m+1, dr);
        aint[nod] = max(aint[nod*2], aint[nod*2+1]);
    }
}

void propagate(int nod, int st, int dr)
{
    if(lazy[nod]){
        aint[nod].ff += lazy[nod];
        if(st != dr){
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
}

void update(int nod, int st, int dr, int l, int r, int val)
{
    if(l > r)
        return;
    propagate(nod, st, dr);
    if(dr < l || st > r)
        return;
    if(st >= l && dr <= r){
        aint[nod].ff += val;
        if(st != dr){
            lazy[nod*2] += val;
            lazy[nod*2+1] += val;
        }
        return;
    }
    int m = (st+dr)/2;
    update(nod*2, st, m, l, r, val);
    update(nod*2+1, m+1, dr, l, r, val);
    aint[nod] = max(aint[nod*2], aint[nod*2+1]);
}

pi query()
{
    propagate(1, 1, p);
    return aint[1];
}

void dfs2(int x)
{
    if(x != 1){
        int st = first[x], dr = last[x];
        update(1, 1, p, 1, p, tt[x]);
        update(1, 1, p, st, dr, -2*tt[x]);
    }
    vector<pi> bkp;
    for (int it = 1; it <= ft[x]; ++it){
        pi now = query();
        sols[x].push_back(now.ff);
        int y = e[now.ss];
        update(1, 1, p, pos[y], pos[y], -now.ff);
        bkp.push_back({pos[y], now.ff});
    }
    for (auto y : bkp)
        update(1, 1, p, y.ff, y.ff, y.ss);
    ok[x] = 0;
    for (auto y : v[x])
        if(ok[y.ff])
            dfs2(y.ff);
    if(x != 1){
        int st = first[x], dr = last[x];
        update(1, 1, p, 1, p, -tt[x]);
        update(1, 1, p, st, dr, 2*tt[x]);
    }
}

int main()
{
    ifstream fin ("regat.in");
    ofstream fout ("regat.out");
    fin >> n >> test;
    for (int i = 1; i < n; ++i){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    for (int i = 1; i <= test; ++i){
        fin >> tests[i];
        ++ft[tests[i]];
    }
    dfs(1);
    build(1, 1, p);
    dfs2(1);
    for (int i = 1; i <= test; ++i)
        fout << sols[tests[i]][solsp[tests[i]]++] << "\n";
    return 0;
}
