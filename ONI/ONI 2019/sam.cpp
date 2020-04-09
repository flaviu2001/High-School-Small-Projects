#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "sam";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005, M = 1000003;

int n, v[nmax];
pi aint[nmax*4][2];

void update(int nod, int st, int dr, int pos, pi val, int tip)
{
    if(st == dr)
        aint[nod][tip] = val;
    else{
        int m = (st+dr)/2;
        if(m >= pos)
            update(nod*2, st, m, pos, val, tip);
        else update(nod*2+1, m+1, dr, pos, val, tip);
        aint[nod][tip] = aint[nod*2][tip];
        if(aint[nod*2+1][tip].ff > aint[nod][tip].ff)
            aint[nod][tip] = aint[nod*2+1][tip];
        else if(aint[nod*2+1][tip].ff == aint[nod][tip].ff){
            aint[nod][tip].ss += aint[nod*2+1][tip].ss;
            if(aint[nod][tip].ss >= M)
                aint[nod][tip].ss -= M;
        }
    }
}

pi query(int nod, int st, int dr, int l, int r, int tip)
{
    if(st >= l && dr <= r)
        return aint[nod][tip];
    int m = (st+dr)/2;
    pi ans = {0, 0};
    if(m >= l)
        ans = query(nod*2, st, m, l, r, tip);
    if(m+1 <= r){
        pi now = query(nod*2+1, m+1, dr, l, r, tip);
        if(now.ff > ans.ff)
            ans = now;
        else if (now.ff == ans.ff){
            ans.ss += now.ss;
            if(ans.ss >= M)
                ans.ss -= M;
        }
    }
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= n; ++i){
        pi tip0, tip1;
        tip0 = query(1, 1, n, 1, v[i], 1);
        if(tip0.ss == 0)
            ++tip0.ss;
        ++tip0.ff;
        tip1 = query(1, 1, n, v[i], n, 0);
        if(tip1.ss == 0)
            ++tip1.ss;
        ++tip1.ff;
        update(1, 1, n, v[i], tip0, 0);
        update(1, 1, n, v[i], tip1, 1);
    }
    pi sol = query(1, 1, n, 1, n, 0);
    pi sol2 = query(1, 1, n, 1, n, 1);
    if(sol2.ff > sol.ff)
        sol = sol2;
    else if(sol2.ff == sol.ff){
        sol.ss += sol2.ss;
        if(sol.ss >= M)
            sol.ss -= M;
    }
    fout << sol.ss << "\n";
    return 0;
}
