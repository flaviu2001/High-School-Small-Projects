#include <bits/stdc++.h>
#define M 666013

using namespace std;

int n, mat[3][3], sol[3][3];

void mult(int a[3][3], int b[3][3], int c[3][3])
{
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] = (c[i][j] + 1LL*a[i][k]*b[k][j])%M;
}

void lgpow(int p, int m[3][3])
{
    int c[3][3], aux[3][3];
    memcpy(c, mat, sizeof(mat));
    m[0][0] = m[1][1] = 1;
    for (int i = 0; (1<<i) <= p; ++i){
        if(p&(1<<i)){
            memset(aux, 0, sizeof(aux));
            mult(m, c, aux);
            memcpy(m, aux, sizeof(aux));
        }
        memset(aux, 0, sizeof(aux));
        mult(c, c, aux);
        memcpy(c, aux, sizeof(c));
    }
}

int main()
{
    ifstream fin ("kfib.in");
    ofstream fout ("kfib.out");
    fin >> n;
    mat[0][0] = 0;
    mat[1][1] = 1;
    mat[1][0] = 1;
    mat[0][1] = 1;
    lgpow(n-1, sol);
    fout << sol[1][1];
    return 0;
}
