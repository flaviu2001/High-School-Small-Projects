#include <bits/stdc++.h>

using namespace std;

const int M = 666013;
short v[2005];
int n, pd[2005][2005];

inline int getsz(int x)
{
    return x/M;
}

inline int getnr(int x)
{
    return x%M;
}

inline int combine(int sz, int nr)
{
    return sz*M+nr;
}

int main()
{
    ifstream fin ("maxpal.in");
    ofstream fout ("maxpal.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i < n; ++i){
        pd[i][i] = combine(1, 1);
        if(v[i] == v[i+1])
            pd[i][i+1] = combine(2, 1);
        else
            pd[i][i+1] = combine(1, 2);
    }
    pd[n][n] = combine(1, 1);
    for (int d = 2; d < n; ++d)
        for (int i = 1; i+d <= n; ++i){
            int a = i, b = i+d;
            int sz = getsz(pd[a+1][b]), nr = getnr(pd[a+1][b]);
            if(getsz(pd[a][b-1]) > sz){
                sz = getsz(pd[a][b-1]);
                nr = getnr(pd[a][b-1]);
            }else if (getsz(pd[a][b-1]) == sz){
                nr += getnr(pd[a][b-1]);
                if(getsz(pd[a+1][b-1]) == sz){
                    nr -= getnr(pd[a+1][b-1]);
                    if(nr < 0)
                        nr = M+nr%M;
                }
            }
            if(v[a] == v[b]){
                int newsz = 2+getsz(pd[a+1][b-1]);
                int newnr = getnr(pd[a+1][b-1]);
                if(newsz > sz){
                    sz = newsz;
                    nr = newnr;
                }else if (newsz == sz)
                    nr += newnr;
            }
            pd[a][b] = combine(sz, nr%M);
        }
    fout << getsz(pd[1][n]) << " " << getnr(pd[1][n]) << "\n";
    return 0;
}

