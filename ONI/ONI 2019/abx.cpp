#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
vector<ll> s, s2;

ll power(ll x)
{
    ll st = 0, dr = s.size()-1, mid, ans = 1;
    for (mid = (st+dr)/2; st <= dr; mid = (st+dr)/2)
        if(s[mid] <= x){
            ans = mid;
            st = mid+1;
        }else dr = mid-1;
    if(ans != s.size()-1 && s[ans+1]-x < x-s[ans])
        ++ans;
    ans = s[ans];
    ll sq = sqrt(x);
    if((sq+1)*(sq+1)-x < x-(sq*sq) && (sq+1)*(sq+1) <= m)
        ++sq;
    sq *= sq;
    if(abs(x-sq) < abs(x-ans))
        ans = sq;
    else if (abs(x-sq) == abs(x-ans))
        ans = min(ans, sq);
    return ans;
}

int main()
{
    ifstream fin ("abx.in");
    ofstream fout ("abx.out");
    fin >> n >> m;
    s2.push_back(1);
    for (ll i = 2; i <= 1000000; ++i){
        ll x = 1ll*i*i;
        while (m/x >= i){
            x *= i;
            s2.push_back(x);
        }
    }
    sort(s2.begin(), s2.end());
    for (auto x : s2)
        if(s.size() == 0 || x != s.back())
            s.push_back(x);
    for (ll i = 1; i <= n; ++i){
        ll x;
        fin >> x;
        fout << power(x) << "\n";
    }
    return 0;
}
