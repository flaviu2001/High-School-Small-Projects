#include <fstream>
#define MAX 1005

using namespace std;

int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
int n, m, mx, v[MAX][MAX];
int p[105], t[105], r[105][105];

void read();
void perimeters();
bool check(int, int);
int enclave_count();
void write();

int main()
{
    read();
    perimeters();
    write();
    return 0;
}

void read()
{
    ifstream fin ("enclave.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    fin.close();
}

void perimeters()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int y = 0; y < 4; ++y)
                if (check(i+dx[y], j+dy[y]) && v[i][j] != v[i+dx[y]][j+dy[y]]){
                    ++p[v[i+dx[y]][j+dy[y]]];
                    if (!r[v[i][j]][v[i+dx[y]][j+dy[y]]]){
                        r[v[i][j]][v[i+dx[y]][j+dy[y]]] = 1;
                        ++t[v[i+dx[y]][j+dy[y]]];
                    }
                }
    for (int i = 1; i <= n; ++i)
        t[v[i][1]] = t[v[i][m]] = 0;
    for (int j = 1; j <= m; ++j)
        t[v[1][j]] = t[v[n][j]] = 0;
}

int enclave_count()
{
    int k(0);
    for (int i = 1; i <= 104; ++i)
        if (t[i] == 1){
            ++k;
            if (p[i] > mx)
                mx = p[i];
        }
    return k;
}

bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m;
}

void write()
{
    ofstream fout ("enclave.out");
    fout << enclave_count() << " ";
    fout << mx << "\n";
    fout.close();
}
