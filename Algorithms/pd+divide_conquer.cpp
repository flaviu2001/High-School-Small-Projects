//https://infoarena.ro/problema/cubeon

#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const string file = "cubeon";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1000005;

ll test, n, k, v[nmax], pr[nmax], pd[2][nmax];

ll cost(ll a, ll b)
{
    return (pr[b]-pr[a-1])*(pr[b]-pr[a-1])*(pr[b]-pr[a-1]);
}

void compute(ll l, ll r, ll optl, ll optr, int now)
{
    ll m = (l+r)/2;
    pll best = {INF, -1};
    for (ll k = optl; k <= min(m, optr); ++k)
        best = min(best, {pd[1-now][k-1]+cost(k, m), k});
    pd[now][m] = best.ff;
    if(l < r){
        compute(l, m-1, optl, best.ss, now);
        compute(m+1, r, best.ss, optr, now);
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test;
    while(test--){
        fin >> n >> k;
        for (int i = 1; i <= n; ++i)
            fin >> v[i], pr[i] = pr[i-1]+v[i];
        for (int i = 1; i <= n; ++i)
            pd[1][i] = cost(1, i);
        for (int i = 2; i <= k; ++i)
            compute(i, n, i, n, i%2);
        fout << pd[k%2][n] << "\n";
    }
    return 0;
}
