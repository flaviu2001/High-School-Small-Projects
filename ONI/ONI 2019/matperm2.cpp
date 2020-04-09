//very ugly implementation, spent like 3 hours on it don't judge
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int n, m, t, v[1005][1005], p[1005][1005], ans[1005][1005], lin[1005], col[1005], where[1005*1005], to[1005*1005], r[1005*1005], test;
bool ok[1005][1005];

void prod(int a[][1005], int b[][1005])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int x = (b[i][j]-1)/m+1;
            int y = b[i][j]-(x-1)*m;
            ans[i][j] = a[x][y];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = ans[i][j];
}

int main()
{
    ifstream fin ("matperm2.in");
    ofstream fout ("matperm2.out");
    fin >> n >> m >> t;
    for (int i = 1; i <= n; ++i)
        fin >> lin[i];
    for (int i = 1; i <= m; ++i)
        fin >> col[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i][j] = (lin[i]-1)*m+col[j];
    fin >> test;
    while(test--){
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        swap(v[x][y], v[a][b]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            p[i][j] = v[i][j];
            where[v[i][j]] = (i-1)*m+j;
        }
    prod(p, v);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            to[where[p[i][j]]] = (i-1)*m+j;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(!ok[i][j]){
                int now = 0, x = i, y = j;
                while(!ok[x][y]){
                    ok[x][y] = 1;
                    r[++now] = (x-1)*m+y;
                    int newx = (to[(x-1)*m+y]-1)/m+1;
                    int newy = to[(x-1)*m+y]-(newx-1)*m;
                    x = newx;
                    y = newy;
                }
                for (int i = 1; i <= now; ++i){
                    int nxt = (i+t-1)%now;
                    if(nxt == 0)
                        nxt = now;
                    int x = (r[nxt]-1)/m+1;
                    int y = r[nxt]-(x-1)*m;
                    int x1 = (r[i]-1)/m+1;
                    int y1 = r[i]-(x1-1)*m;
                    p[x][y] = v[x1][y1];
                }
            }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            fout << p[i][j] << " ";
        fout << "\n";
    }
    return 0;
}
