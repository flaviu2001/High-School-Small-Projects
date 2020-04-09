#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "pif";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 1234567, nmax = 1000006;

int n, k, pv, pt, f[2][nmax], pr[2][2][nmax];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> k >> pv >> pt;
    f[0][0] = f[1][0] = k;
    pr[0][0][0] = pr[0][1][0] = pr[1][0][0] = pr[1][1][0] = k;
    for (int i = 1; i <= n; ++i){
        int young, old;
        if(pv < pt){
            old = min((k+1)/2, i/pt);
            young = min((k-(k+1)/2), (i-old*pt)/pt);
            f[0][i] = ((i-pt >= 0 ? pr[0][1][i-pt] : 0) - (i-pt*old-pt >= 0 ? pr[0][1][i-pt*old-pt] : 0) + M)%M;
            f[0][i] = (f[0][i] + (i-pt*old-pt >= 0 ? pr[0][0][i-pt*old-pt] : 0) - (i-pt*(old+young)-pt >= 0 ? pr[0][0][i-pt*(old+young)-pt] : 0) + M)%M;
        }else{
            young = min((k+1)/2, i/pt);
            old = min((k-(k+1)/2), (i-young*pt)/pt);
            f[0][i] = ((i-pt >= 0 ? pr[0][0][i-pt] : 0) - (i-pt*young-pt >= 0 ? pr[0][0][i-pt*young-pt] : 0) + M)%M;
            f[0][i] = (f[0][i] + (i-pt*young-pt >= 0 ? pr[0][1][i-pt*young-pt] : 0) - (i-pt*(old+young)-pt >= 0 ? pr[0][1][i-pt*(old+young)-pt] : 0) + M)%M;
        }
        f[0][i] = (f[0][i] + k-old-young + M)%M;
        if(pv < pt){
            old = min((k+1)/2, i/pv);
            young = min((k-(k+1)/2), (i-old*pv)/pv);
            f[1][i] = ((i-pv >= 0 ? pr[1][1][i-pv] : 0) - (i-pv*old-pv >= 0 ? pr[1][1][i-pv*old-pv] : 0) + M)%M;
            f[1][i] = (f[1][i] + (i-pv*old-pv >= 0 ? pr[1][0][i-pv*old-pv] : 0) - (i-pv*(old+young)-pv >= 0 ? pr[1][0][i-pv*(old+young)-pv] : 0) + M)%M;
        }else{
            young = min((k+1)/2, i/pv);
            old = min((k-(k+1)/2), (i-young*pv)/pv);
            f[1][i] = ((i-pv >= 0 ? pr[1][0][i-pv] : 0) - (i-pv*young-pv >= 0 ? pr[1][0][i-pv*young-pv] : 0) + M)%M;
            f[1][i] = (f[1][i] + (i-pv*young-pv >= 0 ? pr[1][1][i-pv*young-pv] : 0) - (i-pv*(old+young)-pv >= 0 ? pr[1][1][i-pv*(old+young)-pv] : 0) + M)%M;
        }
        f[1][i] = (f[1][i] + k-old-young + M)%M;
        pr[0][0][i] = f[0][i];
        if(i-pt >= 0)
            pr[0][0][i] = (pr[0][0][i] + pr[0][0][i-pt])%M;
        pr[0][1][i] = f[1][i];
        if(i-pt >= 0)
            pr[0][1][i] = (pr[0][1][i] + pr[0][1][i-pt])%M;
        pr[1][0][i] = f[0][i];
        if(i-pv >= 0)
            pr[1][0][i] = (pr[1][0][i] + pr[1][0][i-pv])%M;
        pr[1][1][i] = f[1][i];
        if(i-pv >= 0)
            pr[1][1][i] = (pr[1][1][i] + pr[1][1][i-pv])%M;
    }
    fout << f[0][n] << "\n";
    return 0;
}
