#include <fstream>
#define INF 1 << 30

using namespace std;

int n, m, r[260][260], v[2][260];

void read()
{
    freopen("lacusta.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &r[i][j]);
    fclose(stdin);
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int magic()
{
    v[1][1] = r[1][1];
    for (int i = 2; i <= m; ++i)
        v[1][i] = r[1][i] + r[1][1];
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            v[0][j] = v[1][j];
            v[1][j] = INF;
        }
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k <= m; ++k){
                if (j == k || (i == 2 && k == 1))
                    continue;
                v[1][j] = min(v[0][k] + r[i][k] + r[i][j], v[1][j]);
            }
    }
    return v[1][m];
}

void write()
{
    freopen("lacusta.out", "w", stdout);
    printf("%d\n", magic());
    fclose(stdout);
}

int main()
{
    read();
    write();
    return 0;
}
