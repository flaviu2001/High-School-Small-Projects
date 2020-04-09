#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "hamilton";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 20;

int n, m, pd[(1<<nmax)+5][nmax], d[nmax][nmax];
vector<pi> v[nmax];

int bkt(int c, int last)
{
    if(pd[c][last] != 0)
        return pd[c][last];
    if(c == (1<<n)-1){
        if(d[last][0] == 0)
            return pd[c][last] = inf;
        return pd[c][last] = d[last][0];
    }
    int ans = inf;
    for (auto x : v[last])
        if((c&(1<<x.ff)) == 0){
            int now = bkt(c|(1<<x.ff), x.ff);
            if(now != inf)
                ans = min(ans, now+x.ss);
        }
    return pd[c][last] = ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, c;
        fin >> x >> y >> c;
        v[x].push_back({y, c});
        d[x][y] = c;
    }
    bkt(1, 0);
    int mn = pd[1][0];
    if(mn == inf)
        fout << "Nu exista solutie\n";
    else fout << mn << "\n";
    return 0;
}
