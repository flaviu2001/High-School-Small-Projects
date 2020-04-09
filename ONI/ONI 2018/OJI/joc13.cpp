#include <fstream>

using namespace std;

int n, k, v[2][5005], pd[2][5005], pd2[2][5005];

int suma (int i3, int i1, int i2)
{
    int sum = 0;
    for (int i = i1; i <= i2; ++i)
        sum += v[i3][i];
    return sum;
}

int main()
{
    ifstream fin ("joc15.in");
    ofstream fout ("joc15.out");
    fin >> n >> k;
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j];
    pd[0][1] = v[0][1];
    pd[1][1] = v[1][1] + v[0][1];
    pd2[0][1] = v[0][1];
    for (int j = 2; j <= n; ++j)
        for (int i = 0; i < 2; ++i){
            int mx = -1<<29;
            for (int t = max(1, j-k+1); t < j; ++t)
                mx = max(mx, pd2[1-i][t] + suma(i, t, j));
            pd2[i][j] = mx;
            mx = max(mx, pd[1-i][j-1] + v[1][j] + v[0][j]);
            pd[i][j] = mx;
        }
    fout << pd[1][n] << "\n";
    fin.close();
    fout.close();
    return 0;
}

