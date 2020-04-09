#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "provocare";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647;

ll test, n, a, b, ans, pascal[105][105];

ll gcd(ll x, ll y)
{
    return (y == 0 ? x : gcd(y, x%y));
}

ll comb(ll n, ll k) {
    if (k > n - k)
        return comb(n, n - k);
    if (k == 0)
        return 1;
    if (n <= 100)
        return pascal[n][k];
    if (k <= 6) {
        ll kf = 1;
        for (ll i = 2; i <= k; ++i)
            kf *= i;
        ll ans = 1;
        for (ll i = n; i > n - k && ans <= inf; --i) {
            ll d = gcd(i, kf);
            kf /= d;
            ans *= (i / d);
        }
        return ans;
    }
    return inf;
}

ll nodes(ll H)
{
    ll ans = 0;
    for (ll beta = 0; beta*b <= H; ++beta){
        ll alfa = (H-beta*b)/a;
        ans += comb(beta+alfa+1, beta+1);
    }
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    pascal[0][0] = 1;
    for (ll i = 1; i <= 100; ++i){
        pascal[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            pascal[i][j] = min(1ll*inf, pascal[i-1][j]+pascal[i-1][j-1]);
    }
    fin >> test;
    while(test--){
        fin >> n >> a >> b;
        if(a > b)
            swap(a, b);
        ll st = 0, dr = b*(log2(n)+1), m, ans = 1;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(nodes(m) >= n){
                ans = m;
                dr = m-1;
            }else st = m+1;
        fout << ans << "\n";
    }
    return 0;
}
