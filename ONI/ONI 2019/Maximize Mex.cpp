#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 5005;

int n, M, test, p[nmax], m[nmax], r[nmax], ans[nmax], pairu[nmax], pairv[nmax], dist[nmax], matching;
bool online[nmax];
vector<int> adj[nmax];

bool bfs(int lim)
{
    queue<int> q;
    for (int i = 1; i <= lim; ++i)
        if(pairu[i] == 0){
            dist[i] = 0;
            q.push(i);
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

bool cuplaj(int lim)
{
    while(bfs(lim))
        for (int i = 1; i <= lim; ++i)
            if(pairu[i] == 0 && dfs(i))
                ++matching;
    return matching == lim;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> p[i], ++p[i];
    for (int i = 1; i <= n; ++i)
        cin >> m[i];
    memset(online, 1, sizeof(online));
    cin >> test;
    for (int i = 1; i <= test; ++i){
        cin >> r[i];
        online[r[i]] = 0;
    }
    for (int i = 1; i <= n; ++i)
        if(online[i])
            adj[p[i]].push_back(m[i]);
    int curr = 0;
    while(curr < M && cuplaj(curr+1))
        ++curr;
    ans[test+1] = curr;
    for (int i = test; i >= 1; --i){
        adj[p[r[i]]].push_back(m[r[i]]);
        while(curr < M && cuplaj(curr+1))
            ++curr;
        ans[i] = curr;
    }
    for (int i = 2; i <= test+1; ++i)
        cout << ans[i] << "\n";
    return 0;
}
