#include <bits/stdc++.h>

using namespace std;

short pd[205][205][400];
int sz[205][205], n, k;

void add(short c[], short a[], int &szc, int &sza)
{
    if(sza == 0){
        sza = 1;
        a[0] = 0;
        return;
    }
    int p = 0, t = 0;
    while(p < sza){
        c[p] += a[p]+t;
        t = c[p]/10;
        c[p] %= 10;
        ++p;
    }
    szc = max(szc, p);
    while(t){
        c[p] += t;
        t = c[p]/10;
        c[p] %= 10;
        ++p;
        szc = max(szc, p);
    }
}

void mult(short c[], short a[], int x, int &szc, int &sza)
{
    short b[4] = {0}, szb = 0;
    while(x != 0){
        b[szb] = x%10;
        x /= 10;
        ++szb;
    }
    if(sza == 0){
        sza = 1;
        a[0] = 0;
        c[0] = 0;
        szc = 1;
        return;
    }
    szc = sza+szb-1;
    for (int i = 0; i < sza; ++i)
        for (int j = 0; j < szb; ++j)
            c[i+j] += a[i]*b[j];
    int t = 0;
    for (int i = 0; i < szc; ++i){
        c[i] += t;
        t = c[i]/10;
        c[i] %= 10;
    }
    if(t){
        c[szc] = t;
        ++szc;
    }
}

int main()
{
    ifstream fin ("perm.in");
    ofstream fout ("perm.out");
    fin >> n >> k;
    pd[1][1][0] = 1;
    sz[1][1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= k && j <= i; ++j){
            mult(pd[i][j], pd[i-1][j], i-1, sz[i][j], sz[i-1][j]);
            add(pd[i][j], pd[i-1][j-1], sz[i][j], sz[i-1][j-1]);
            //pd[i][j] = pd[i-1][j-1]+pd[i-1][j]*(i-1);
        }
    for (int i = sz[n][k]-1; i >= 0; --i)
        fout << pd[n][k][i];
    return 0;
}

