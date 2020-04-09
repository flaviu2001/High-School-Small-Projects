#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b;

ll divisors(ll x)
{
    ll sq = sqrt(x), ans = 0;
    for (ll i = 1; i <= sq; ++i){
        ans += (x/i-x/(i+1))*i;
        if(i != x/i)
            ans += x/i;
    }
    return ans;
}

int main()
{
    ifstream fin ("ndiv.in");
    ofstream fout ("ndiv.out");
    fin >> a >> b;
    fout << divisors(b)-divisors(a-1) << "\n";
    return 0;
}

