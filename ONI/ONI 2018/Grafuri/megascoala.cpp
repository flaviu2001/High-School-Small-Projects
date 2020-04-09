#include <fstream>

using namespace std;

int n, v[102][102], I, J, mn = 2000000000;

int main()
{
    ifstream fin("megascoala.in");
    ofstream fout("megascoala.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j];
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if(v[i][k] && v[k][j] && (v[i][j] == 0 || v[i][j] > v[i][k] + v[k][j]))
                    v[i][j] = v[i][k] + v[k][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if(i != j){
                int mx = 0;
                for (int k = 1; k <= n; ++k)
                    if(k != i && k != j)
                        mx = max(mx, min(v[i][k], v[j][k]));
                if(mx < mn){
                    I = i;
                    J = j;
                    mn = mx;
                }
            }
    fout << I << " " << J << " " << mn << "\n";
    fin.close();
    fout.close();
    return 0;
}

