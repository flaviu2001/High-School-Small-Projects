#include <bits/stdc++.h>

using namespace std;

const int nmax = 1005;
int n, lin[nmax][nmax], col[nmax][nmax], lg2[nmax];
short rmq[10][nmax][nmax], rmq2[10][nmax];
char v[nmax][nmax];

bool check(int x, int y, int m)
{
    if(m == 0)
        return true;
    int p = y-m;
    int r = y+m;
    int lg = lg2[r-p];
    int rm1 = min(rmq[lg][x][p], rmq[lg][x][r-(1<<lg)]);
    p = x-m;
    r = x+m;
    lg = lg2[r-p];
    int rm2 = min(rmq2[lg][p], rmq2[lg][r-(1<<lg)]);
    return min(rm1, rm2) >= m+1;
}

int main()
{
    ifstream fin ("pscpld2d.in");
    ofstream fout ("pscpld2d.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> (v[i]+1);
    for (int j = 1; j <= n; ++j){
        int c = 1, r = -1, rad = 0;
        for (int i = 1; i <= n; ++i){
            if(i <= r)
                rad = min(col[2*c-i][j], r-i);
            else rad = 0;
            while(i+rad <= n && i-rad >= 1 && v[i-rad][j] == v[i+rad][j])
                ++rad;
            col[i][j] = rad;
            if(i+rad-1 > r){
                r = i+rad-1;
                c = i;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        int c = 1, r = -1, rad = 0;
        for (int j = 1; j <= n; ++j){
            if(j <= r)
                rad = min(lin[i][2*c-j], r-j);
            else rad = 0;
            while(j-rad >= 1 && j+rad <= n && v[i][j-rad] == v[i][j+rad])
                ++rad;
            lin[i][j] = rad;
            if(j+rad-1 > r){
                c = j;
                r = j+rad-1;
            }
        }
    }
    long long sol = 0;
    lg2[1] = 0;
    for (int i = 2; i <= n; ++i)
        lg2[i] = lg2[i/2]+1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j < n; ++j)
            rmq[0][i][j] = min(col[i][j], col[i][j+1]);
        for (int t = 1; (1<<t) <= n; ++t)
            for (int j = 1; j+(1<<t) <= n; ++j)
                rmq[t][i][j] = min(rmq[t-1][i][j], rmq[t-1][i][j+(1<<(t-1))]);
    }
    for (int j = 1; j <= n; ++j){
        for (int i = 1; i < n; ++i)
            rmq2[0][i] = min(lin[i][j], lin[i+1][j]);
        for (int t = 1; (1<<t) <= n; ++t)
            for (int i= 1; i+(1<<t) <= n; ++i)
                rmq2[t][i] = min(rmq2[t-1][i], rmq2[t-1][i+(1<<(t-1))]);
        for (int i = 1; i <= n; ++i){
            int st = 0, dr = min(j-1, i-1), m, ans=0;
            dr = min(dr, min(n-j, n-i));
            for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
                if(check(i, j, m)){
                    ans = m;
                    st = m+1;
                }else dr = m-1;
            sol += ans+1;
        }
    }
    fout << sol << "\n";
    return 0;
}

