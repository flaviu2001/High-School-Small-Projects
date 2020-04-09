#include <bits/stdc++.h>

using namespace std;

const int nmax = 1100, inf = 2000000000, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int v[nmax][nmax], n, memo[nmax][nmax];
pair<int, int> where[nmax][nmax];

bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= n;
}

int fill(int x, int y)
{
    if(memo[x][y] != -inf)
        return memo[x][y];
    int mx = 0;
    for (int i = 0; i < 4; ++i)
        if(check(x+dx[i], y+dy[i]) && v[x+dx[i]][y+dy[i]] > v[x][y] && mx < fill(x+dx[i], y+dy[i])){
            mx = fill(x+dx[i], y+dy[i]);
            where[x][y] = {x+dx[i], y+dy[i]};
        }
    if(mx == 0)
        where[x][y] = {x, y};
    memo[x][y] = mx+1;
    return mx+1;
}

int main()
{
    ifstream fin ("alpin.in");
    ofstream fout ("alpin.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            fin >> v[i][j];
            memo[i][j] = -inf;
        }
    int mx = 0, I, J;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            mx = max(mx, fill(i, j));
            if(mx == memo[i][j])
                I = i, J = j;
        }
    fout << mx << "\n";
    for (int i = 1; i <= mx; ++i){
        fout << I << " " << J << "\n";
        int NewI = where[I][J].first;
        int NewJ = where[I][J].second;
        I = NewI;
        J = NewJ;
    }
    return 0;
}

