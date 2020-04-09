#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 30103;
ll a, b, c, k, ans, f[8005];
bool ok[25][25][25];
map<ll, ll> mp;

void gcd(ll &x, ll &y, ll a, ll b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        ll aux = x;
        x = y;
        y = aux-y*(a/b);
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

ll comb(ll n, ll m)
{
    if(mp.find(n*10000+m) != mp.end())
        return mp[n*10000+m];
    ll now = f[n];
    now = (now*invers(f[m]))%M;
    now = (now*invers(f[n-m]))%M;
    mp[n*10000+m] = now;
    return now;
}

void add(ll x)
{
    ans = (ans+x)%M;
}

void rem(ll x)
{
    ans = (ans-x)%M;
    if(ans < 0)
        ans = M+ans%M;
}

void bkt(ll x, ll y, ll z, ll t)
{
    if(ok[x][y][z])
        return;
    ok[x][y][z] = 1;
    if(x*y*z < k)
        return;
    ll ch = (comb(x*y*z, k)*comb(a, x)*comb(b, y)*comb(c, z))%M;
    if(t%2 == 0)
        add(ch);
    else rem(ch);
    bkt(x-1, y, z, t+1);
    bkt(x, y-1, z, t+1);
    bkt(x, y, z-1, t+1);
}

int main()
{
    ifstream fin ("borg.in");
    ofstream fout ("borg.out");
    fin >> a >> b >> c >> k;
    f[0] = 1;
    for (ll i = 1; i <= 8000; ++i)
        f[i] = (f[i-1]*i)%M;
    bkt(a, b, c, 0);
    fout << ans << "\n";
    return 0;
}
