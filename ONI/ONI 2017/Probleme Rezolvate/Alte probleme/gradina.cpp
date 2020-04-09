#include <fstream>

using namespace std;

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int n, m, p[22][22][4], v[22][22], mx, r[1000];
int mx2, t1, t2;
bool v2[22][22];
char t3;

void read();
void add(int, int, int);
void matrix();
void fill(int, int, int);
void fill2(int, int);

int main()
{
    read();
    matrix();
    return 0;
}

void read()
{
    ifstream fin ("gradina.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int x;
            fin >> x;
            add(i, j, x);
        }
}

void add(int i1, int j1, int x)
{
    if (x >= 8)
        x -= 8,
        p[i1][j1][3] = 1;
    if (x >= 4)
        x -= 4,
        p[i1][j1][2] = 1;
    if (x >= 2)
        x -= 2,
        p[i1][j1][1] = 1;
    if (x >= 1)
        x -= 1,
        p[i1][j1][0] = 1;
}

void matrix()
{
    int k = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!v[i][j])
                fill(i, j, ++k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            ++r[v[i][j]];
            if (r[v[i][j]] > mx)
                mx = r[v[i][j]];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fill2(i, j);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            printf("%d ", v[i][j]);
        printf("\n");
    }
    ofstream fout ("gradina.out");
    fout << k << "\n" << mx << "\n" << mx2 << " " << t1 << " " << t2 << " " << t3 << "\n";
    fout.close();
}

void fill(int i1, int j1, int t)
{
    v[i1][j1] = t;
    for (int i = 0; i < 4; ++i)
        if (!p[i1][j1][i] && !v[i1+dx[i]][j1+dy[i]])
            fill(i1+dx[i], j1+dy[i], t);
}

void fill2(int i1, int j1)
{
    v2[i1][j1] = 1;
    for (int i = 0; i < 4; ++i)
        if (!p[i1][j1][i] && !v2[i1+dx[i]][j1+dy[i]])
            fill2(i1+dx[i], j1+dy[i]);
        else if (i1 + dx[i] > 0 && i1 + dx[i] <= n && j1 + dy[i] > 0 && j1 + dy[i] <= m && v[i1][j1] != v[i1+dx[i]][j1+dy[i]]){
            if (r[v[i1][j1]] + r[v[i1+dx[i]][j1+dy[i]]] > mx2){
                mx2 = r[v[i1][j1]] + r[v[i1+dx[i]][j1+dy[i]]];
                t1 = i1;
                t2 = j1;
                switch(i){
                    case 0:
                        t3 = 'V';
                        break;
                    case 1:
                        t3 = 'N';
                        break;
                    case 2:
                        t3 = 'E';
                        break;
                    case 3:
                        t3 = 'S';
                        break;
                }
            }
        }
}
