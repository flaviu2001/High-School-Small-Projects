#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll M = 1000000007;
vector< pair<ll, ll> > divs;
ll n, test, pascal[1005][1005], pw[20][1005];

int main()
{
    ifstream fin ("nkl.in");
    ofstream fout ("nkl.out");
    pascal[0][0] = 1;
    for (ll i = 1; i <= 1004; ++i){
        pascal[i][0] = 1;
        for (ll j = 1; j <= i; ++j)
            pascal[i][j] = (pascal[i-1][j]+pascal[i-1][j-1])%M;
    }
    fin >> n >> test;
    for (ll i = 2; i*i <= n; ++i)
        if(n%i == 0){
            ll cnt = 0;
            while(n%i == 0){
                ++cnt;
                n /= i;
            }
            divs.push_back({i, cnt});
        }
    if(n != 1)
        divs.push_back({n, 1});
    int now = 0;
    for (vector< pair<ll, ll> >::iterator it = divs.begin(); it != divs.end(); ++it){
        pw[now][0] = 1;
        for (int i = 1; i <= 1004; ++i)
            pw[now][i] = (1ll*pw[now][i-1]*it->second)%M;
        ++now;
    }
    while(test--){
        ll k, l;
        fin >> k >> l;
        ll ans = 1;
        for (int t = 0; t < now; ++t){
            ll sol = 0;
            for (ll i = l-1; i >= 0; --i)
                sol = (sol+1ll*pascal[k][i]*pw[t][i])%M;
            ans = (1ll*ans*sol)%M;
        }
        fout << ans << "\n";
    }
    return 0;
}

