#include <fstream>

using namespace std;

int n, k, p, q, v[520][520];

void read()
{
    ifstream fin ("pav.in");
    fin >> k >> p >> q;
    n = 1;
    for (int i = 1; i <= k; ++i, n *= 2);
    k = 0;
    fin.close();
}

void pav(int i1, int j1, int i2, int j2, int x, int y)
{
    if (i1 + 1 == i2){
        ++k;
        for (int i = i1; i <= i2; ++i)
            for (int j = j1; j <= j2; ++j)
                if (i != x || j != y)
                    v[i][j] = k;
        return;
    }
    int m1 = (i1+i2)/2;
    int m2 = (j1+j2)/2;
    if (x <= m1 && y <= m2){
        ++k;
        v[m1+1][m2] = v[m1][m2+1] = v[m1+1][m2+1] = k;
        pav(i1, j1, m1, m2, x, y);
        pav(i1, m2+1, m1, j2, m1, m2+1);
        pav(m1+1, j1, i2, m2, m1+1, m2);
        pav(m1+1, m2+1, i2, j2, m1+1, m2+1);
        return;
    }
    if (x <= m1 && y > m2){
        ++k;
        v[m1+1][m2] = v[m1][m2] = v[m1+1][m2+1] = k;
        pav(i1, j1, m1, m2, m1, m2);
        pav(i1, m2+1, m1, j2, x, y);
        pav(m1+1, j1, i2, m2, m1+1, m2);
        pav(m1+1, m2+1, i2, j2, m1+1, m2+1);
        return;
    }
    if (x > m1 && y <= m2){
        ++k;
        v[m1][m2] = v[m1][m2+1] = v[m1+1][m2+1] = k;
        pav(i1, j1, m1, m2, m1, m2);
        pav(i1, m2+1, m1, j2, m1, m2+1);
        pav(m1+1, j1, i2, m2, x, y);
        pav(m1+1, m2+1, i2, j2, m1+1, m2+1);
        return;
    }
    if (x > m1 && y > m2){
        ++k;
        v[m1][m2] = v[m1][m2+1] = v[m1+1][m2] = k;
        pav(i1, j1, m1, m2, m1, m2);
        pav(i1, m2+1, m1, j2, m1, m2+1);
        pav(m1+1, j1, i2, m2, m1+1, m2);
        pav(m1+1, m2+1, i2, j2, x, y);
        return;
    }
}

void write()
{
    ofstream fout ("pav.out");
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            fout << v[i][j] << " ";
        fout << "\n";
    }
    fout.close();
}

int main()
{
    read();
    pav(1, 1, n, n, p, q);
    write();
    return 0;
}
