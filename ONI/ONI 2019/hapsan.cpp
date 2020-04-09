#define ff first
#define ss second
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int nmax = 200005, inf = -1+(1ll<<31);
int n, segs, c[nmax], lft[nmax], l2[nmax];
ll aint[nmax*4], sol, v[nmax];
pair<int, int> p[nmax];

void update(int pos, ll val, int nod = 1, int st = 1, int dr = nmax-1)
{
    if(st == dr)
        aint[nod] = val;
    else{
        int m = (st+dr)/2;
        if(m >= pos)
            update(pos, val, nod*2, st, m);
        else update(pos, val, nod*2+1, m+1, dr);
        aint[nod] = max(aint[nod*2], aint[nod*2+1]);
    }
}

ll query(int l, int r, int nod = 1, int st = 1, int dr = nmax-1)
{
    if(l > r)
        return 0;
    if(st >= l && dr <= r)
        return aint[nod];
    int m = (st+dr)/2;
    ll ans = 0;
    if(m >= l)
        ans = query(l, r, nod*2, st, m);
    if(m+1 <= r)
        ans = max(ans, query(l, r, nod*2+1, m+1, dr));
    return ans;
}

int main()
{
    ifstream fin ("hapsan.in");
    ofstream fout ("hapsan.out");
    for (int i = 0; i < nmax; ++i){
        lft[i] = i-1;
        l2[i] = inf;
    }
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> c[i];
        v[i] = c[i];
    }
    fin >> segs;
    for (int i = 1; i <= segs; ++i)
        fin >> p[i].ff >> p[i].ss;
    for (int i = 1; i <= segs; ++i)
        l2[p[i].ss] = min(l2[p[i].ss], p[i].ff);
    for (int i = n-1; i >= 1; --i)
        l2[i] = min(l2[i], l2[i+1]);
    for (int i = 1; i <= n; ++i)
        --l2[i];
    sol = c[1];
    int p = 2;
    for (int i = 1; i <= n; ++i){
        update(c[i], v[i]);
        while(l2[p] <= i){
            if(l2[p] == i)
                v[p] += query(1, c[p]-1);
            ++p;
        }
        sol = max(sol, v[i]);
    }
    fout << sol << "\n";
    return 0;
}
