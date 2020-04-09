#include <fstream>

using namespace std;

int n, m, a[1005][1005], b[1005][1005];

int min(int x, int y)
{
    return x < y ? x : y;
}

void makeMatrix()
{
    for (int i = 1; i <= n; ++i)
        if (a[i][1])
            b[i][1] = 0;
        else b[i][1] = b[i-1][1] + 1;
    for (int i = 1; i <= m; ++i)
        if (a[1][i])
            b[1][i] = 0;
        else b[1][i] = b[1][i-1] + 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= m; ++j){
            if (a[i][j]){
                if (!b[i-1][j] || !b[i][j-1])
                    b[i][j] = 0;
                else if (b[i-1][j] > 0 && b[i][j-1] > 0)
                    b[i][j] = -b[i-1][j-1];
                else b[i][j] = min(b[i-1][j], b[i][j-1]);
            }
            else{
                if (a[i-1][j])
                    b[i][j] = b[i][j-1] + 1;
                else if (a[i][j-1])
                    b[i][j] = b[i-1][j] + 1;
                else if (b[i-1][j-1] > 0)
                    b[i][j] = b[i][j-1] + b[i-1][j] - b[i-1][j-1] + 1;
                else if (b[i-1][j-1] <= 0)
                    b[i][j] = b[i][j-1] + b[i-1][j] + b[i-1][j-1] + 1;
            }
        }
}

int main()
{
    ifstream fin ("acces.in");
    ofstream fout ("acces.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];
    makeMatrix();
    int t;
    fin >> t;
    while(t--){
        int x, y;
        fin >> x >> y;
        fout << b[x][y] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
