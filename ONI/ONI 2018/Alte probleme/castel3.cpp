#include <bits/stdc++.h>

using namespace std;

const int nmax = 105, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int test, n, m[nmax][nmax], nrcamere, _up, _down, _left, _right, cnt, solup, soldown, solleft, solright, mx, rooms;
bool ok[nmax][nmax];

bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= n && !ok[x][y];
}

void dfs(int x, int y)
{
    ok[x][y] = 1;
    ++cnt;
    _up = max(_up, x);
    _down = min(_down, x);
    _left = min(_left, y);
    _right = max(_right, y);
    int nr = m[x][y], pw = 8;
    for (int i = 0; i < 4; ++i){
        if(nr < pw){
            if(check(x+dx[i], y+dy[i]))
                dfs(x+dx[i], y+dy[i]);
        }else nr -= pw;
        pw /= 2;
    }
}

int main()
{
    ifstream fin ("castel3.in");
    ofstream fout ("castel3.out");
    fin >> test >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> m[i][j];
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if(!ok[i][j]){
                _up = -1;
                _down = n+1;
                _left = n+1;
                _right = -1;
                cnt = 0;
                dfs(i, j);
                if(cnt > mx){
                    mx = cnt;
                    solup = _up;
                    soldown = _down;
                    solleft = _left;
                    solright = _right;
                }
                ++rooms;
            }
    switch(test){
        case 1:
            fout << rooms << "\n";
            break;
        case 2:
            fout << mx << "\n";
            break;
        case 3:
            fout << soldown << " " << solleft << " " << solup << " " << solright << "\n";
            break;
    }
    return 0;
}

