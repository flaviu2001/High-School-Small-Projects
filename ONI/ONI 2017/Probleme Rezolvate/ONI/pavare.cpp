#include <fstream>
 
using namespace std;
 
int n, m, v[155][155], t;
 
void read();
void pavareA1(int&, int, int);
void pavareA2(int&, int, int);
void pavareB1(int, int);
void pavareB2(int, int);
void pavare();
void write();
 
int main()
{
    read();
    pavare();
    write();
    return 0;
}
 
void read()
{
    ifstream fin ("pavare3.in");
    fin >> n >> m;
    fin.close();
}
 
void pavare()
{
    int k = n * m / 2 / 12, p = 0;
    if (n > 3){
        for (int i = 1; i <= n - 3 && p < k; i += 4)
            for (int j = 1; j <= m - 2 && p < k; j += 3)
                pavareA1(p, i, j);
    }
    else{
        for (int j = 1; j <= m - 3 && p < k; j += 4)
            pavareA2(p, 1, j);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!v[i][j] && !v[i+1][j] && i < n)
                pavareB1(i, j);
            else if (!v[i][j] && !v[i][j+1] && j < m)
                pavareB2(i, j);
}
 
void pavareA1(int &p, int i1, int j1)
{
    ++p;
    v[i1][j1] = v[i1][j1+1] = v[i1+1][j1] = v[i1+2][j1] = v[i1+2][j1+1] = v[i1+3][j1] = ++t;
    v[i1][j1+2] = v[i1+1][j1+1] = v[i1+1][j1+2] = v[i1+2][j1+2] = v[i1+3][j1+1] = v[i1+3][j1+2] = ++t;
}
 
void pavareA2(int &p, int i1, int j1)
{
    ++p;
    v[i1][j1] = v[i1][j1+1] = v[i1][j1+2] = v[i1][j1+3] = v[i1+1][j1+1] = v[i1+1][j1+3] = ++t;
    v[i1+2][j1] = v[i1+2][j1+1] = v[i1+2][j1+2] = v[i1+2][j1+3] = v[i1+1][j1] = v[i1+1][j1+2] = ++t;
}
 
 
void pavareB1(int i1, int j1)
{
    v[i1][j1] = v[i1+1][j1] = ++t;
}
 
void pavareB2(int i1, int j1)
{
    v[i1][j1] = v[i1][j1+1] = ++t;
}
 
void write()
{
    ofstream fout ("pavare3.out");
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            fout << v[i][j] << " ";
        fout << "\n";
    }
    fout.close();
}