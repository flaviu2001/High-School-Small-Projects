#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "traseu4";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, m, v[505][505], pr[505][505];
pi pos[505*505];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            fin >> v[i][j];
            pos[v[i][j]] = {i, j};
        }
    int mx = -1;
    for (int t = n*m; t >= 1; --t){
        int x = pos[t].ff, y = pos[t].ss;
        while(x >= 1 && y <= m){
            ++pr[x][y];
            --x, ++y;
        }
        x = pos[t].ff, y = pos[t].ss;
        int now = 0;
        while(y+1 <= m){
            ++y;
            ++now;
            int rem = min(y-pos[t].ss, n-x);
            int x2 = x+rem+1, y2 = y-rem-1;
            if(pr[x][y]-pr[x2][y2] > 0)
                mx = max(mx, now);
        }
        while(x+1 <= n){
            ++x;
            ++now;
            int rem = min(y-pos[t].ss, n-x);
            int x2 = x+rem+1, y2 = y-rem-1;
            if(pr[x][y]-pr[x2][y2] > 0)
                mx = max(mx, now);
        }
    }
    fout << mx+1 << "\n";
    return 0;
}
