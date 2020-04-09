#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll nmax = 100005;
ll n, m, test;
ll v[nmax], pr[nmax];

int main()
{
    ifstream fin ("tnia.in");
    ofstream fout ("tnia.out");
    fin >> n >> m;
    for (ll i = 1; i <= n; ++i){
        fin >> v[i];
        pr[i] = pr[i-1]+v[i];
    }
    fin >> test;
    while(test--){
        ll x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        ll st = x1, dr = x2, mid, ans1 = -1, ans2 = -1;
        for (mid = (st+dr)/2; st <= dr; mid = (st+dr)/2)
            if(v[mid] >= y1){
                ans1 = mid;
                dr = mid-1;
            }else st = mid+1;
        st = x1, dr = x2;
        for (mid = (st+dr)/2; st <= dr; mid = (st+dr)/2)
            if(v[mid] > y2){
                ans2 = mid;
                dr = mid-1;
            }else st = mid+1;
        if(ans1 == -1){
            fout << "0\n";
            continue;
        }
        ll ans = 0;
        if(ans2 == -1)
            ans = pr[x2]-pr[ans1-1]-(x2-ans1+1)*(y1-1);
        else
            ans = pr[ans2-1]-pr[ans1-1]-(ans2-1-ans1+1)*(y1-1)+(x2-ans2+1)*(y2-y1+1);
        fout << ans << "\n";
    }
    return 0;
}

