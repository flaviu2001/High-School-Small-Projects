#include <fstream>
#include <vector>

using namespace std;

char q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int d[130][130], n, m, mx, k;
int v[130 * 130], mx2, I, J;

void read()
{
    ifstream fin ("vila.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            fin >> q;
            if (q == '1')
                d[i][j] = -1;
        }
    fin.close();
}

bool check(int i1, int j1)
{
    if (i1 > 0 && j1 > 0 && i1 <= n && j1 <= m)
        return true;
    return false;
}

void fill(int i1, int j1, int c)
{
    ++v[c];
    if (v[c] > mx)
        mx = v[c];
    d[i1][j1] = c;
    for (int i = 0; i < 4; ++i)
        if (check(i1 + dx[i], j1 + dy[i]) && d[i1 + dx[i]][j1 + dy[i]] == 0)
            fill(i1 + dx[i], j1 + dy[i], c);
}

void matrix()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (d[i][j] == 0)
                fill(i, j, ++k);
}

bool check2(int i1, int j1)
{
    if (i1 <= 0 || j1 <= 0 || i1 > n || j1 > m)
        return false;
    if (d[i1][j1] == -1)
        return false;
    return true;
}

void flip()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (d[i][j] == -1){
                bool okk[130 * 130] = {0};
                vector<int> tr;
                int ok = 0, i2;
                for (int i1 = 0; i1 < 4; ++i1)
                    if (check2(i + dx[i1], j + dy[i1])){
                        if (!okk[d[i+dx[i1]][j+dy[i1]]])
                            tr.push_back(d[i+dx[i1]][j+dy[i1]]),
                            okk[d[i+dx[i1]][j+dy[i1]]] = 1;
                        ++ok;
                        i2 = i1;
                    }
                if (ok == 0 && 1 > mx2){
                    mx2 = 1;
                    I = i;
                    J = j;
                }
                if (ok == 1 && v[d[i+dx[i2]][j+dy[i2]]] + 1 > mx2){
                    mx2 = v[d[i+dx[i2]][j+dy[i2]]] + 1;
                    I = i;
                    J = j;
                }
                if (ok >= 2){
                    int rr = 1;
                    for (unsigned i1 = 0; i1 < tr.size(); ++i1)
                        rr += v[tr[i1]];
                    if (rr > mx2){
                        mx2 = rr;
                        I = i;
                        J = j;
                    }
                }
            }
}

void write()
{
    ofstream fout ("vila.out");
    fout << k << "\n" << mx << "\n" << I << " " << J << " " << mx2 << "\n";
    fout.close();
}

int main()
{
    read();
    matrix();
    flip();
    write();
    return 0;
}
