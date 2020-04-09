#include <bits/stdc++.h>

using namespace std;

const int64_t nmax = 305;
int64_t n, k, M, pd[nmax][nmax], comb[nmax][nmax];

int main()
{
    ifstream fin ("kmax.in");
    ofstream fout ("kmax.out");
    fin >> n >> k >> M;
    comb[0][0] = 1;
    for (int64_t i = 1; i < nmax; ++i){
        comb[i][0] = 1;
        for (int64_t j = 1; j <= i; ++j)
            comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%M;
    }
    for (int64_t i = 1; i <= k; ++i)
        pd[1][i] = 1;
    for (int64_t i = 2; i <= n; ++i)
        for (int64_t j = 1; j <= k; ++j){
            pd[i][j] = (pd[i-1][j-1]+pd[i-1][j])%M;
            for (int64_t q = 1; q < i; ++q)
                pd[i][j] = (pd[i][j] + pd[q][k-1]*pd[i-q-1][j]*comb[i-1][q])%M;
        }
    fout << pd[n][k];
    return 0;
}

