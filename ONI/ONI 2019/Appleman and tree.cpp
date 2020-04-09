#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll nmax = 100005, M = 1000000007;
ll n, col[nmax], got[nmax], pd[2][nmax];
vector<ll> v[nmax];

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

void dfs(int x)
{
    if(col[x] == 1){
        ll prod = 1;
        for (vector<ll>::iterator it = v[x].begin(); it != v[x].end(); ++it){
            dfs(*it);
            prod = (prod*(pd[0][*it]+pd[1][*it]))%M;
        }
        pd[1][x] = prod;
    }else{
        ll prod = 1, sum = 0;
        for (vector<ll>::iterator it = v[x].begin(); it != v[x].end(); ++it){
            dfs(*it);
            prod = (prod*(pd[0][*it]+pd[1][*it]))%M;
        }
        for (vector<ll>::iterator it = v[x].begin(); it != v[x].end(); ++it){
            ll now = (prod*invers(pd[0][*it]+pd[1][*it]))%M;
            sum = (sum+now*pd[1][*it])%M;
        }
        pd[0][x] = prod;
        pd[1][x] = sum;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //ifstream cin ("data.in");
    cin >> n;
    for (ll i = 1; i < n; ++i){
        ll x;
        cin >> x;
        v[x].push_back(i);
        //v[i].push_back(x);
    }
    for (ll i = 0; i < n; ++i)
        cin >> col[i];
    dfs(0);
    cout << pd[1][0];
    return 0;
}

