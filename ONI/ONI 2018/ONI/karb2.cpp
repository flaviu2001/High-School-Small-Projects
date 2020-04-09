#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll nmax = 100005, M = 666013;
ll n, t, pd[2][nmax];
bool iscartel[nmax];
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

void df(ll x, ll pred = 0)
{
    if(iscartel[x]){
        pd[1][x] = 0;
        ll prod = 1;
        bool one = false;
        for (vector<ll>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(*it != pred){
                df(*it, x);
                prod = (prod*(pd[0][*it]+pd[1][*it]))%M;
                one = true;
            }
        pd[0][x] = prod;
    }else{
        ll prod = 1;
        bool one = false;
        for (vector<ll>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(*it != pred){
                df(*it, x);
                prod = (prod*(pd[0][*it]+pd[1][*it]))%M;
                one = true;
            }
        if (!one){
            pd[0][x] = 0;
            pd[1][x] = 1;
            return;
        }
        pd[1][x] = prod;
        for (vector<ll>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(*it != pred){
                pd[0][x] += pd[0][*it]*prod*invers(pd[0][*it]+pd[1][*it]);
                pd[0][x] %= M;
            }
    }
}

int main()
{
    ifstream fin ("karb2.in");
    ofstream fout ("karb2.out");
    fin >> n >> t;
    for (ll i = 1; i <= t; ++i){
        ll x;
        fin >> x;
        iscartel[x] = 1;
    }
    for (ll i = 1; i < n; ++i){
        ll x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    df(1);
    fout << pd[0][1] << "\n";
    return 0;
}

