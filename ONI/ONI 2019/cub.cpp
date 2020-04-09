#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "cub";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

struct pos{
    int f, x, y;
};

int n, v[6][55][55], mx = inf, mxf;
queue<pos> q;

pos walk(pos now, int d)
{
    now.x += dx[d];
    now.y += dy[d];
    if(now.x == 0){
        if(now.f == 0){
            now.f = 3;
            now.x = 1;
            now.y = n+1-now.y;
            return now;
        }
        if(now.f == 1){
            now.f = 0;
            now.x = n;
            return now;
        }
        if(now.f == 2){
            now.f = 3;
            now.x = n;
            return now;
        }
        if(now.f == 3){
            now.f = 0;
            now.x = 1;
            now.y = n+1-now.y;
            return now;
        }
        if(now.f == 4){
            now.f = 0;
            now.x = n+1-now.y;
            now.y = n;
            return now;
        }
        if(now.f == 5){
            now.f = 0;
            now.x = now.y;
            now.y = 1;
            return now;
        }
    }
    if(now.x == n+1){
        if(now.f == 0){
            now.f = 1;
            now.x = 1;
            return now;
        }
        if(now.f == 1){
            now.f = 2;
            now.x = n;
            now.y = n+1-now.y;
            return now;
        }
        if(now.f == 2){
            now.f = 1;
            now.x = n;
            now.y = n+1-now.y;
            return now;
        }
        if(now.f == 3){
            now.f = 2;
            now.x = 1;
            return now;
        }
        if(now.f == 4){
            now.f = 2;
            now.x = n+1-now.y;
            now.y = 1;
            return now;
        }
        if(now.f == 5){
            now.f = 2;
            now.x = now.y;
            now.y = n;
            return now;
        }
    }
    if(now.y == 0){
        if(now.f == 0){
            now.f = 5;
            now.y = now.x;
            now.x = 1;
            return now;
        }
        if(now.f == 1){
            now.f = 5;
            now.y = n;
            return now;
        }
        if(now.f == 2){
            now.f = 4;
            now.y = n+1-now.x;
            now.x = n;
            return now;
        }
        if(now.f == 3){
            now.f = 4;
            now.y = n;
            return now;
        }
        if(now.f == 4){
            now.f = 1;
            now.y = n;
            return now;
        }
        if(now.f == 5){
            now.f = 3;
            now.y = n;
            return now;
        }
    }
    if(now.y == n+1){
        if(now.f == 0){
            now.f = 4;
            now.y = n+1-now.x;
            now.x = 1;
            return now;
        }
        if(now.f == 1){
            now.f = 4;
            now.y = 1;
            return now;
        }
        if(now.f == 2){
            now.f = 5;
            now.y = now.x;
            now.x = n;
            return now;
        }
        if(now.f == 3){
            now.f = 5;
            now.y = 1;
            return now;
        }
        if(now.f == 4){
            now.f = 3;
            now.y = 1;
            return now;
        }
        if(now.f == 5){
            now.f = 1;
            now.y = 1;
            return now;
        }
    }
    return now;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    int m;
    pos start;
    fin >> n >> m >> start.f >> start.x >> start.y; --start.f;
    while(m--){
        pos now;
        fin >> now.f >> now.x >> now.y;
        v[now.f-1][now.x][now.y] = -2;
    }
    for (int f = 0; f < 6; ++f)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                bool yea = v[f][i][j] == -2;
                fin >> v[f][i][j], v[f][i][j] *= -1;
                if(yea && !v[f][i][j])
                    v[f][i][j] = -2;
            }
    v[start.f][start.x][start.y] = 1;
    q.push(start);
    while(!q.empty()){
        pos now = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d){
            pos nxt = walk(now, d);
            if(v[nxt.f][nxt.x][nxt.y] == -1 || v[nxt.f][nxt.x][nxt.y] > 0)
                continue;
            if(v[nxt.f][nxt.x][nxt.y] == -2){
                if(mx > v[now.f][now.x][now.y]+1){
                    mx = v[now.f][now.x][now.y]+1;
                    mxf = 1;
                }else if (mx == v[now.f][now.x][now.y]+1)
                    ++mxf;
            }
            v[nxt.f][nxt.x][nxt.y] = v[now.f][now.x][now.y]+1;
            q.push(nxt);
        }
    }
    fout << mx << "\n" << mxf << "\n";
    return 0;
}
