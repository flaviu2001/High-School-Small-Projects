#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 20173333;
ll test, n, k, f[100005], p[100005];

ll pw(ll x, ll y)
{
    ll p = 1;
    while(y)
        if(y%2 == 0){
            x = (x*x)%M;
            y /= 2;
        }else{
            p = (p*x)%M;
            --y;
        }
    return p;
}

int main()
{
    ifstream fin ("sirul2.in");
    ofstream fout ("sirul2.out");
    fin >> test >> n >> k;
    if(test == 1){
        f[0] = 1;
        for (ll i = 1; i <= 100000; ++i)
            f[i] = (f[i-1]*i)%M;
        ll ans = f[n-1];
        ans = (ans*pw(f[k-1], M-2))%M;
        ans = (ans*pw(f[n-k], M-2))%M;
        fout << ans << "\n";
    }else{
        f[0] = f[1] = p[0] = 1;
        p[1] = 2;
        for (ll i = 2; i <= n; ++i){
            f[i] = (p[i-1]-(i-k-1 >= 0 ? p[i-k-1] : 0)+M)%M;
            p[i] = (p[i-1]+f[i])%M;
        }
        fout << f[n] << "\n";
    }
    return 0;
}
