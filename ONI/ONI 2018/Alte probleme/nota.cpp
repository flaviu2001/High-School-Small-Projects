#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll M = 1000000007;
ll fact[200005], p, f[200005];

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

ll invers(ll a)
{
    ll x, y;
    gcd(x, y, a, M);
    if(x < 0)
        x = M+x%M;
    return x;
}

ll comb(ll n, ll k)
{
    ll sol = fact[n];
    sol = (sol*invers(fact[k]))%M;
    sol = (sol*invers(fact[n-k]))%M;
    return sol;
}

int main()
{
    //ifstream cin ("nota.in");
    //ofstream cout ("nota.out");
    fact[0] = 1;
    for (ll i = 1; i < 200005; ++i)
        fact[i] = (fact[i-1] * i)%M;
    ll sum = 0, r = 0, test, perm = 1;
    cin >> test >> p;
    while(test--){
        ll tst, x;
        cin >> tst >> x;
        if(tst == 0){
            sum += x;
            ++r;
            ll t = p-sum;
            perm = (perm*r)%M;
            ++f[x];
            perm = (perm*invers(f[x]))%M;
            if(t < 0)
                cout << "-1\n";
            else cout << (comb(t+r, r)*perm)%M << "\n";
        }else{
            sum -= x;
            --r;
            ll t = p-sum;
            perm = (perm*f[x])%M;
            --f[x];
            perm = (perm*invers(r+1))%M;
            if(t < 0)
                cout << "-1\n";
            else cout << (comb(t+r, r)*perm)%M << "\n";
        }
    }
    return 0;
}

