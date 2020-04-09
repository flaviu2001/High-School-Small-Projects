//https://codeforces.com/contest/1107/problem/G

#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 300005;

ll n, a, d[nmax], c[nmax], pd[20][nmax], lg2[nmax], pr[nmax], aintmx[nmax*4], aintmn[nmax*4];

ll query(ll x, ll y)
{
    ll sz = lg2[y-x];
    if(x == y)
        return 0;
    ll ans = max(pd[sz][x], pd[sz][y-(1<<sz)]);
    if(y-(1<<sz)-1 >= x)
        ans = max(ans, d[y-(1<<sz)]-d[y-(1<<sz)-1]);
    return ans;
}

void buildmx(ll nod, ll st, ll dr)
{
    if(st == dr)
        aintmx[nod] = pr[st];
    else{
        ll m = (st+dr)/2;
        buildmx(nod*2, st, m);
        buildmx(nod*2+1, m+1, dr);
        aintmx[nod] = max(aintmx[nod*2], aintmx[nod*2+1]);
    }
}

void buildmn(ll nod, ll st, ll dr)
{
    if(st == dr)
        aintmn[nod] = pr[st];
    else{
        ll m = (st+dr)/2;
        buildmn(nod*2, st, m);
        buildmn(nod*2+1, m+1, dr);
        aintmn[nod] = min(aintmn[nod*2], aintmn[nod*2+1]);
    }
}

ll qrmn(ll nod, ll st, ll dr, ll l, ll r)
{
    if(l == 0){
        if(r == 0)
            return 0;
        return min(0ll, qrmn(nod, st, dr, 1, r));
    }
    if(st >= l && dr <= r)
        return aintmn[nod];
    ll m = (st+dr)/2;
    ll ans = INF;
    if(m >= l)
        ans = qrmn(nod*2, st, m, l, r);
    if(m < r)
        ans = min(ans, qrmn(nod*2+1, m+1, dr, l, r));
    return ans;
}

ll qrmx(ll nod, ll st, ll dr, ll l, ll r)
{
    if(st >= l && dr <= r)
        return aintmx[nod];
    ll m = (st+dr)/2;
    ll ans = -INF;
    if(m >= l)
        ans = qrmx(nod*2, st, m, l, r);
    if(m < r)
        ans = max(ans, qrmx(nod*2+1, m+1, dr, l, r));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    lg2[2] = 1;
    for (ll i = 3; i < nmax; ++i)
        lg2[i] = lg2[i/2]+1;
    cin >> n >> a;
    ll solution = 0;
    for (ll i = 1; i <= n; ++i){
        cin >> d[i] >> c[i];
        solution = max(solution, a-c[i]);
        pr[i] = pr[i-1]-c[i]+a;
    }
    buildmx(1, 1, n);
    buildmn(1, 1, n);
    for (ll i = 1; i < n; ++i)
        pd[0][i] = d[i+1]-d[i];
    for (ll t = 1; (1<<t) <= n; ++t)
        for (ll i = 1; i <= n-(1<<t); ++i)
            pd[t][i] = max(pd[t-1][i], max(pd[t-1][i+(1<<(t-1))], d[i+(1<<(t-1))]-d[i+(1<<(t-1))-1]));
    for (ll i = 2; i <= n; ++i){
        ll lf = d[i]-d[i-1];
        ll lo = i-1, hi = i;
        ll st = 1, dr = i-1, m;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(query(m, i) <= lf){
                lo = m;
                dr = m-1;
            }else st = m+1;
        st = i, dr = n;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(query(i-1, m) <= lf){
                hi = m;
                st = m+1;
            }else dr = m-1;
        solution = max(solution, qrmx(1, 1, n, i, hi)-qrmn(1, 1, n, lo-1, i-2)-lf*lf);
    }
    cout << solution;
    return 0;
}
