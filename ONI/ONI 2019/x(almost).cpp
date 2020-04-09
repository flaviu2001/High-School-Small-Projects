#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int nmax = 1000006;
int urm[nmax], u[nmax], u2[nmax], n, m, k, test;
string v, v2, c;

int pal(int a, int b)
{
    int lo = 1, hi = min(m, min(a, n-b-1)), mid, ans = 0;
    for (mid = (lo+hi)/2; lo <= hi; mid = (lo+hi)/2)
        if(u[b+mid] >= mid && u2[n-a-1+mid] >= mid){
            ans = mid;
            lo = mid+1;
        }else hi = mid-1;
    return ans;
}

int main()
{
    ifstream fin ("x.in");
    ofstream fout ("x.out");
    fin >> n >> m >> test >> v >> c; v2 = v;
    reverse(v2.begin(), v2.end());
    urm[0] = 0;
    for (int i = 1; i < m; ++i){
        while(k > 0 && c[k] != c[i])
            k = urm[k-1];
        if(c[k] == c[i])
            ++k;
        urm[i] = k;
    }
    k = 0;
    for (int i = 0; i < n; ++i){
        while(k > 0 && c[k] != v[i])
            k = urm[k-1];
        if(c[k] == v[i])
            ++k;
        u[i] = k;
    }
    k = 0;
    for (int i = 0; i < n; ++i){
        while(k > 0 && c[k] != v2[i])
            k = urm[k-1];
        if(c[k] == v2[i])
            ++k;
        u2[i] = k;
    }
    while(test--){
        int x, y;
        fin >> x >> y;--x;--y;
        fout << pal(x, y) << "\n";
    }
    return 0;
}
