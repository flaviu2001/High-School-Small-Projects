#include <bits/stdc++.h>

using namespace std;

int v[500005], n;

bool majoritar(int x)
{
    int f[500005] = {0}, target = (x+1)/2;
    for (int i = 1; i <= x; ++i){
        ++f[v[i]];
        if(f[v[i]] >= target)
            return true;
    }
    for (int i = x+1; i <= n; ++i){
        --f[v[i-x]];
        ++f[v[i]];
        if(f[v[i]] >= target)
            return true;
    }
    return false;
}

int main()
{
    ifstream fin ("mate.in");
    ofstream fout ("mate.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    int lo = 2, hi = n, m, ans;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
        if(majoritar(m)){
            ans = m;
            lo = m+1;
        }else hi = m-1;
    fout << ans << "\n";
    fin.close();
    fout.close();
    return 0;
}

