#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll nmax = 400005;
ll n, test, k, nr = 0, sz[nmax], posl[nmax], posr[nmax], mxl[nmax], mxr[nmax], rmq[20][nmax], lg2[nmax], unmap[nmax];
map<ll, ll> mapp;
pair<ll, ll> pr[nmax], queries[nmax];
set<ll> v;
unordered_map<ll, ll> mapto;

ll query(ll x, ll y)
{
    if(x > y)
        return 0;
    if(x == y)
        return sz[x];
    ll lg = lg2[y-x];
    return max(rmq[lg][x], rmq[lg][y-(1<<lg)]);
}

int main()
{
    ifstream fin ("proiectoare.in");
    ofstream fout ("proiectoare.out");
    fin >> n >> test >> k;
    for (int i = 0; i < nmax; ++i)
        posl[i] = posr[i] = -1;
    for (ll i = 1; i <= n; ++i){
        ll x, y;
        fin >> x >> y;
        if(mapp.find(x) != mapp.end())
            mapp[x] = max(mapp[x], y);
        else mapp[x] = y;
    }
    for (map<ll, ll>::iterator it = mapp.begin(); it != mapp.end(); ++it){
        v.insert(it->first);
        v.insert(it->second);
        pr[++nr] = *it;
    }
    for (ll i = 1; i <= test; ++i){
        ll x, y;
        fin >> x >> y;
        queries[i] = {x, y};
        v.insert(x);
        v.insert(y);
    }
    n = nr;
    ll cnt = 0;
    for (set<ll>::iterator it = v.begin(); it != v.end(); ++it){
        mapto[*it] = ++cnt;
        unmap[cnt] = *it;
    }
    for (ll i = 1; i <= n; ++i){
        sz[mapto[pr[i].first]] = pr[i].second-pr[i].first;
        posl[mapto[pr[i].first]] = pr[i].second;
        if(posr[mapto[pr[i].second]] == -1)
            posr[mapto[pr[i].second]] = pr[i].first;
        else posr[mapto[pr[i].second]] = min(posr[mapto[pr[i].second]], pr[i].first);
    }
    for (ll i = 1; i <= cnt; ++i)
        if(posl[i] != -1)
            mxl[i] = max(mxl[i-1], posl[i]);
        else mxl[i] = mxl[i-1];
    mxr[cnt+1] = 20000000000000000;
    for (ll i = cnt; i >= 1; --i){
        if(posr[i] != -1)
            mxr[i] = min(mxr[i+1], posr[i]);
        else mxr[i] = mxr[i+1];
    }
    lg2[1] = 0;
    for (ll i = 2; i < nmax; ++i)
        lg2[i] = lg2[i/2]+1;
    for (ll i = 1; i <= cnt-1; ++i)
        rmq[0][i] = max(sz[i], sz[i+1]);
    ll pw = 1;
    while((1<<pw) < cnt){
        for (ll i = 1; i+(1<<pw) <= cnt; ++i)
            rmq[pw][i] = max(rmq[pw-1][i], rmq[pw-1][i+(1<<(pw-1))]);
        ++pw;
    }
    for (ll i = 1; i <= test; ++i){
        ll x = queries[i].first, y = queries[i].second, rb = y;
        ll ans = 0;
        if(mxr[mapto[y]+1] < y){
            ans = y-mxr[mapto[y]+1];
            rb = mxr[mapto[y]+1];
            if(ans >= y-x){
                fout << y-x << "\n";
                continue;
            }
        }
        ans = max(ans, query(mapto[x], mapto[rb]-1));
        if(mxl[mapto[x]-1] > x)
            ans = max(ans, min(mxl[mapto[x]-1]-x, y-x));
        fout << ans << "\n";
    }
    return 0;
}

