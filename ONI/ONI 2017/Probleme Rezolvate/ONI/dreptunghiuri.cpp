#include <fstream>
#include <vector>

using namespace std;

struct rectangle{
    int a, b, c, d;
}dt;

int n, m, mx(0), k;
bool v[1005][1005];
vector<rectangle> r;

void read();
void solve();
void meet_rectangle(int, int);
void fill(int, int);
void write();

int main()
{
    read();
    solve();
    write();
    return 0;
}

void read()
{
    ifstream fin ("dreptunghiuri.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    fin.close();
}

void solve()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j])
                meet_rectangle(i, j);
}

void meet_rectangle(int I, int J)
{
    int a, b, c, d, f(1);
    a = I;
    b = J;
    c = I;
    d = J;
    for (int i = I + 1; v[i][J]; ++i)
        ++c;
    for (int j = J + 1; v[I][j]; ++j)
        ++d;
    fill(I, J);
    for (int i = 0; i < r.size(); ++i)
        if (r[i].a < a && r[i].c > c && r[i].b < b && r[i].d > d)
            ++f;
    if (f > mx)
        mx = f,
        k = 1;
    else if (f == mx) ++k;
    dt.a = a, dt.b = b, dt.c = c, dt.d = d;
    r.push_back(dt);
}

void fill(int i, int j)
{
    if (v[i][j]){
        v[i][j] = 0;
        fill(i + 1, j);
        fill(i, j + 1);
        fill(i - 1, j);
        fill(i, j - 1);
    }
}

void write()
{
    ofstream fout ("dreptunghiuri.out");
    fout << r.size() << " " << mx << " " << k << "\n";
    fout.close();
}
