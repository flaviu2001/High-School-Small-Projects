#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll M = 123457;
int pd[505][505], n, m, fact[2005];

void gcd(ll &x, ll &y, ll a, ll b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        ll aux = x;
        x = y;
        y = aux - (a/b)*y;
    }
}

ll invers(ll x)
{
    ll a, b;
    gcd(a, b, x, M);
    if(a < 0)
        a = M+a%M;
    return a;
}

ll catalan(ll x)
{
    ll ans = fact[x*2];
    ans = (ans*invers(fact[x]))%M;
    ans = (ans*invers(fact[x+1]))%M;
    return ans;
}

int main()
{
    ifstream fin ("mugur.in");
    ofstream fout ("mugur.out");
    fact[0] = 1;
    for (ll i = 1; i <= 2000; ++i)
        fact[i] = (fact[i-1]*i)%M;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        pd[i][1] = catalan(i-1);
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= i && j <= m; ++j){
            ll ans = 0;
            for (int k = 1; k <= i && i-k >= j-1; ++k)
                ans = ans + 1LL*pd[i-k][j-1]*pd[k][1];
            pd[i][j] = ans%M;
        }
    fout << pd[n][m] << "\n";
    return 0;
}

