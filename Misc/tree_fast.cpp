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
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647, M = 1000000007;

void add(int &a, int b)
{
    a = (a+b)%M;
}

void sub(int &a, int b)
{
    a = (a-b+M)%M;
}

int dfs(int nod, int prev, vector<int> &depth, vector< vector<int> > &graph, vector<int> &subtree, vector<int> &power2)
{
    if (prev == -1)
        depth[nod] = 1;
    else depth[nod] = depth[prev]+1;
    subtree[nod] = 1;
    int ans = 0, now = 0;
    for (auto son : graph[nod])
        if (son != prev){
            add(ans, dfs(son, nod, depth, graph, subtree, power2));
            int son_size = subtree[son];
            subtree[nod] += son_size;
            sub(now, power2[son_size]-1);
        }
    add(now, power2[subtree[nod]]-1);
    add(ans, (1ll*depth[nod]*now)%M);
    return ans;
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
    vector<int> depth(n), subtree(n), power2(n+1);

    power2[0] = 1;
    for (int i = 1; i <= n; ++i)
        power2[i] = (2*power2[i-1])%M;

    for (int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << dfs(0, -1, depth, graph, subtree, power2) << "\n";
    return 0;
}
