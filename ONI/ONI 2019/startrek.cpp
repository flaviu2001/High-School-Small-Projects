#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int nmax = 100005;
int n, p, q, m, first[nmax], last[nmax], sol[nmax];
pair<int, int> v[nmax];

int main()
{
    ifstream fin ("startrek.in");
    ofstream fout ("startrek.out");
    fin >> n >> p >> q >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        if(first[y] == 0)
            first[y] = last[y] = x;
        else{
            first[y] = min(first[y], x);
            last[y] = max(last[y], x);
        }
    }
    for (int i = 1; i <= n; ++i)
        if(first[i] == 0)
            first[i] = 2000000;
    int ans = 1;
    v[1] = {max(p, last[1]), q};
    if(v[1].first+p <= n)
        for (int t = 2; 1; ++t){
            int l = max(v[t-1].first+p, last[t]);
            int r = min(v[t-1].second+q, first[t]+q-1);
            r = min(r, n);
            v[t] = {l, r};
            if(v[t].first+p > n){
                ans = t;
                break;
            }
        }
    fout << ans << "\n";
    int an = ans, pos = n;
    sol[pos] = ans;
    while(an > 1){
        --an;
        int newpos = first[an+1]-1;
        newpos = min(newpos, v[an].second);
        newpos = min(newpos, pos-p);
        pos = newpos;
        sol[pos] = an;
    }
    for (int i = n-1; i >= 1; --i)
        if(sol[i] == 0)
            sol[i] = sol[i+1];
    for (int i = 1; i <= n; ++i)
        fout << sol[i] << " ";
    return 0;
}

