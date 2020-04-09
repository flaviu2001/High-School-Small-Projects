#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const ll M = 1000000009;
ll n;
 
ll pw(ll x, ll y)
{
    ll p = 1;
    x %= M;
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
    ifstream fin ("algebra2.in");
    ofstream fout ("algebra2.out");
    fin >> n;
    if(n%2 == 1)
        fout << pw(pw(n, n), (n+1)/2) << "\n";
    else fout << pw(pw(n, n+1), n/2) << "\n";
    return 0;
}
