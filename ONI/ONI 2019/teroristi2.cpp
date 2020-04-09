#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, M, pw2[105], mapto[105], mask[105], pd[1<<21], fact[105], pascal[105][105];
pair<ll, ll> e[105];
set<ll> s;

int main()
{
    ifstream fin ("teroristi2.in");
    ofstream fout ("teroristi2.out");
    fin >> n >> m >> M;
    pw2[0] = 1;
    for (ll i = 1; i < 21; ++i)
        pw2[i] = pw2[i-1]*2;
    fact[0] = 1;
    for (ll i = 1; i < 105; ++i)
        fact[i] = (fact[i-1]*i)%M;
    pascal[0][0] = 1;
    for (ll i = 1; i < 105; ++i){
        pascal[i][0] = 1;
        for (ll j = 1; j <= i; ++j)
            pascal[i][j] = (pascal[i-1][j]+pascal[i-1][j-1])%M;
    }
    for (ll i = 1; i <= m; ++i){
        fin >> e[i].first >> e[i].second;
        s.insert(e[i].first);
        s.insert(e[i].second);
    }
    ll p = -1;
    for (auto x : s)
        mapto[x] = ++p;
    for (ll i = 1; i <= m; ++i){
        e[i].first = mapto[e[i].first];
        e[i].second = mapto[e[i].second];
        mask[e[i].second] |= pw2[e[i].first];
    }
    ++p;
    pd[0] = 1;
    for (ll cfg = 0; cfg < (1<<p); ++cfg)
        for (ll i = 0; i < p; ++i)
            if((cfg&pw2[i]) == 0 && (cfg&mask[i]) == mask[i])
                pd[cfg|pw2[i]] = (pd[cfg|pw2[i]] + pd[cfg])%M;
    ll ans = (pd[(1<<p)-1] * fact[n-p])%M;
    ans = (ans*pascal[n][p])%M;
    fout << ans << "\n";
    return 0;
}

