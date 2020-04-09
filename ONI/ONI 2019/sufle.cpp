#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "sufle";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, test, v[nmax], vbits[20][nmax], f[20];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        for (int j = 0; j < 20; ++j)
            vbits[j][i] = vbits[j][i-1] + ((v[i]&(1<<j)) == 0 ? 0 : 1);
    }
    while(test--){
        int a, b;
        fin >> a >> b;
        for (int i = 0; i < 20; ++i)
            f[i] = vbits[i][b]-vbits[i][a-1];
        ll ans = 0;
        pair<int, int> p[22];
        for (int i = 0; i < 22; ++i)
            p[i] = {0, 0};
        p[1].ff = b-a+1;
        for (int b = 19; b >= 0; --b){
            int sum = 0;
            for (int i = 1; i <= 20; ++i){
                sum += p[i].ff;
                if(sum >= f[b]){
                    for (int j = 21; j > i; --j)
                        p[j] = p[j-1];
                    for (int j = 1; j < i; ++j)
                        p[j].ss += (1<<b);
                    int ch = f[b]-(sum-p[i].ff);
                    p[i].ff -= ch;
                    p[i+1].ff = ch;
                    p[i+1].ss += (1<<b);
                    break;
                }
            }
        }
        for (int i = 1; i <= 20; ++i)
            ans += 1ll*p[i].ff*p[i].ss*p[i].ss;
        fout << ans << "\n";
    }
    return 0;
}
