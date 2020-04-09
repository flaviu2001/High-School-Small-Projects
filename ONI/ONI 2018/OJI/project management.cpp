#include <bits/stdc++.h>

using namespace std;

const int nmax = 105;
int n, c[nmax], mxdown[nmax], sol1[nmax], sol2[nmax];
vector<int> v[nmax], vt[nmax];
bool good[nmax];

int df(int x)
{
    if(mxdown[x] != -1)
        return mxdown[x];
    int mx = 0;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        mx = max(mx, df(*it));
    mxdown[x] = mx+c[x];
    return mxdown[x];
}

int overhead(int x)
{
    if(sol1[x] != -1)
        return sol1[x];
    int mx = 0;
    for (vector<int>::iterator it = vt[x].begin(); it != vt[x].end(); ++it)
        mx = max(mx, overhead(*it));
    sol1[x] = mx+c[x];
    return sol1[x];
}

void i_dont_even_know_anymore(int x, int val)
{
    sol2[x] = min(sol2[x], val-c[x]);
    for (vector<int>::iterator it = vt[x].begin(); it != vt[x].end(); ++it)
        if(sol2[*it] >= val-c[x]-c[*it])
            i_dont_even_know_anymore(*it, val-c[x]);
}

int main()
{
    ifstream fin ("pm2.in");
    ofstream fout ("pm2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> c[i];
        sol2[i] = 2000000000;
    }
    for (int i = 1; i <= n; ++i){
        int m;
        fin >> m;
        if(m == 0)
            good[i] = 1;
        for (int j = 1; j <= m; ++j){
            int x;
            fin >> x;
            v[x].push_back(i);
            vt[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i)
        if(v[i].size() == 0)
            good[i] = 1;
    memset(mxdown, -1, sizeof(mxdown));
    memset(sol1, -1, sizeof(sol1));
    int mx = 0;
    for (int i = 1; i <= n; ++i)
        mx = max(mx, df(i));
    for (int i = 1; i <= n; ++i)
        overhead(i);
    for (int i = 1; i <= n; ++i)
        if(good[i])
            i_dont_even_know_anymore(i, mx);
    fout << mx << "\n";
    for (int i = 1; i <= n; ++i)
        fout << sol1[i]-c[i] << " " << sol2[i] << "\n";
    return 0;
}

