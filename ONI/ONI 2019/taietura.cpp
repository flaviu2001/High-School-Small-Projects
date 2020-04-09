#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int nmax = 100005;

ll n, v[nmax], pr[nmax], lft[nmax], rgt[nmax];
unordered_map<ll, ll> f;

int main()
{
    ifstream fin ("taietura.in");
    ofstream fout ("taietura.out");
    fin >> n;
    ++f[0];
    for (ll i = 1; i <= n; ++i){
        fin >> v[i];
        pr[i] = pr[i-1]+v[i];
        lft[i] = f[pr[i]]++;
    }
    f.clear();
    for (ll i = n; i >= 1; --i)
        rgt[i] = f[pr[i]]++;
    ll ans = f[0];
    for (ll i = 1; i <= n; ++i){
        ans -= lft[i-1];
        ans += rgt[i-1];
        fout << ans << " ";
    }
    return 0;
}
