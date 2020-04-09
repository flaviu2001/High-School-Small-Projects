#include <bits/stdc++.h>

using namespace std;

const int nmax = 505, M = 666013;
int n, m, v[nmax][nmax], r[nmax][nmax], lasta[256][nmax], lastb[256][nmax], mx, sol;
char c1[nmax], c2[nmax];

int main()
{
    ifstream fin ("subsir.in");
    ofstream fout ("subsir.out");
    fin >> (c1+1) >> (c2+1);
    n = strlen(c1+1);
    m = strlen(c2+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            if(c1[i] == c2[j])
                v[i][j] = 1+v[i-1][j-1];
            else v[i][j] = max(v[i-1][j], v[i][j-1]);
            mx = max(mx, v[i][j]);
        }
    memset(lasta, -1, sizeof(lasta));
    memset(lastb, -1, sizeof(lastb));
    for  (int k = 'a'; k <= 'z'; ++k)
        for (int i = 1; i <= n; ++i)
            if(c1[i] == k)
                lasta[k][i] = i;
            else lasta[k][i] = lasta[k][i-1];
    for (int k = 'a'; k <= 'z'; ++k)
        for (int i = 1; i <= m; ++i)
            if(c2[i] == k)
                lastb[k][i] = i;
            else lastb[k][i] = lastb[k][i-1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(c1[i] == c2[j]){
                if(v[i][j] == 1){
                    r[i][j] = 1;
                    continue;
                }
                for (int k = 'a'; k <= 'z'; ++k){
                    int la = lasta[k][i-1], lb = lastb[k][j-1];
                    if(la != -1 && lb != -1 && v[la][lb]+1 == v[i][j]){
                        r[i][j] += r[la][lb];
                        r[i][j] %= M;
                    }
                }
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(v[i][j] == mx){
                int la = lasta[c1[i]][n], lb = lastb[c2[j]][m];
                if(la <= i && lb <= j){
                    sol += r[i][j];
                    sol %= M;
                }
            }
    fout << sol << "\n";
    return 0;
}

