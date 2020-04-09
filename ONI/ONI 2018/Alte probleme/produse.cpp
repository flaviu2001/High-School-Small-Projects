#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 1000000007;
ll n, pd[200005], d, sol, ones;
int pascal[200005][21];

unordered_map<ll, ll> mp;

int main()
{
    ifstream fin ("produse.in");
    ofstream fout ("produse.out");
    pascal[0][0] = 1;
    for (ll i = 1; i <= 200000; ++i){
        pascal[i][0] = 1;
        for (ll j = 1; j <= min(i, 20ll); ++j)
            pascal[i][j] = (pascal[i-1][j]+pascal[i-1][j-1])%M;
    }
    fin >> n >> d;
    for (ll i = 1; i <= n; ++i){
        ll x;
        fin >> x;
        if(x == 1)
            ++ones;
        else ++mp[x];
    }
    pd[1] = 1;
    for (auto i : mp){
        ll x = i.first, y = i.second;
        ll big = d-(d%x);
        for (ll j = big; j >= x; j -= x){
            ll e = 1;
            for (ll jj = x; jj <= d && e <= y; jj *= x, ++e)
                if(j%jj == 0)
                    pd[j] = (pd[j] + pd[j/jj]*pascal[y][e])%M;
                else break;
        }
    }
    ll sol = 0;
    for (ll i = 1; i <= d; ++i)
        sol = (sol+pd[i])%M;
    for (int i = 1; i <= ones; ++i)
        sol = (sol+sol)%M;
    sol = (-1+sol+M)%M;
    fout << sol << "\n";
}

