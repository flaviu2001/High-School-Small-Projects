#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "dreptunghiuri";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647;

ll n, m, d[405][405], sol, root[405*405];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    for (ll i = 0; i < 405; ++i)
        for (ll j = 0; j < 405; ++j)
            d[i][j] = -1;
    for (ll i = 1; i <= 400; ++i)
        root[i*i] = i;
    fin >> n >> m;--n,--m;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= m; ++j){
            if(d[i][j] == -1){
                d[i][j] = 0;
                ll h = i, w = j;
                if(h > w)
                    swap(h, w);
                for (ll a = 1; a < h; ++a){
                    ll delta = w*w-4*(h-a)*a;
                    if(delta < 0 || (root[delta] == 0 && delta != 0))
                        continue;
                    if(delta == 0 && w%2 == 0)
                        ++d[i][j];
                    else if (delta > 0){
                        ll x1 = w-root[delta];
                        if(x1%2 == 0 && x1 > 0)
                            ++d[i][j];
                        ll x2 = w+root[delta];
                        if(x2%2 == 0 && x2/2 < w)
                            ++d[i][j];
                    }
                }
                d[j][i] = d[i][j];
            }
            sol += (d[i][j]+1)*(n-i+1)*(m-j+1);
        }
    fout << sol << "\n";
    return 0;
}
