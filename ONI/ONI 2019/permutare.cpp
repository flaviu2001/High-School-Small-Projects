#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, v[200005], ans;

int main()
{
    ifstream fin ("permutare2.in");
    ofstream fout ("permutare2.out");
    fin >> n >> m;
    for (ll i = 1; i <= n; ++i){
        ll x;
        fin >> x;
    }
    swap(n, m);
    v[1] = 0;
    for (ll i = 2; i <= n; ++i){
        fin >> v[i];
        if(abs(v[i]-m) < v[i])
            v[i]-=m;
    }
    sort(v+1, v+n+1);
    ll st = 1, dr = n, zero, now = 0;
    for (ll i = 1; i <= n; ++i){
        now += abs(v[i]);
        if(v[i] == 0)
            zero = i;
    }
    ans = now;
    for (ll t = 1; t < m; ++t){
        now -= dr-zero;
        now += zero-st+1;
        while(v[st] == t-1-m/2){
            v[++dr] = v[st++]+m;
            if(n%2 == 1)
                --now;
            else now -= 2;
        }
        ans = min(ans, now);
        while(zero+1 <= dr && v[zero+1] == t)
            ++zero;
    }
    fout << ans;
    return 0;
}
