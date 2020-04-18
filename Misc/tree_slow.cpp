#include <bits/stdc++.h>
#define ff first
#define ss second
#define int long long

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647, M = 1000000007;

void dfs(int nod, int prev, vector<int> &depth, vector< unordered_set<int> > &common, vector< vector<int> > &graph)
{
    if (prev == -1)
        depth[nod] = 1;
    else depth[nod] = depth[prev]+1;
    common[nod].insert(nod);
    for (auto x : graph[nod])
        if (x != prev){
            dfs(x, nod, depth, common, graph);
            for (auto y : common[x])
                common[nod].insert(y);
        }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    int n;
    cin >> n;
    vector< vector<int> > graph(n);
    for (int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> depth(n);
    vector< unordered_set<int> > common(n);
    dfs(0, -1, depth, common, graph);
    vector< vector<int> > lca(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            int ans = 0, mx = 0;
            for (int k = 0; k < n; ++k)
                if (common[k].find(i) != common[k].end() && common[k].find(j) != common[k].end() && mx < depth[k]){
                    mx = depth[k];
                    ans = k;
                }
            lca[i][j] = ans;
        }
    int sum = 0;
    for (int c = 1; c < (1<<n); ++c){
        int now = -1;
        for (int i = 0; i < n; ++i)
            if (c&(1<<i)){
                if (now == -1)
                    now = i;
                else now = lca[now][i];
            }
        sum = (sum + depth[now])%M;
    }
    cout << sum << "\n";
    return 0;
}
