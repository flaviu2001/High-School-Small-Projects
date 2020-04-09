#include <fstream>
 
using namespace std;
 
int n, v[1005][1005], d[1005][1005], r[1005];
 
void read()
{
    ifstream fin ("custi.in");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j];
    fin.close();
}
 
int min(int x, int y, int z)
{
    int mn = x;
    if(y < mn)
        mn = y;
    if(z < mn)
        mn = z;
    return mn;
}
 
void magic()
{
    for (int i = 1; i <= n; ++i){
        d[i][1] = v[i][1];
        d[1][i] = v[1][i];
        r[1] += v[i][1];
        r[1] += v[1][i];
    }
    r[1] -= v[1][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            if (v[i][j]){
                if(v[i-1][j] && v[i][j-1] && v[i-1][j-1])
                    d[i][j] = min(d[i-1][j], d[i][j-1], d[i-1][j-1]) + 1;
                else d[i][j] = 1;
                ++r[d[i][j]];
            }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            r[i] += r[j];
}
 
void write()
{
    ofstream fout ("custi.out");
    for (int i = 1; i <= n; ++i)
        fout << r[i] << "\n";
    fout.close();
}
 
int main()
{
    read();
    magic();
    write();
    return 0;
}
