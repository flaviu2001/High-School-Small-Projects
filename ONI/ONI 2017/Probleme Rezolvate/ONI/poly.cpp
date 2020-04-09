#include <fstream>
#define M 30103

using namespace std;

int t, factorial[2005];

void gcd(int &x, int &y, int a, int b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        int aux = x;
        x = y;
        y = aux - y * (a/b);
    }
}

int combinari_modificat(int n)
{
    if(n < 2)
        return 1;
    int aux, x1, x2, sol = factorial[2*n];
    gcd(x1, aux, factorial[n+1], M);
    gcd(x2, aux, factorial[n], M);
    if(x1 < 0)
        x1 = M + x1%M;
    if(x2 < 0)
        x2 = M + x2%M;
    sol *= x1;
    sol %= M;
    sol *= x2;
    sol %= M;
    return sol;
}

int main()
{
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i < 2005; ++i)
        factorial[i] = (factorial[i-1] * i) % M;
    ifstream fin ("poly.in");
    ofstream fout ("poly.out");
    fin >> t;
    fout << combinari_modificat(t) << "\n";
    fin.close();
    fout.close();
    return 0;
}

