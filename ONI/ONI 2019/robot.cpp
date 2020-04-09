#include <bits/stdc++.h>

using namespace std;

struct stare{
    int dir, x, y;
};

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; //0 - N, 1 - E, 2 - S, 3 - V
int n, v[1005][1005], px, py, qx, qy, d1[4][1005][1005], d2[4][1005][1005];
stare q[7000000];

stare mks(int dir, int x, int y)
{
    stare aux;
    aux.dir = dir;
    aux.x = x;
    aux.y = y;
    return aux;
}

bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n && !v[x][y];
}

void lee(int startx, int starty, int d[][1005][1005])
{
    int p = 0, f = 0;
    for (int i = 0; i < 4; ++i){
        d[i][startx][starty] = 1;
        q[++f] = mks(i, startx, starty);
    }
    int x, y, cx, cy, dist;
    while(p != f){
        ++p;
        stare k = q[p];
        x = k.x, y = k.y;
        for (int t = 0; t < 4; ++t){
            cx = x+dx[t], cy = y+dy[t], dist = d[k.dir][x][y];
            if(t != k.dir)
                ++dist;
            if(cx >= 1 && cx <= n && cy >= 1 && cy <= n && !v[cx][cy] && (d[t][cx][cy] == 0 || dist < d[t][cx][cy])){
                d[t][cx][cy] = dist;
                q[++f] = mks(t, cx, cy);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int t = 0; t < 4; ++t)
                --d[t][i][j];
}

int minx(int x, int y, bool D1)
{
    int mn = 2000000000;
    if(D1){
        for (int i = 0; i < 4; ++i)
            if(d1[i][x][y] != -1)
                mn = min(mn, d1[i][x][y]);
    }else
        for (int i = 0; i < 4; ++i)
            if(d2[i][x][y] != -1)
                mn = min(mn, d2[i][x][y]);
    return mn;
}

int main()
{
    ifstream fin ("robot2.in");
    ofstream fout ("robot2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j];
    fin >> px >> py >> qx >> qy;
    lee(px, py, d1);
    lee(qx, qy, d2);
    int mnx = minx(qx, qy, 1);
    fout << mnx << " ";
    int cnt = 0, mn = mnx;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if(v[i][j]){
                int mn1 = mnx;
                for (int t1 = 0; t1 < 4; ++t1)
                    if(check(i+dx[t1], j+dy[t1]))
                        for (int t2 = 0; t2 < 4; ++t2)
                            if(t1 != t2 && check(i+dx[t2], j+dy[t2])){
                                int x1 = i+dx[t1], y1 = j+dy[t1], x2 = i+dx[t2], y2 = j+dy[t2];
                                int e1 = minx(x1, y1, 1), e2 = minx(x2, y2, 0);
                                if(e1 == 2000000000 || e2 == 2000000000)
                                    continue;
                                if(e1 != d1[(t1+2)%4][x1][y1])
                                    ++e1;
                                if(e2 != d2[(t2+2)%4][x2][y2])
                                    ++e2;
                                if((t1+2)%4 != t2)
                                    ++e1;
                                mn1 = min(mn1, e1+e2);
                            }
                if(mn1 < mn){
                    mn = mn1;
                    cnt = 1;
                }else if(mn1 == mn)
                    ++cnt;
            }
    fout << mn << " " << cnt << "\n";
    return 0;
}

