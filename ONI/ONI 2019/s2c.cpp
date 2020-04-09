#include <bits/stdc++.h>

using namespace std;

int test, n, v[2005], s[2005], mapto[30005], pd[2005][2005];

int main()
{
    ifstream fin ("s2c.in");
    ofstream fout ("s2c.out");
    fin >> test;
    while(test--){
        fin >> n;
        for (int i = 1; i <= n; ++i){
            fin >> v[i];
            s[i] = v[i];
        }
        sort(s+1, s+n+1);
        memset(mapto, 0, sizeof(mapto));
        int p = 0;
        for (int i = 1; i <= n; ++i)
            if(mapto[s[i]] == 0)
                mapto[s[i]] = ++p;
        for (int i = 1; i <= n; ++i)
            v[i] = mapto[v[i]];
        memset(pd, 0, sizeof(pd));
        int ans = 1;
        for (int i = 1; i <= n; ++i){
            pd[0][i] = 1;
            for (int j = 1; j <= n; ++j)
                pd[j][i] = max(pd[j][i], pd[j-1][i]);
            for (int j = i+1; j <= n; ++j){
                pd[v[i]][j] = pd[v[j]-1][i]+1;
                ans = max(ans, pd[v[i]][j]);
            }
        }
        fout << ans << "\n";
    }
}

