#include <bits/stdc++.h>

using namespace std;

const int M = 9973;
int n, m, sol, fact[10005], f[10];

void gcd(int &x, int &y, int a, int b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        int aux = x;
        x = y;
        y = aux - (a/b)*y;
    }
}

int invers_modular(int x, int y)
{
    int a, b;
    gcd(a, b, x, y);
    if(a < 0)
        return y + a%y;
    return a;
}

int comb(int N, int K)
{
    int sol = fact[N];
    sol = (sol*invers_modular(fact[K], M))%M;
    sol = (sol*invers_modular(fact[N-K], M))%M;
    return sol;
}

void bkt(int k, int val, int last = 2) //i actually think it's more of a pd but fuck it, it's recursive i'll call bkt
{
    if(val == 1){
        if(k > n)
            return;
        sol += comb(n, k-1)%M;
        sol %= M;
        return;
    }
    for (int i = last; i <= 9; ++i)
        if(val%i == 0){
            ++f[i];
            bkt(k+1, val/i);
            --f[i];
        }
}

int main()
{
    ifstream fin ("numere6.in");
    ofstream fout ("numere6.out");
    fin >> n >> m;
    fact[0] = 1;
    for (int i = 1; i < 10005; ++i)
        fact[i] = (fact[i-1]*i)%M;
    bkt(1, m);
    fout << sol;
    return 0;
}

