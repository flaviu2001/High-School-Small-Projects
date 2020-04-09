#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "deminare";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int test, n, m, d, pr[505][505];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test >> n >> m >> d;
    for (int i = 1; i <= d; ++i){
        int x, y;
        fin >> x >> y;
        pr[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            pr[i][j] += pr[i-1][j]+pr[i][j-1]-pr[i-1][j-1];
    if(test == 1){
        int mx = 0;
        vector<int> sol;
        for (int i = 1; i <= n; ++i)
            if(pr[i][m]-pr[i-1][m] > mx){
                sol.clear();
                sol.push_back(i);
                mx = pr[i][m]-pr[i-1][m];
            }else if (pr[i][m]-pr[i-1][m] == mx)
                sol.push_back(i);
        for (auto x : sol)
            fout << x << " ";
        fout << "\n";
    }else{
        int mn = inf;
        for (int t = 1; t <= min(d, n); ++t)
            if(d%t == 0 && d/t <= m){
                int l = t, c = d/t;
                for (int i = l; i <= n; ++i)
                    for (int j = c; j <= m; ++j)
                        mn = min(mn, d-(pr[i][j]-pr[i-l][j]-pr[i][j-c]+pr[i-l][j-c]));
            }
        fout << (mn == inf ? -1 : mn) << "\n";
    }
    return 0;
}
