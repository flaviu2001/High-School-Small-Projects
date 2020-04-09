#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct data{
    int mx, n, m, k;
}dt;

vector<data> r;
int v[1005][1005], f[1000005];
int test, n, m, d;
bool p[1000005];

void read()
{
    ifstream fin ("intrus.in");
    fin >> test >> n >> m >> d;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    fin.close();
}

int suspects()
{
    int k = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j]){
                if (!f[v[i][j]])
                    ++f[v[i][j]];
                else if (f[v[i][j]] == 1){
                    ++f[v[i][j]];
                    k += 2;
                }
                else if (f[v[i][j]])
                    ++k;
            }
    return k;
}

void write1()
{
    ofstream fout ("intrus.out");
    fout << suspects() << "\n";
    fout.close();
}

void ciur()
{
    p[1] = 1;
    for (int i = 2; i * i <= 1000000; ++i)
        if (!p[i])
            for (int dd = i * i; dd <= 1000000; dd += i)
                p[dd] = 1;
}

bool check(int x, int y)
{
    if (x > 0 && y > 0 && x <= n && y <= m && v[x][y])
        return true;
    return false;
}

void suspects2()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j]){
                if (!f[v[i][j]])
                    ++f[v[i][j]];
                else if (f[v[i][j]] == 1)
                    ++f[v[i][j]];
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (f[v[i][j]] == 2){
                dt.mx = 0; dt.n = i; dt.m = j; dt.k = 0;
                for (int i1 = i - (d-1)/2; i1 <= i + (d-1)/2; ++i1)
                    for (int j1 = j - (d-1)/2; j1 <= j + (d-1)/2; ++j1){
                        if (!(i1 == i && j1 == j) && check(i1, j1) && f[v[i1][j1]] != 2 && !p[v[i1][j1]]){
                            if (v[i1][j1] > dt.mx)
                                dt.mx = v[i1][j1];
                            ++dt.k;
                        }
                    }
                r.push_back(dt);
            }
}

bool cmp(data d1, data d2)
{
    if (d1.k != d2.k)
        return d1.k > d2.k;
    if (d1.mx != d2.mx)
        return d1.mx > d2.mx;
    if (d1.n != d2.n)
        return d1.n < d2.n;
    return d1.m < d2.m;
}

void write2()
{
    ofstream fout ("intrus.out");
    sort(r.begin(), r.end(), cmp);
    for (unsigned i = 0; i < r.size(); ++i)
        fout << v[r[i].n][r[i].m] << " " << r[i].n << " " << r[i].m << "\n";
    if (!r.size())
        fout << "-1\n";
    fout.close();
}

int main()
{
    read();
    if (test == 1)
        write1();
    else{
        ciur();
        suspects2();
        write2();
    }
    return 0;
}
