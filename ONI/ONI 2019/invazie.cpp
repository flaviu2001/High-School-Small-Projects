#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll M = 666013;
ll test, n;
 
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
 
ll sign(ll x)
{
    if(x >= 0)
        return 1;
    return -1;
}
 
int main()
{
    ifstream fin ("invazie.in");
    ofstream fout ("invazie.out");
    fin >> test;
    while(test--){
        ll x, y;
        fin >> x >> y >> n;
        x %= M;
        y %= M;
        ll ans = lgpw((x+y)%M, n)+lgpw((x-y)%M, n);
        ans = (333007ll*(ans%M+M))%M;
        fout << ans << "\n";
    }
    return 0;
}
