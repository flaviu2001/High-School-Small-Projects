#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int n, m, f[nmax], go[nmax];
ifstream fin ("romania.in");
ofstream fout ("romania.out");

void solve(int t)
{
    if(f[go[t]])
        solve(go[t]);
    go[t] = go[go[t]];
    fout << t << " " << go[t] << "\n";
    --f[t];
    if(f[t])
        solve(t);
}

int main()
{
    fin >> m >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        ++f[x];
    }
    for (int i = 1; i < m; ++i)
        go[i] = i+1;
    go[m] = 1;
    for (int i = 1; i <= m; ++i)
        if(f[i])
            solve(i);
    return 0;
}
