#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "cover";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1000006, nmax2 = 60004;

int n, m, c[nmax], mx, r[nmax], pd[nmax], last;
bool start[nmax];
pi v[nmax2];
deque<int> d;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
        fin >> c[i];
    for (int i = 1; i <= n; ++i){
        fin >> v[i].ff >> v[i].ss;
        last = max(last, v[i].ff);
        start[v[i].ff] = 1;
        r[v[i].ss] = max(r[v[i].ss], v[i].ff);
    }
    sort(v+1, v+n+1);
    int ans = inf;
    d.push_back(0);
    for (int t = 1; t <= m; ++t){
        while(!d.empty() && d.front() < mx)
            d.pop_front();
        pd[t] = c[t] + pd[d.front()];
        if(!start[t])
            pd[t] = min(pd[t], pd[t-1]);
        while(!d.empty() && pd[d.back()] >= pd[t])
            d.pop_back();
        d.push_back(t);
        mx = max(mx, r[t]);
        if(t >= last)
            ans = min(ans, pd[t]);
    }
    fout << ans << "\n";
    return 0;
}
