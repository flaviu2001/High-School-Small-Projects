#include <bits/stdc++.h>

using namespace std;

int n, m, v[1005][1005], pd[1005][1005], mn[1005][1005], ans, I = 1, J = 1;

int main()
{
    ifstream fin ("joc.in");
    ofstream fout ("joc.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    for (int i = 0; i < 1005; ++i)
        for (int j = 0; j < 1005; ++j)
            mn[i][j] = -2000000000;
    ans = v[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            if(i == 1 && j > 1)
                mn[i][j] = mn[i][j-1];
            else if (i > 1 && j == 1)
                mn[i][j] = mn[i-1][j];
            else if (i == 1 && j == 1)
                mn[i][j] = -2000000000;
            else
                mn[i][j] = max(mn[i-1][j], mn[i][j-1]);
            if(i > 1)
                mn[i][j] = max(mn[i][j], pd[i-1][j]);
            if(j > 1)
                mn[i][j] = max(mn[i][j], pd[i][j-1]);
            if(i == 1 && j == 1)
                pd[i][j] = v[i][j];
            else
                pd[i][j] = v[i][j]-mn[i][j];
            if(pd[i][j] > ans){
                ans = pd[i][j];
                I = i;
                J = j;
            }
        }
    fout << ans << " " << I << " " << J << "\n";
    return 0;
}

