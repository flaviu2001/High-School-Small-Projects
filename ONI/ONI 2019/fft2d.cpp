#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const string file = "fft2d";
const int nmax = 100005;

int n, m;
ll ans;
pi e[nmax];
map< pair<pi, pi>, int> mp;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    ans = (1ll<<(n-1))*(1ll<<(n-1));
    for (int i = 1; i <= m; ++i)
        fin >> e[i].ff >> e[i].ss;
    sort(e+1, e+m+1);
    for (int i = 1; i <= m; ++i){
        int niv = e[i].ff, val = e[i].ss, pw = 1<<(n-2), now = 0, niv2 = 0;
        int has = (1<<niv);
        while(pw && niv2 < niv){
            has -= mp[{{now, niv2}, {((1<<(n-1-niv))-1)&val, n-1-niv}}];
            now += pw&val;
            pw /= 2;
            ++niv2;
        }
        for (int j = n-2-niv; j >= 0; --j)
            mp[{{now, niv}, {((1<<j)-1)&val, j}}] += has;
        ans -= 1ll*has*(1<<(n-1-niv));
    }
    fout << ans << "\n";
    return 0;
}
