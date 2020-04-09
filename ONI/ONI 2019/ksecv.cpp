#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "ksecv";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, m, v[nmax], pd[2][nmax], s1[nmax], s2[nmax], vf;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= n; ++i)
        pd[1][i] = max(pd[1][i-1], v[i]);
    pd[0][0] = pd[1][0] = v[0] = inf;
    for (int k = 2; k <= m; ++k){
        int u = k%2, o = (k-1)%2;
        s1[1] = 0;
        s2[1] = inf;
        vf = 1;
        for (int i = k-1; i <= n; ++i){
            int mn = s2[vf];
            while(v[i] > v[s1[vf]]){
                --vf;
                mn = min(mn, s2[vf]);
            }
            s2[vf] = mn;
            pd[u][i] = pd[u][s1[vf]];
            if(mn != inf && mn+v[i] < pd[u][i])
                pd[u][i] = mn+v[i];
            ++vf;
            s1[vf] = i;
            s2[vf] = pd[o][i];
        }
    }
    fout << pd[m%2][n] << "\n";
    return 0;
}
