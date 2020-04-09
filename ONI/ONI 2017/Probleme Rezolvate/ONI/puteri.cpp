#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll test;
vector<ll> v;
bool ok[1000006];

ll cnt(ll n)
{
    if(n == 0)
        return 0;
    ll lo = 0, hi = v.size()-1, m, ans = -1;
        for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
            if(v[m] <= n){
                lo = m+1;
                ans = m;
            }else hi = m-1;
    return sqrt(n)+int(pow(n, 1.0/3)+0.000000000001)-int(pow(n, 1.0/6)+0.000000000001)+ans+1;
}

int main()
{
    ifstream fin ("puteri4.in");
    ofstream fout ("puteri4.out");
    for (ll i = 2; i <= 1000; ++i)
        ok[i*i] = 1;
    for (ll i = 2; i*i*i <= 1000000; ++i)
        ok[i*i*i] = 1;
    for (ll i = 2; i <= 3981; ++i)
        if(!ok[i]){
            ll d = i*i*i*i, cnt = 4;
            do{
                d *= i;
                ++cnt;
                if(cnt%2 != 0 && cnt%3 != 0){
                    if(d <= 1000000)
                        ok[d] = 1;
                    v.push_back(d);
                }
            }while(d <= 1000000000000000000/i);
        }
    sort(v.begin(), v.end());
    fin >> test;
    while(test--){
        ll st, dr;
        fin >> st >> dr;
        fout << cnt(dr)-cnt(st-1) << "\n";
    }
    return 0;
}

