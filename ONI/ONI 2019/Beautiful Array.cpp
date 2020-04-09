#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 300005;

ll n, k, v[nmax], pr[nmax], ezsol[nmax], vx[nmax], ans, aintx[nmax*4], lazy[nmax*4];

void build(ll nod, ll st, ll dr)
{
    if(st == dr)
        aintx[nod] = vx[st];
    else{
        ll mid = (st+dr)/2;
        build(nod*2, st, mid);
        build(nod*2+1, mid+1, dr);
        aintx[nod] = max(aintx[nod*2], aintx[nod*2+1]);
    }
}

void propagate(ll nod, ll st, ll dr)
{
    if(lazy[nod]){
        aintx[nod] += lazy[nod];
        if(st != dr){
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
}

void update(ll nod, ll st, ll dr, ll l, ll r, ll val)
{
    if(l > r)
        return;
    propagate(nod, st, dr);
    if(st > r || dr < l)
        return;
    if(st >= l && dr <= r){
        aintx[nod] += val;
        if(st != dr){
            lazy[nod*2] += val;
            lazy[nod*2+1] += val;
        }
        return;
    }
    ll mid = (st+dr)/2;
    update(nod*2, st, mid, l, r, val);
    update(nod*2+1, mid+1, dr, l, r, val);
    aintx[nod] = max(aintx[nod*2], aintx[nod*2+1]);
}

ll query(ll nod, ll st, ll dr, ll l, ll r)
{
    propagate(nod, st, dr);
    if(st >= l && dr <= r)
        return aintx[nod];
    ll ans = 0, mid = (st+dr)/2;
    if(mid >= l)
        ans = max(ans, query(nod*2, st, mid, l, r));
    if(mid+1 <= r)
        ans = max(ans, query(nod*2+1, mid+1, dr, l, r));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
        pr[i] = pr[i-1]+v[i];
    }
    ans = 0;
    ll mn = 0;
    for (int i = 1; i <= n; ++i){
        mn = min(mn, pr[i]);
        ezsol[i] = pr[i]-mn;
        ans = max(ans, pr[i]-mn);
    }
    for (int i = 1; i <= n; ++i){
        vx[i] = vx[i-1]+v[i]*k;
        ll now = ezsol[i-1]+v[i]*k;
        vx[i] = max(vx[i], now);
    }
    build(1, 1, n);
    for (int i = 1; i <= n; ++i){
        update(1, 1, n, 1, i-1, v[i]);
        ans = max(ans, query(1, 1, n, 1, i));
    }
    cout << ans;
    return 0;
}