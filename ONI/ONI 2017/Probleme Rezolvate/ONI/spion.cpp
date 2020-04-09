#include <fstream>
#include <cstdio>
#include <cstring>
#define M 100003

using namespace std;

char s[100005];
long long n, test;
long long factorial[100005];

int cerinta1()
{
    int k = 1;
    for (int i = 0; i < n; ++i)
        if(s[i] == 'E')
            ++k;
    return k;
}

void gcd(long long &x, long long &y, long long a, long long b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        long long aux = x;
        x = y;
        y = aux - y * (a/b);
    }
}

long long invers_modular(long long a, long long b)
{
    long long aux, inv;
    gcd(inv, aux, a, b);
    if(inv < 0)
        inv = b + inv%b;
    return inv;
}

long long combinari(long long N, long long K)
{
    if(!N || !K)
        return 1;
    long long sol = factorial[N];
    long long invk = invers_modular(factorial[K], M), invn_k = invers_modular(factorial[N-K], M);
    sol *= invk;
    sol %= M;
    sol *= invn_k;
    sol %= M;
    return sol;
}

long long cerinta2()
{
    factorial[1] = 1;
    for (int i = 2; i < 100005; ++i)
        factorial[i] = (factorial[i-1] * i) % M;
    long long k = 0;
    for (int i = 0; i < n; ++i)
        if(s[i] == 'E')
            ++k;
    return combinari(n, k);
}

int main()
{
    ifstream fin ("spion.in");
    ofstream fout ("spion.out");
    fin >> test; fin.get();
    fin.getline(s, 100005);
    n = strlen(s);
    if(test == 1)
        fout << cerinta1() << "\n";
    else
        fout << cerinta2() << "\n";
    return 0;
}

