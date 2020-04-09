#include <bits/stdc++.h>

using namespace std;

const int nmax = 1005, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, k1, k2, l1, c1, l2, c2, r[nmax][nmax], d[nmax][nmax];

bool check(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

int lee(int sx, int sy, int fx, int fy, int lo = -1, int hi = 1000000000)
{
    memset(d, 0, sizeof(d));
    queue< pair<int, int> > q;
    q.push({sx, sy});
    d[sx][sy] = 1;
    while(!q.empty() && !d[fx][fy]){
        pair<int, int> now = q.front();
        q.pop();
        for(int t = 0; t < 4; ++t){
            int nx = now.first+dx[t], ny = now.second+dy[t], x = now.first, y = now.second;
            if(!check(nx, ny) || d[nx][ny])
                continue;
            if(r[nx][ny] != 0 && r[nx][ny] < hi && r[nx][ny] > lo)
                continue;
            d[nx][ny] = d[x][y]+1;
            q.push({nx, ny});
        }
    }
    return d[fx][fy]-1;
}

int main()
{
    ifstream fin ("vis.in");
    ofstream fout ("vis.out");
    fin >> n >> k1 >> k2 >> l1 >> c1 >> l2 >> c2;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> r[i][j];
    int _1n00 = lee(1, 1, n, n), _1l100 = lee(1, 1, l1, c1), _l1nk10 = lee(l1, c1, n, n, k1), _1l200 = lee(1, 1, l2, c2), _l2l10k2 = lee(l2, c2, l1, c1, -1, k2);
    int _l2n0k2 = lee(l2, c2, n, n, -1, k2), _l1l2k10 = lee(l1, c1, l2, c2, k1), _l2nk1k2 = lee(l2, c2, n, n, k1, k2), _l1nk1k2 = lee(l1, c1, n, n, k1, k2), mn = 2000000000;
    if(_1n00 != -1)
        mn = _1n00;
    if(_1l100 != -1 && _l1nk10 != -1)
        mn = min(mn, _1l100 + _l1nk10);
    if(_1l200 != -1 && _l2n0k2 != -1)
        mn = min(mn, _1l200 + _l2n0k2);
    if(_1l100 != -1 && _l1l2k10 != -1 && _l2nk1k2 != -1)
        mn = min(mn, _1l100 + _l1l2k10 + _l2nk1k2);
    if(_1l200 != -1 && _l2l10k2 != -1 && _l1nk1k2 != -1)
        mn = min(mn, _1l200 + _l2l10k2 + _l1nk1k2);
    fout << mn+1 << "\n";
    return 0;
}

