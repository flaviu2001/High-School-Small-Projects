#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
ll test, a, M;
char b[100005];
 
ll upten(ll x)
{
    ll now = x;
    x = (x*x)%M;
    x = (x*x)%M;
    x = (x*x)%M;
    x = (x*now)%M;
    x = (x*now)%M;
    return x;
}
 
ll pw(ll x, ll y)
{
    ll p = 1;
    while(y)
        if(y%2){
            p = (p*x)%M;
            --y;
        }else{
            x = (x*x)%M;
            y /= 2;
        }
    return p;
}
 
int main()
{
    ifstream fin ("guinness.in");
    ofstream fout ("guinness.out");
    fin >> test;
    while(test--){
        fin >> a >> b >> M;
        ll digits = strlen(b);
        ll ans = 1;
        for (int t = 0; t < digits; ++t){
            ll dig = b[t]-'0';
            ans = (upten(ans)*pw(a, dig))%M;
        }
        fout << ans << "\n";
    }
    return 0;
}
