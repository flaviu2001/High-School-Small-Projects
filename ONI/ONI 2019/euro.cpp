#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll nmax = 34567+5, inf = (1ll<<62);
ll n, m=1, t, v[nmax], c[nmax], pr[nmax], pd[nmax];

int main()
{
    ifstream fin ("euro.in");
    ofstream fout ("euro.out");
    fin >> n >> t;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        pr[i] = pr[i-1] + v[i];
        if(pr[i]-pr[c[m-1]] < 0 || i == n){
            c[m] = i;
            ++m;
        }
    }
    --m;
    for (int i = 1; i <= m; ++i){
        pd[i] = -inf;
        for (int j = i-1; j >= 0 && (i-j)*(i-j) <= t+1000; --j)
            pd[i] = max(pd[i], pd[j]+c[i]*(pr[c[i]]-pr[c[j]])-t);
    }
    fout << pd[m] << "\n";
    return 0;
}

