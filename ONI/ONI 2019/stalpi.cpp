#include <bits/stdc++.h>

using namespace std;

int n, E, v[55], pd[52][10005], lo, hi, m, ans;

int check(int dmax)
{
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= v[n]; ++j)
            pd[i][j] = E+1;
    for (int i = 1; i <= min(v[n]-1, dmax); ++i)
        pd[1][i] = abs(i-v[1]);
    for (int i = 2; i < n; ++i){
        deque<int> d;
        for (int j = i; j < v[n]; ++j){
            if(!d.empty() && j-d.front() == dmax)
                d.pop_front();
            while(!d.empty() && pd[i-1][j] <= pd[i-1][d.back()])
                d.pop_back();
            d.push_back(j);
            pd[i][j+1] = pd[i-1][d.front()] + abs(j+1-v[i]);
            pd[i][j+1] = min(pd[i][j+1], E+1);
        }
    }
    int mn = E+1;
    for (int i = v[n]-dmax; i < v[n]; ++i)
        mn = min(mn, pd[n-1][i]);
    return mn;
}

int main()
{
    ifstream fin ("stalpi2.in");
    ofstream fout ("stalpi2.out");
    fin >> n >> E;--n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        hi = max(hi, v[i]-v[i-1]);
    }
    lo = (v[n]-1)/n+1;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
        if(check(m) <= E){
            ans = m;
            hi = m-1;
        }else lo = m+1;
    fout << ans << "\n";
    return 0;
}

