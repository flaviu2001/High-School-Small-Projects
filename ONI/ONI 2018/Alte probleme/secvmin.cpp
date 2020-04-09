#include <bits/stdc++.h>

using namespace std;

int n, m, a[100005], b[100005], u[1000005], p[1000005], d[1000005], l[1000005], ans = 2000000000;

int main()
{
    ifstream fin ("secvmin.in");
    ofstream fout ("secvmin.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i){
        fin >> b[i];
        p[b[i]] = i;
    }
    d[b[1]] = 1;
    l[b[1]] = 1;
    for (int i = 1; i <= n; ++i)
        if(p[a[i]] != 0){
            if(p[a[i]] == 1){
                u[a[i]] = i;
                continue;
            }
            if(u[b[p[a[i]]-1]] == 0){
                u[a[i]] = i;
                l[a[i]] = 1;
                continue;
            }
            d[a[i]] = d[b[p[a[i]]-1]] + i-u[b[p[a[i]]-1]];
            l[a[i]] = l[b[p[a[i]]-1]]+1;
            if(l[a[i]] == m)
                ans = min(ans, d[a[i]]);
            u[a[i]] = i;
        }
    fout << (ans == 2000000000 ? -1 : ans) << "\n";
    fin.close();
    fout.close();
    return 0;
}

