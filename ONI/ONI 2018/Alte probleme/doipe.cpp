#include <bits/stdc++.h>

using namespace std;

const int nmax = 2005, M = 29997;
int pd[2][nmax], test;
char c[nmax];

int main()
{
    ifstream fin ("doipe.in");
    ofstream fout ("doipe.out");
    fin >> test;
    while(test--){
        int n;
        fin >> n >> (c+1);
        memset(pd, 0, sizeof(pd));
        pd[1][1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j){
                if(c[i-1] == '<')
                    pd[i%2][j] = (pd[1-i%2][j-1]+pd[i%2][j-1])%M;
                else pd[i%2][j] = (pd[1-i%2][i-1]-pd[1-i%2][j-1]+pd[i%2][j-1])%M;
                if(pd[i%2][j] < 0)
                    pd[i%2][j] = M+pd[i%2][j]%M;
            }
        fout << pd[n%2][n] << "\n";
    }
    return 0;
}

