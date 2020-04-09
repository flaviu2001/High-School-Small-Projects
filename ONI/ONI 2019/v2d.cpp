#include <bits/stdc++.h>

using namespace std;

const int inf = 2147483647;
int n, Q, test, m[2][505][505], M[505][505], v[505][505];

void pd(int pi, int pj, int o)
{
    int idir = 2*(1-pi)-1, jdir = 2*(1-pj)-1;
    for (int i = (n-1)*pi; i != (n-1)*(1-pi)+idir; i += idir)
        for (int j = (n-1)*pj; j != (n-1)*(1-pj)+jdir; j += jdir){
            int r = -inf;
            if(i != (n-1)*pi)
                r = v[i-idir][j];
            if(j != (n-1)*pj)
                r = max(r, v[i][j-jdir]);
            M[i][j] = max(r-i*idir-j*jdir, M[i][j]);
            v[i][j] = max(r, m[o][i][j]+i*idir+j*jdir);
        }
}

int main()
{
    ifstream fin ("v2d.in");
    ofstream fout ("v2d.out");
    fin >> n >> test >> Q; ++test;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> m[1][i][j];
    for (int t = 2; t <= test; ++t){
        int o = (t-1)%2, u = t%2;
        memset(M, 0, sizeof(M));
        memset(v, 0, sizeof(v));
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                pd(i, j, o);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m[u][i][j] = t+(m[o][i][j] + M[i][j]*(t-1))%Q;
    }
    int S = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            S = (S+m[test%2][i][j])%Q;
    fout << S << "\n";
    return 0;
}

