#include <bits/stdc++.h>

using namespace std;

int n, k, pd[505][505][2], pd2[505];
char c[505];

int main()
{
    ifstream fin ("zuma.in");
    ofstream fout ("zuma.out");
    fin >> n >> k >> (c+1);
    for (int d = 0; d <= n; ++d)
        for (int i = 1; i+d <= n; ++i){
            int j = i+d;
            if(i == j){
                pd[i][j][0] = pd[i][j][1] = 1;
                continue;
            }
            if(c[i] == c[j]){
                pd[i][j][0] = -1;
                for (int p = i+1; p <= j; ++p){
                    if(pd[i][p-1][0] == -1 || pd[p][j][1] == -1)
                        continue;
                    pd[i][j][0] = max(pd[i][j][0], pd[i][p-1][0]+pd[p][j][1]);
                }
                pd[i][j][1] = pd[i][j][0];
            }else{
                pd[i][j][0] = pd[i][j][1] = -1;
                for (int p = i+1; p <= j; ++p){
                    if(pd[i][p-1][0] != -1 && pd[p][j][0] != -1 && c[p] == c[i])
                        pd[i][j][0] = max(pd[i][j][0], pd[i][p-1][0]+pd[p][j][0]);
                    if(pd[i][p-1][0] != -1 && (pd[p][j][0] >= k || pd[p][j][1] >= k))
                        pd[i][j][0] = max(pd[i][j][0], pd[i][p-1][0]);
                    if(pd[p][j][1] != -1 && pd[i][p-1][1] != -1 && c[p-1] == c[j])
                        pd[i][j][1] = max(pd[i][j][1], pd[i][p-1][1]+pd[p][j][1]);
                    if(pd[p][j][1] != -1 && (pd[i][p-1][0] >= k || pd[i][p-1][1] >= k))
                        pd[i][j][1] = max(pd[i][j][1], pd[p][j][1]);
                }
            }
        }
    for (int i = 1; i <= n; ++i){
        pd2[i] = pd2[i-1]+1;
        for (int j = i; j >= 1; --j)
            if(pd[j][i][0] >= k || pd[j][i][1] >= k)
                pd2[i] = min(pd2[i], pd2[j-1]);
    }
    fout << pd2[n] << "\n";
    return 0;
}
