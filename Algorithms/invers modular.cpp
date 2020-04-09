#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, M;

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

ll invers(ll x)
{
    ll a, b;
    gcd(a, b, x, M);
    if(a < 0)
        a = M+a%M;
    return a;
}

int main()
{
    ifstream fin ("inversmodular.in");
    ofstream fout ("inversmodular.out");
    fin >> n >> M;
    fout << invers(n) << "\n";
    return 0;
}

