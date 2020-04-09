#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "gaz";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

ll l, p, d, c, n, v[2005], pd[2005], pr[2005];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> l >> p >> d >> c >> n;
    for (ll i = 1; i <= n; ++i){
        fin >> v[i];
        pr[i] = pr[i-1]+v[i];
    }
    pd[1] = p;
    for (ll i = 2; i <= n; ++i){
        pd[i] = pd[i-1]+p;
        ll sum = 0;
        for (ll j = i-2; j >= 0; --j){
            ll now = pr[i]-pr[j+1]-l;
            if(now > 0)
                sum += now*c;
            pd[i] = min(pd[i], pd[j]+sum+p);
        }
    }
    fout << pd[n]+pr[n]*d << "\n";
    return 0;
}
