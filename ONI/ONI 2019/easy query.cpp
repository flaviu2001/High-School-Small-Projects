#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, test, v[nmax], querymn, querymx;
int mn1[nmax*4], mx1[nmax*4], aintmn[nmax*4], aintmx[nmax*4], aintmnmx[nmax*4], aint2mn[nmax*4], aint2mx[nmax*4], aint2mnmx[nmax*4];

void build(int nod, int st, int dr)
{
    int mn = v[dr], mx = v[dr], mid = (st+dr)/2;
    aintmn[nod] = 0;
    aintmx[nod] = v[dr]*2;
    aintmnmx[nod] = v[dr];
    aint2mn[nod] = 0;
    aint2mx[nod] = v[dr]*2;
    aint2mnmx[nod] = v[dr];
    for (int i = dr; i >= st; --i){
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
        aintmn[nod] = max(aintmn[nod], v[i]-mn);
        aintmx[nod] = max(aintmx[nod], v[i]+mx);
        aintmnmx[nod] = max(aintmnmx[nod], v[i]-mn+mx);
        aint2mn[nod] = min(aint2mn[nod], v[i]-mx);
        aint2mx[nod] = min(aint2mx[nod], v[i]+mn);
        aint2mnmx[nod] = min(aint2mnmx[nod], v[i]-mx+mn);
    }
    mn1[nod] = mn;
    mx1[nod] = mx;
    if(st != dr){
        build(nod*2, st, mid);
        build(nod*2+1, mid+1, dr);
    }
}

int query2mx(int nod, int st, int dr, int a, int b)
{
    if(st >= a && dr <= b){
        int ans = aintmnmx[nod];
        ans = max(ans, aintmn[nod]+querymx);
        ans = max(ans, aintmx[nod]-querymn);
        ans = max(ans, mx1[nod]-querymn+querymx);
        querymx = max(querymx, mx1[nod]);
        querymn = min(querymn, mn1[nod]);
        return ans;
    }
    int mid = (st+dr)/2, ans = -inf;
    if(mid+1 <= b)
        ans = query2mx(nod*2+1, mid+1, dr, a, b);
    if(mid >= a)
        ans = max(ans, query2mx(nod*2, st, mid, a, b));
    return ans;
}

int query2mn(int nod, int st, int dr, int a, int b)
{
    if(st >= a && dr <= b){
        int ans = aint2mnmx[nod];
        ans = min(ans, aint2mn[nod]+querymn);
        ans = min(ans, aint2mx[nod]-querymx);
        ans = min(ans, mn1[nod]-querymx+querymn);
        querymx = max(querymx, mx1[nod]);
        querymn = min(querymn, mn1[nod]);
        return ans;
    }
    int mid = (st+dr)/2, ans = inf;
    if(mid+1 <= b)
        ans = query2mn(nod*2+1, mid+1, dr, a, b);
    if(mid >= a)
        ans = min(ans, query2mn(nod*2, st, mid, a, b));
    return ans;
}

int main()
{
    ifstream fin ("eq.in");
    ofstream fout ("eq.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    build(1, 1, n);
    while(test--){
        int a, b;
        fin >> a >> b;
        querymn = v[b], querymx = v[b];
        int ans = query2mx(1, 1, n, a, b);
        querymn = v[b], querymx = v[b];
        ans += query2mn(1, 1, n, a, b);
        fout << ans << "\n";
    }
    return 0;
}
