#include <bits/stdc++.h>

using namespace std;

const int nmax = 3005, pmax = 3505, M = 31333;
int n, p, dp[nmax][pmax], c[nmax], e[nmax], last[nmax], vf, sub[nmax], pw2[nmax];
vector<int> v[nmax];

void dfs(int x, int pred = 0)
{
    e[++vf] = x;
    sub[x] = 1;
    for(auto y : v[x])
        if(y != pred){
            dfs(y, x);
            sub[x] += sub[y];
        }
    last[x] = vf;
}

int main()
{
    ifstream fin ("radare.in");
    ofstream fout ("radare.out");
    fin >> n >> p;
    for (int i = 2; i <= n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        fin >> c[i];
    dfs(1);
    pw2[0] = 1;
    for (int i = 1; i < nmax; ++i)
        pw2[i] = (pw2[i-1]*2)%M;
    dp[1][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= p; ++j)
            if(dp[i][j] > 0){
                if(j+c[e[i]] <= p){
                    dp[i+1][j+c[e[i]]] += dp[i][j];
                    if(dp[i+1][j+c[e[i]]] >= M)
                        dp[i+1][j+c[e[i]]] -= M;
                }
                dp[last[e[i]]+1][j] = (dp[last[e[i]]+1][j] + dp[i][j]*pw2[sub[e[i]]-1])%M;
            }
    fout << dp[n+1][p] << "\n";
    return 0;
}
