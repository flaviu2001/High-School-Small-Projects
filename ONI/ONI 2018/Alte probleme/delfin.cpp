#include <bits/stdc++.h>

using namespace std;

const int nmax = 1005, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1}, inf = 2000000000;
int n, m, v[nmax][nmax], vS[nmax][nmax], vF[nmax][nmax], vD[nmax][nmax], w[nmax][nmax], ans = inf;
pair<int, int> S, D, F;
char ch[nmax];

struct stare{
    int x, y, one;
};

bool check(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void lee(int r[nmax][nmax], pair<int, int> strt, bool type)
{
    queue< pair<int, int> > q;
    q.push(strt);
    bool ok[nmax][nmax] = {0};
    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= m+1; ++j)
            r[i][j] = -1;
    r[strt.first][strt.second] = 0;
    ok[strt.first][strt.second] = 1;
    while(!q.empty()){
        int kx = q.front().first, ky = q.front().second;
        q.pop();
        for (int t = 0; t < 4; ++t)
            if(check(kx+dx[t], ky+dy[t]) && !ok[kx+dx[t]][ky+dy[t]] && v[kx+dx[t]][ky+dy[t]] == type){
                ok[kx+dx[t]][ky+dy[t]] = 1;
                r[kx+dx[t]][ky+dy[t]] = r[kx][ky]+1;
                q.push({kx+dx[t], ky+dy[t]});
            }
    }
}

bool checksol(int x, int y)
{
    for (int k = 0; k < 4; ++k)
        if(check(x+dx[k], y+dy[k]) && x+dx[k] == F.first && y+dy[k] == F.second)
            return true;
    return false;
}

int main()
{
    ifstream fin ("delfin.in");
    ofstream fout ("delfin.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fin >> (ch+1);
        for (int j = 1; j <= m; ++j){
            char q = ch[j];
            if(q == '0'){
                v[i][j] = 0;
            }else if (q == '1'){
                v[i][j] = 1;
            }else if (q == 'S'){
                v[i][j] = 1;
                S = {i, j};
            }else if (q == 'D'){
                v[i][j] = 0;
                D = {i, j};
            }else if (q == 'F'){
                v[i][j] = 1;
                F = {i, j};
            }
        }
    }
    lee(vS, S, 1);
    lee(vD, D, 0);
    queue<stare> q;
    q.push({F.first, F.second, 1});
    bool ok[nmax][nmax] = {0};
    ok[F.first][F.second] = 1;
    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= m+1; ++j)
            w[i][j] = inf;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(vD[i][j] != -1){
                int mn = inf;
                for (int k = 0; k < 4; ++k)
                    if(check(i+dx[k], j+dy[k]) && vS[i+dx[k]][j+dy[k]] != -1)
                        mn = min(mn, vS[i+dx[k]][j+dy[k]]+1);
                if(mn == inf)
                    continue;
                w[i][j] = max(mn, vD[i][j]);
                if(checksol(i, j))
                    ans = min(ans, w[i][j]+1);
            }
    while(!q.empty()){
        stare k = q.front();
        q.pop();
        for (int t = 0; t < 4; ++t)
            if(check(k.x+dx[t], k.y+dy[t]) && !ok[k.x+dx[t]][k.y+dy[t]]){
                if(v[k.x+dx[t]][k.y+dy[t]] == v[k.x][k.y]){
                    if(v[k.x+dx[t]][k.y+dy[t]] == 0 && w[k.x+dx[t]][k.y+dy[t]] != inf)
                        ans = min(ans, w[k.x+dx[t]][k.y+dy[t]]+vF[k.x][k.y]+1);
                    vF[k.x+dx[t]][k.y+dy[t]] = vF[k.x][k.y] + 1;
                    q.push({k.x+dx[t], k.y+dy[t], k.one});
                    ok[k.x+dx[t]][k.y+dy[t]] = 1;
                }else if (v[k.x][k.y] == 1 && k.one == 1){
                    if(v[k.x+dx[t]][k.y+dy[t]] == 0 && w[k.x+dx[t]][k.y+dy[t]] != inf)
                        ans = min(ans, w[k.x+dx[t]][k.y+dy[t]]+vF[k.x][k.y]+1);
                    vF[k.x+dx[t]][k.y+dy[t]] = vF[k.x][k.y] + 1;
                    q.push({k.x+dx[t], k.y+dy[t], 0});
                    ok[k.x+dx[t]][k.y+dy[t]] = 1;
                }
            }
    }
    if(vS[F.first][F.second] != -1)
        ans = min(ans, vS[F.first][F.second]);
    fout << ans << "\n";
    return 0;
}
