#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

//const int inf = 2147483647;
//const ll inf = 9223372036854775807ll;

const ll nmax = 100012;
ll M, test, f[nmax], inv[nmax];

void gcd(ll &x, ll &y, ll a, ll b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        ll aux = x;
        x = y;
        y = aux - y*(a/b);
    }
}

ll P(ll x)
{
    ll ans = 0;
    while(x){
        ans += x/M;
        x /= M;
    }
    return ans;
}

ll F(ll x)
{
    ll ans = 1;
    if((x/M)%2 == 1)
        ans = M-1;
    ans = (ans*f[x%M])%M;
    if(x/M > 0)
        ans = (ans*F(x/M))%M;
    return ans;
}

ll comb(ll n, ll k)
{
    ll _n = F(n), _k = F(k), _nk = F(n-k);
    return (_n*inv[_k]*inv[_nk])%M;
}

int main()
{
    ifstream fin ("jap2.in");
    ofstream fout ("jap2.out");
    fin >> M >> test;
    f[0] = 1;
    for (ll i = 1; i < M; ++i){
        f[i] = (f[i-1]*i)%M;
        ll a, b;
        gcd(a, b, i, M);
        inv[i] = a;
        if(a < 0)
            inv[i] = M+a%M;
    }
    while(test--){
        ll n, k;
        fin >> n >> k;
        k = min(k, n-k);
        if(P(n) != P(k)+P(n-k)){
            fout << "0\n";
            continue;
        }
        fout << comb(n, k) << "\n";
    }
    return 0;
}

