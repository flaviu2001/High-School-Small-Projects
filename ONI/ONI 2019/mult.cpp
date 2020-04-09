#include <bits/stdc++.h>

using namespace std;

const int nmax = 2505, base = 100000000;
int n, k, v[nmax];
int pd[2][2][nmax][nmax], sol[nmax], one[nmax];

void sumabc(int a[], int b[], int c[])
{
    if(b[0] == 0){
        b[0] = 1;
        b[1] = 0;
    }
    if(c[0] == 0){
        c[0] = 1;
        c[1] = 0;
    }
    int t = 0;
    for (int i = 1; i <= max(b[0], c[0]); ++i){
        if(i > b[0])
            b[i] = 0;
        if(i > c[0])
            c[i] = 0;
        a[i] = t+b[i]+c[i];
        t = a[i]/base;
        a[i] %= base;
    }
    a[0] = max(b[0], c[0]);
    if(t)
        a[++a[0]] = t;
}

void sumab(int a[], int b[])
{
    if(a[0] == 0){
        a[0] = 1;
        a[1] = 0;
    }
    if(b[0] == 0){
        b[0] = 1;
        b[1] = 0;
    }
    int t = 0;
    for (int i = 1; i <= max(a[0], b[0]); ++i){
        if(i > a[0])
            a[i] = 0;
        if(i > b[0])
            b[i] = 0;
        a[i] += b[i]+t;
        t = a[i]/base;
        a[i] %= base;
    }
    a[0] = max(a[0], b[0]);
    if(t)
        a[++a[0]] = t;
}

int main()
{
    ifstream fin ("mult.in");
    ofstream fout ("mult.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    one[0] = one[1] = sol[0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < k; ++j)
            sumabc(pd[i%2][0][j], pd[1-(i%2)][0][j], pd[1-(i%2)][1][j]);
        for (int j = 0; j < k; ++j)
            pd[i%2][1][j][0] = 0;
        for (int j = 0; j < k; ++j)
            sumab(pd[i%2][1][(10*j+v[i])%k], pd[i%2][0][j]);
        sumab(pd[i%2][1][v[i]%k], one);
        sumab(sol, pd[i%2][1][0]);
    }
    for (int i = sol[0]; i >= 1; --i){
        for (int j = 1; j < base; j *= 10)
            if(i != sol[0] && j > sol[i])
                fout << "0";
        fout << sol[i];
    }
    fout << "\n";
    return 0;
}

