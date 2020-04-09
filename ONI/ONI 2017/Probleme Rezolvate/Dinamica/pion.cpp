#include <fstream>

using namespace std;

int v[205][205], n, m;

int rec(int i1 = 1, int j1 = 1)
{
    if(v[i1][j1] != -1)
        return v[i1][j1];
    if(v[i1+1][j1] == -1)
        v[i1+1][j1] = rec(i1+1, j1);
    if(v[i1][j1+1] == -1)
        v[i1][j1+1] = rec(i1, j1+1);
    if((i1+j1)%2 == 0)
        v[i1][j1] = max(v[i1][j1+1], v[i1+1][j1]);
    else v[i1][j1] = min(v[i1][j1+1], v[i1+1][j1]);
    return v[i1][j1];
}

int main()
{
    ifstream fin ("pion.in");
    ofstream fout ("pion.out");
    fin >> n >> m;
    for (int i = 0; i < 205; ++i)
        for (int j = 0; j < 205; ++j)
            v[i][j] = -1;
    for (int i = 1; i <= m; ++i)
        fin >> v[i][n+1];
    for (int i = 1; i <= n; ++i)
        fin >> v[m+1][i];
    fout << rec() << "\n";
    fin.close();
    fout.close();
    return 0;
}

