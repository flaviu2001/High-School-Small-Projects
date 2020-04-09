#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "felinare";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

vector<int> adj[10005];
int n, m, e, pairu[10005], pairv[10005], dist[10005], sol, ans[10005];
set<pi> s;

bool bfs()
{
    queue<int> q;
    s.clear();
    for (int i = 1; i <= n; ++i)
        if(pairu[i] == 0){
            dist[i] = 0;
            q.push(i);
            s.insert({i, 1});
        }else
            dist[i] = inf;
    dist[0] = inf;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u] < dist[0])
            for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
                if(dist[pairv[*it]] == inf){
                    dist[pairv[*it]] = dist[u] + 1;
                    q.push(pairv[*it]);
                    s.insert({*it, 2});
                    s.insert({pairv[*it], 1});
                }
    }
    return (dist[0] != inf);
}

bool dfs(int x)
{
    if(x != 0){
        for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); ++it)
            if(dist[pairv[*it]] == dist[x] + 1)
                if(dfs(pairv[*it])){
                    pairv[*it] = x;
                    pairu[x] = *it;
                    return true;
                }
        dist[x] = inf;
        return false;
    }
    return true;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m; sol = 2*n;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        adj[x].push_back(y);
    }
    while(bfs())
        for (int i = 1; i <= n; ++i)
            if(pairu[i] == 0 && dfs(i))
                --sol;
    for (int i = 1; i <= n; ++i)
        ans[i] = 2;
    for (auto x : s)
        if(x.ss == 1)
            ++ans[x.ff];
        else ans[x.ff] -= 2;
    fout << sol << "\n";
    for (int i = 1; i <= n; ++i)
        fout << ans[i] << "\n";
    return 0;
}
