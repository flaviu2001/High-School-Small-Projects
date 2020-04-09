#include <bits/stdc++.h>
#define M 30011

using namespace std;

vector<int> v[102];
bool ok[102];
int r[102], t;
int memo[102][102];

int dfs(int x, int k)
{
    if(memo[x][k] != -1)
        return memo[x][k];
    int sol = 1;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it){
        int n = 0;
        for (int i = k+1; i <= t-r[*it]+1; ++i){
            memo[*it][i] = dfs(*it, i);
            n = (n+memo[*it][i])%M;
        }
        sol = (1LL*sol*n)%M;
    }
    memo[x][k] = sol;
    return sol;
}

int df(int x)
{
    if(v[x].size() == 0)
        return 1;
    int n = 0;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        n = max(n, df(*it)+1);
    return n;
}

int main()
{
    ifstream fin ("iepuri2.in");
    ofstream fout ("iepuri2.out");
    int n;
    fin >> n >> t;
    for (int i = 0; i < 102; ++i)
        for (int j = 0; j < 102; ++j)
            memo[i][j] = -1;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        ok[y] = 1;
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
        r[i] = df(i);
    int sol = 1;
    for (int u = 1; u <= n; ++u)
        if(!ok[u]){
            int x = 0;
            for (int i = 1; i <= t-r[u]+1; ++i)
                x = (x+dfs(u, i))%M;
            sol = (1ll*sol*x)%M;
        }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}
