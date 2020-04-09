#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 666013;
ll m, n, pd[1005][1005], pas[1005][1005], p2[1005];

ll lgpw(ll x, ll y)
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
    ifstream fin ("retea3.in");
    ofstream fout ("retea3.out");
    fin >> m >> n;
    p2[0] = 1;
    for (int i = 1; i <= 1000; ++i)
        p2[i] = (p2[i-1]*2)%M;
    pas[0][0] = 1;
    for (int i = 1; i <= 1000; ++i){
        pas[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            pas[i][j] = (pas[i-1][j]+pas[i-1][j-1])%M;
    }
    for (int i = 1; i <= n; ++i){
        pd[i][1] = i;
        pd[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            pd[i][j] = (pd[i-1][j]+pd[i][j-1])%M;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans = (ans+  (((((pd[i][j]-pd[i-1][j]+M)%M)*p2[i-1]))%M)*pas[n][j]  )%M;
    ans = (ans+1)%M;
    fout << lgpw(ans, m-1) << "\n";
    return 0;
}

