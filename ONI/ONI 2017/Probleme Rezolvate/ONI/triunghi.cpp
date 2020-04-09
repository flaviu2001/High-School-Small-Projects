#include <fstream>

using namespace std;

int n, v[1005][1005], s[1005][1005], pd[1005][1005][2];

int min(int x, int y)
{
    return x < y ? x : y;
}

void precalculare()
{
    for (int j = 1; j <= n-1; ++j)
        for (int i = n-1, d = 2; i >= j; --i, ++d)
            pd[j][d][0] = pd[j][d-1][0] + v[i][j] + v[i+1][j+1];
    for (int j = 1; j <= n-1; ++j)
        for (int i = n-1, d = 2; i >= j; --i, ++d)
            pd[j][d][0] *= d-1;
    for (int j = 1; j <= n-1; ++j){
        int x = 0;
        for (int i = n-1, d = 2; i >= j; --i, ++d)
            x += v[i][j] + v[i+1][j],
            pd[j][d][0] += x;
    }

    for (int j = n; j >= 2; --j){
        for  (int i = n-1, d = 1; d < j; --i, ++d)
            pd[j-d][d+1][1] = pd[j-d+1][d][1] + v[i][j-d] + v[i+1][j-d];
    }
    for (int j = n; j >= 2; --j)
        for  (int i = n-1, d = 1; d < j; --i, ++d)
            pd[j-d][d+1][1] *= d;
    for (int j = n; j >= 2; --j){
        int x = 0;
        for  (int i = n-1, d = 1; d < j; --i, ++d)
            x += v[i][j-d] + v[i+1][j+1-d],
            pd[j-d][d+1][1] += x;
    }
}

int triunghi(int j1, int i1)
{
    if(s[j1][i1] != -1)
        return s[j1][i1];
    if(i1 == 1 || j1 == n)
        return 0;
    if(s[j1+1][i1-1] == -1)
        s[j1+1][i1-1] = triunghi(j1+1, i1-1);
    if(s[j1][i1-1] == -1)
        s[j1][i1-1] = triunghi(j1, i1-1);
    s[j1][i1] = min(s[j1+1][i1-1] + pd[j1][i1][0], s[j1][i1-1] + pd[j1][i1][1]);
    return s[j1][i1];
}

int main()
{
    ifstream fin ("triunghi3.in");
    ofstream fout ("triunghi3.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            fin >> v[i][j];
    for (int i = 0; i < 1005; ++i)
        for (int j = 0; j < 1005; ++j)
            s[i][j] = -1;
    precalculare();
    fout << triunghi(1, n) << "\n";
    fin.close();
    fout.close();
    return 0;
}

