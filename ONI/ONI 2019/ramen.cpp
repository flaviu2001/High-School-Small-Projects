#define ff first
#define ss second
#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005, inf = -1+(1ll<<31);
int n, N, d, aint[nmax*4], ans[nmax], r[nmax];
vector<int> t, v[nmax];
pair<int, int> e[nmax];
set<int> ok;
unordered_map<int, int> rv;

void update(int pos, int val, int nod = 1, int st = 1, int dr = N)
{
    if(st == dr){
        aint[nod] = val;
        return;
    }
    int m = (st+dr)/2;
    if(m >= pos)
        update(pos, val, nod*2, st, m);
    else update(pos, val, nod*2+1, m+1, dr);
    aint[nod] = min(aint[nod*2], aint[nod*2+1]);
}

int query(int l, int r, int nod = 1, int st = 1, int dr = N)
{
    if(st >= l && dr <= r)
        return aint[nod];
    int ans = inf, m = (st+dr)/2;
    if(m >= l)
        ans = query(l, r, nod*2, st, m);
    if(m+1 <= r)
        ans = min(ans, query(l, r, nod*2+1, m+1, dr));
    return ans;
}

int main()
{
    ifstream fin ("ramen.in");
    ofstream fout ("ramen.out");
    fin >> n >> d;
    for (int i = 0; i < nmax; ++i)
        aint[i] = inf;
    for (int i = 1; i <= n; ++i){
        fin >> e[i].ff >> e[i].ss;
        ok.insert(e[i].ss);
        //N = max(N, e[i].ss);
    }
    int I = 0;
    for (auto x : ok){
        r[++I] = x;
        rv[x] = I;
    }
    N = I;
    for (int i = 1; i <= n; ++i){
        t.push_back(e[i].ff+d);
        if(v[rv[e[i].ss]].empty())
            update(rv[e[i].ss], e[i].ff-e[i].ss);
        v[rv[e[i].ss]].push_back(i);
    }
    for (int i = 1; i <= N; ++i)
        reverse(v[i].begin(), v[i].end());
    for (auto p : t){
        int st = 1, dr = N, m, an=0;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(query(1, m) <= p){
                an = m;
                dr = m-1;
            }else st = m+1;
        ans[v[an].back()] = p+r[an];
        v[an].pop_back();
        if(v[an].empty())
            update(an, inf);
        else update(an, e[v[an].back()].ff-e[v[an].back()].ss);
    }
    for (int i = 1; i <= n; ++i)
        fout << ans[i] << "\n";
    return 0;
}
