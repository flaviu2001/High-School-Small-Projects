#include <bits/stdc++.h>

using namespace std;

const int nmax = 2005, inf = 2000000002;
int test, n, k, nrz, nri, zeroes[nmax], v[nmax], sums[nmax][nmax], sz[nmax], pd[nmax][nmax];

int main()
{
    ifstream fin ("antivirus.in");
    ofstream fout ("antivirus.out");
    fin >> test;
    while(test--){
        memset(zeroes, 0, sizeof(zeroes));
        memset(sums, 0, sizeof(sums));
        memset(pd, 0, sizeof(pd));
        nri = 0, nrz = 0;
        fin >> n >> k;
        for (int i = 1; i <= n; ++i){
            fin >> v[i];
            if(v[i] == 0)
                zeroes[++nrz] = i, --k;
        }
        if(zeroes[1] != 1){
            ++nri;
            int sum = 0, cnt = 0;
            for (int j = zeroes[1]-1; j >= 1; --j){
                sum += v[j];
                ++cnt;
                sums[nri][cnt] = sum;
            }
            sz[nri] = cnt;
        }
        for (int i = 2; i <= nrz; ++i)
            if(zeroes[i-1]+1 != zeroes[i]){
                ++nri;
                sz[nri] = zeroes[i]-zeroes[i-1]-1;
                int sum = 0, cnt = 0;
                for (int j = zeroes[i-1]+1; j < zeroes[i]; ++j)
                    sums[nri][sz[nri]] += v[j];
                for (int j = 1; j < sz[nri]; ++j)
                    sums[nri][j] = inf;
                for (int j = zeroes[i]-1; j > zeroes[i-1]+1; --j){
                    sum += v[j];
                    ++cnt;
                    sums[nri][cnt] = min(sum, sums[nri][cnt]);
                }
                sum = 0, cnt = 0;
                sum = 0, cnt = 0;
                for (int j = zeroes[i-1]+1; j < zeroes[i]; ++j){
                    sum += v[j];
                    ++cnt;
                    sums[nri][cnt] = min(sum, sums[nri][cnt]);
                    int sumnow = 0, cntnow = 0;
                    for (int t = zeroes[i]-1; t > j+1; --t){
                        sumnow += v[t];
                        ++cntnow;
                        sums[nri][cnt+cntnow] = min(sums[nri][cnt+cntnow], sum+sumnow);
                    }
                }
            }
        if(zeroes[nrz] != n){
            ++nri;
            int sum = 0, cnt = 0;
            for (int j = zeroes[nrz]+1; j <= n; ++j){
                sum += v[j];
                ++cnt;
                sums[nri][cnt] = sum;
            }
            sz[nri] = cnt;
        }
        for (int i = 0; i <= sz[1]; ++i)
            pd[1][i] = sums[1][i];
        int total = sz[1];
        for (int i = 2; i <= nri; ++i){
            for (int j = 0; j <= sz[i]; ++j)
                pd[i][j] = sums[i][j];
            total += sz[i];
            for (int j = 0; j <= min(total, k); ++j){
                if(pd[i][j] == 0)
                    pd[i][j] = pd[i-1][j];
                pd[i][j] = min(pd[i][j], pd[i-1][j]);
                for (int t = 0; t <= min(sz[i], j); ++t)
                    if(j-t <= total-sz[i]){
                        if(pd[i][j] == 0)
                            pd[i][j] = pd[i-1][j-t]+sums[i][t];
                        pd[i][j] = min(pd[i][j], pd[i-1][j-t]+sums[i][t]);
                    }
            }
        }
        fout << pd[nri][k] << "\n";
    }
    return 0;
}

