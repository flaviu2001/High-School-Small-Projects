#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "revolutie";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, nmax = 130;

int n, v[nmax][nmax], pairu[nmax], pairv[nmax], dist[nmax];
vector<int> adj[nmax];

bool bfs()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
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

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            fin >> v[i][j];
            if(v[i][j])
                adj[i].push_back(j);
        }
    while(bfs())
        for (int i = 1; i <= n; ++i)
            if(pairu[i] == 0)
                dfs(i);
    fout << n-1 << "\n";
    for (int t = 1; t < n; ++t){
        int now;
        for (int i = t; i <= n; ++i)
            if(pairu[i] == t)
                now = i;
        fout << "C " << t << " " << pairu[t] << "\n";
        swap(pairu[t], pairu[now]);
    }
    return 0;
}
