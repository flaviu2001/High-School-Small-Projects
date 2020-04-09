#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const ll M = 666013;
ll n, k, x, v[100005], factorial[100005], pascal[2][100005];
 
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
 
ll invers(ll a)
{
    ll x, y;
    gcd(x, y, a, M);
    if(x < 0)
        x = M + x%M;
    return x;
}
 
ll combinari(ll n, ll k)
{
    ll sol = factorial[n];
    ll invk = invers(factorial[k]);
    ll invn_k = invers(factorial[n-k]);
    return (sol * invk * invn_k) % M;
}
 
ll pw(ll x, ll y)
{
    ll p = 1;
    while(y)
        if(y%2==0){
            x *= x;
            x %= M;
            y /= 2;
        }else{
            p *= x;
            p %= M;
            --y;
        }
    return p;
}
 
int main()
{
    ifstream fin ("xnumere.in");
    ofstream fout ("xnumere.out");
    fin >> k >> x >> n;
    factorial[0] = 1;
    factorial[1] = 1;
    for (ll i = 2; i <= 100005; ++i)
        factorial[i] = (factorial[i-1]*i)%M;
    ll A = 1;
    for (ll i = k-x+1; i <= k; ++i)
        A = (A*(i%M))%M;
    ll S = 0;
    for (int j = 1; j <= x; ++j)
        if((x-j)%2 == 0)
            S = (S + combinari(x, j)*pw(j, n))%M;
        else{
            S = (S - combinari(x, j)*pw(j, n))%M;
            if(S < 0)
                S = M+S%M;
        }
    S = (S*invers(factorial[x]))%M;
    fout << (S*A)%M << "\n";
    return 0;
}
