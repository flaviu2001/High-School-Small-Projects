#include <bits/stdc++.h>

using namespace std;

int n, pr[100005], aint[400005], p, q;

void build(int nod, int st, int dr)
{
    if(st == dr)
        aint[nod] = pr[st];
    else{
        int m = (st+dr)/2;
        build(nod*2, st, m);
        build(nod*2+1, m+1, dr);
        aint[nod] = min(aint[nod*2], aint[nod*2+1]);
    }
}

int query(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return aint[nod];
    int m = (st+dr)/2;
    int ans = 2000000000;
    if(m >= l)
        ans = query(nod*2, st, m, l, r);
    if(m+1 <= r)
        ans = min(ans, query(nod*2+1, m+1, dr, l, r));
    return ans;
}

int main()
{
    ifstream fin ("sum2.in");
    ofstream fout ("sum2.out");
    fin >> n >> p >> q;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        pr[i] = pr[i-1]+x;
    }
    build(1, 0, n);
    int ans = pr[p];
    for (int i = p; i <= n; ++i){
        int x = i-q, y = i-p;
        x = max(x, 0);
        int now = query(1, 0, n, x, y);
        ans = max(ans, pr[i]-now);
    }
    fout << ans << "\n";
    return 0;
}

