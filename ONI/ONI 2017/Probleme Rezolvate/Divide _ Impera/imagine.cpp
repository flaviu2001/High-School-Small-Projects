#include <fstream>
#define MAX 255

using namespace std;

int n;
bool v[MAX][MAX];

void read()
{
    ifstream fin ("imagine.in");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j];
    fin.close();
}

bool uniform(int i1, int j1, int i2, int j2)
{
    bool vl = v[i1][j1];
    for (int i = i1; i <= i2; ++i)
        for (int j = j1; j <= j2; ++j)
            if (v[i][j] != vl)
                return false;
    return true;
}

int compress(int i1, int j1, int i2, int j2)
{
    if (uniform(i1, j1, i2, j2))
        return 2;
    int d1 = (i1+i2)/2, d2 = (j1+j2)/2;
    return 1 + compress(i1, j1, d1, d2) +
            compress(i1, d2+1, d1, j2) +
            compress(d1+1, j1, i2, d2) +
            compress(d1+1, d2+1, i2, j2);
}

void write()
{
    ofstream fout ("imagine.out");
    fout << compress(1, 1, n, n) << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}
