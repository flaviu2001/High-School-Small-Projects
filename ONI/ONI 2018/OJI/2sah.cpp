#include <fstream>
#include <cstring>
#define M 100003

using namespace std;

long long test, n, m, mat[4][4], sol[4][4];

long long cerinta1(long long x, long long p)
{
    long long t = x, ans = 1;
    while(p){
        if(p%2==0){
            t *= t;
            t %= M;
            p /= 2;
        }else{
            ans *= t;
            ans %= M;
            --p;
        }
    }
    return ans;
}

void mult(long long a[][4], long long b[][4], long long c[][4]) {
    long long i, j, k;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            for (k = 0; k < 3; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % M;
}

void lg_power(long long p, long long mm[][4]) {
    long long c[4][4], aux[4][4], i;
    memcpy(c, mat, sizeof(mat));
    mm[0][0] = 1; mm[1][1] = 1; mm[2][2] = 1;
    for (i = 0; (1 << i) <= p; ++i) {
        if (p & (1 << i)) {
            memset(aux, 0, sizeof(aux));
            mult(mm, c, aux);
            memcpy(mm, aux, sizeof(aux));
        }
        memset(aux, 0, sizeof(aux));
        mult(c, c, aux);
        memcpy(c, aux, sizeof(c));
    }
}

long long cerinta2()
{
    long long p = n-m+1;
    if(p == 2)
        return 4;
    if(p == 1)
        return 2;
    if(p == 0)
        return 1;
    mat[0][1] = 1;
    mat[1][2] = 1;
    mat[2][0] = 1;
    mat[2][1] = 1;
    mat[2][2] = 1;
    lg_power(p, sol);
    return sol[2][2];
}

int main()
{
    ifstream fin ("2sah.in");
    ofstream fout ("2sah.out");
    fin >> test >> n >> m;
    if(test == 1)
        fout << cerinta1(3, m-1) << "\n";
    else fout << cerinta2() << "\n";
    return 0;
}

