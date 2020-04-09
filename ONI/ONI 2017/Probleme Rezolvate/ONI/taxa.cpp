#include <fstream>
#include <queue>
#define MAX 1005

using namespace std;

struct coord{
    int a, b;
}pi, pf, dt, dd;

queue<coord> q[40005];
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1}, dy[] = {0, 1, -1, 0, 1, -1, -1, 1};
int v[MAX][MAX], r[MAX][MAX], n, m;

void read();
void solve();
void fill(int, int, int, int);
bool check(int, int);

int main()
{
    read();
    solve();
    return 0;
}

void read()
{
    ifstream fin ("taxa.in");
    fin >> n >> m >> pi.a >> pi.b >> pf.a >> pf.b;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j],
            r[i][j] = -1;
    fin.close();
}

void solve()
{
    q[0].push(pi);
    for (int i = 0; i < 40005; ++i)
        for (; !q[i].empty(); q[i].pop()){
            dd = q[i].front();
            if (r[dd.a][dd.b] == -1)
                fill(dd.a, dd.b, v[dd.a][dd.b], i);
            if (r[pf.a][pf.b] != -1){
                ofstream fout ("taxa.out");
                fout << r[pf.a][pf.b] << "\n";
                fout.close();
                return;
            }
        }
}

void fill(int i1, int j1, int c, int vl)
{
    if (check(i1, j1) && r[i1][j1] == -1){
        if (v[i1][j1] == c){
            r[i1][j1] = vl;
            for (int i = 0; i < 8; ++i)
                fill(i1+dx[i], j1+dy[i], c, vl);
        }
        else{
            dt.a = i1;
            dt.b = j1;
            q[vl+v[i1][j1]*c].push(dt);
        }
    }
}

bool check(int x1, int y1)
{
    if (x1 <= 0 || x1 > n || y1 <= 0 || y1 > m)
        return false;
    return true;
}
