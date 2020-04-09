#include <bits/stdc++.h>

using namespace std;

const int M = 666013, nmax = 755;

int n, v[nmax], pd[nmax][nmax*10], S;

int main()
{
    ifstream fin ("bilute2.in");
    ofstream fout ("bilute2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        S += v[i];
    }
    pd[0][0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i){
        sum += v[i];
        for (int k = min(i, n/2+1); k >= 1; --k)
            for (int s = min(sum, S/2+1); s >= v[i]; --s){
                pd[k][s] += pd[k-1][s-v[i]];
                if(pd[k][s] >= M)
                    pd[k][s] -= M;
            }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= S; ++j)
            if(j*n == i*S)
                ans = (ans+pd[min(i, n-i)][min(j, S-j)])%M;
    fout << ans << "\n";
    return 0;
}
