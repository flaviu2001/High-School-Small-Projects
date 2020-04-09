#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "tairos";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 1000000007, nmax = 105, dmax = 10005;

int n, k, dist[nmax], pd[dmax], ans;
vector<int> frunze, v[nmax];

void dfs(int x, int pred = 0)
{
    bool frunza = true;
    if(x != 1)
        dist[x] = dist[pred]+1;
    for (auto y : v[x])
        if (y != pred){
            frunza = false;
            dfs(y, x);
        }
    if(frunza)
        frunze.push_back(dist[x]);
}

void dfs2(int x, int pred = 0)
{
    bool frunza = true;
    for (auto y : v[x])
        if (y != pred){
            frunza = false;
            dfs2(y, x);
        }
    if(!frunza && x != 1 && k-dist[x] >= 0)
        ans = (ans+pd[k-dist[x]])%M;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> k;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    pd[0] = 1;
    for (int i = 1; i <= k; ++i)
        for (auto x : frunze)
            if(x <= i)
                pd[i] = (pd[i]+pd[i-x])%M;
    ans = pd[k];
    dfs2(1);
    fout << ans << "\n";
    return 0;
}
