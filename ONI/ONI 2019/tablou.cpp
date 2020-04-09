#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "tablou";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

ll n, m, q, r[3005][3005], sum[100005];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= m; ++j){
            char qq;
            fin >> qq;
            r[i][j] = qq-'0';
            sum[0] += r[i][j];
            r[i][j] += r[i-1][j]+r[i][j-1]-r[i-1][j-1];
        }
    fin >> q;
    for (ll t = 1; t <= q; ++t){
        ll a, b, c, d, e;
        fin >> a >> b >> c >> d >> e;
        sum[t] = sum[0];
        ll now = r[c][d]-r[a-1][d]-r[c][b-1]+r[a-1][b-1];
        sum[t] += (c-a+1)*(d-b+1)*e-now;
    }
    ll all = 0;
    for (ll t = 1; t <= q; ++t)
        all += sum[t];
    for (ll t = 1; t <= q; ++t)
        fout << (sum[t]*q-all)*n*m << "\n";
    return 0;
}
