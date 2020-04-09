#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 1000000007;
ll n, f[10], fct[100005], ans, prime[10];

void gcd(ll &x, ll &y, ll a, ll b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        ll aux = x;
        x = y;
        y = aux - y * (a/b);
    }
}

ll invers_modular(ll a)
{
    ll x, y;
    gcd(x, y, a, M);
    if(x < 0)
        x = M + x%M;
    return x;
}

void bkt(ll k, ll prod, ll sum, ll last)
{
    if(k > n)
        return;
    if(sum < 0)
        return;
    if(prod == 1){
        if(sum != n-k)
            return;
        f[1] = n-k;
        ll add = fct[n];
        for (int i = 1; i <= 9; ++i)
            add = (add*invers_modular(fct[f[i]]))%M;
        f[1] = 0;
        ans = (ans+add)%M;
        return;
    }
    for (int i = last; i >= 2; --i)
        if(prod%i == 0){
            ++f[i];
            bkt(k+1, prod/i, sum-i, i);
            --f[i];
            if(prime[i])
                break;
        }
}

int main()
{
    cin >> n;
    if(n == 1){
        cout << "10";
        return 0;
    }
    prime[2] = prime[3] = prime[5] = prime[7] = 1;
    fct[0] = 1;
    for (int i = 1; i < 100005; ++i)
        fct[i] = (fct[i-1]*i)%M;
    for (int t = 1; t <= 9*n; ++t)
        bkt(0, t, t, 9);
    cout << ans;
}

