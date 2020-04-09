#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct query{
    ll x, y, i;
    bool operator<(const query &obj)const{
        if(y != obj.y)
            return y < obj.y;
        return x < obj.x;
    }
};

const ll nmax = 100005;
ll n, test, k, p[nmax], sol[nmax], sq, cnt[2000005];
vector<query> v[1005];

query mkq(ll x, ll y, ll i)
{
    query aux;
    aux.x = x;
    aux.y = y;
    aux.i = i;
    return aux;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //ifstream cin ("data.in");
    cin >> n >> test >> k; sq = sqrt(n);
    for (ll i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        p[i] = p[i-1]^x;
    }
    for (ll i = 1; i <= test; ++i){
        ll x, y;
        cin >> x >> y;
        --x;
        v[x/sq].push_back(mkq(x, y, i));
    }
    for (ll i = 0; i < 1005; ++i)
        sort(v[i].begin(), v[i].end());
    for (ll t = 0; t < 1005; ++t)
        if(v[t].size() != 0){
            query first = *v[t].begin();
            ll ans = 0;
            for (ll i = first.x; i <= first.y; ++i){
                ans += cnt[p[i]^k];
                ++cnt[p[i]];
            }
            sol[first.i] += ans;
            ll lx = first.x, ly = first.y;
            for (vector<query>::iterator it = v[t].begin()+1; it != v[t].end(); ++it){
                ll x = it->x, y = it->y;
                for (ll i = lx; i < x; ++i){
                    --cnt[p[i]];
                    ans -= cnt[p[i]^k];
                }
                for (ll i = lx-1; i >= x; --i){
                    ans += cnt[p[i]^k];
                    ++cnt[p[i]];
                }
                for (ll i = ly+1; i <= y; ++i){
                    ans += cnt[p[i]^k];
                    ++cnt[p[i]];
                }
                sol[it->i] = ans;
                lx = x, ly = y;
            }
            for (int i = lx; i <= ly; ++i)
                --cnt[p[i]];
        }
    for (ll i = 1; i <= test; ++i)
        cout << sol[i] << "\n";
    return 0;
}

