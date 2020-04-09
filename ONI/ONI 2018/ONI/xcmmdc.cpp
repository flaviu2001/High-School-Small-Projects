#include <bits/stdc++.h>

using namespace std;

int v[1005][1005], r[13][1005][1005], n, m, test, k, sol[1005];

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int gcdMatrix(int x, int y, int sz)
{
    int lg2 = 1;
    for (; 1<<lg2 <= sz; ++lg2);
    --lg2;
    if(sz == 1)
        return v[x][y];
    return gcd(r[lg2][x][y], gcd(r[lg2][x+sz-(1<<lg2)][y], gcd(r[lg2][x][y+sz-(1<<lg2)], r[lg2][x+sz-(1<<lg2)][y+sz-(1<<lg2)])));
}

int Binary(int x, int y, int ok)
{
    int lo = 1, hi = min(n-x+1, m-y+1), m, ans = -1;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2){
        int gcd = gcdMatrix(x, y, m);
        if(gcd == k)
            ans = m;
        if(gcd < k+ok)
            hi = m-1;
        else lo = m+1;
    }
    return ans;
}

int main()
{
    ifstream fin ("xcmmdc.in");
    ofstream fout ("xcmmdc.out");
    fin >> n >> m >> k >> test;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            fin >> v[i][j];
            r[0][i][j] = v[i][j];
        }
    int lg2 = 1;
    for (; 1<<lg2 <= min(n, m); ++lg2);
    --lg2;
    for (int t = 1; t <= lg2; ++t)
        for (int i = 1; i <= n-(1<<t)+1; ++i)
            for (int j = 1; j <= m-(1<<t)+1; ++j)
                r[t][i][j] = gcd(r[t-1][i][j], gcd(r[t-1][i+(1<<(t-1))][j], gcd(r[t-1][i][j+(1<<(t-1))], r[t-1][i+(1<<(t-1))][j+(1<<(t-1))])));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int lo = Binary(i, j, 1), hi = Binary(i, j, 0);
            if(lo != -1){
                ++sol[lo];
                --sol[hi+1];
            }
        }
    for (int i = 2; i <= min(n, m); ++i)
        sol[i] += sol[i-1];
    while(test--){
        int x;
        fin >> x;
        fout << sol[x] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
