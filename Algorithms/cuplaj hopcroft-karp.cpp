#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "cuplaj";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 10005;

int n, m, e, pairu[nmax], pairv[nmax], dist[nmax];
vector<int> v[nmax];

bool bfs()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if(pairu[i] == 0){
            dist[i] = 0;
            q.push(i);
        }else dist[i] = inf;
    dist[0] = inf;
    while(!q.empty()){
        if(dist[0] != inf)
            return true;
        int nod = q.front();
        q.pop();
        for (auto x : v[nod])
            if(dist[pairv[x]] == inf){
                dist[pairv[x]] = dist[nod]+1;
                q.push(pairv[x]);
            }
    }
    return false;
}

bool dfs(int x)
{
    if(x == 0)
        return true;
    for (auto y : v[x])
        if(dist[pairv[y]] == dist[x]+1 && dfs(pairv[y])){
            pairu[x] = y;
            pairv[y] = x;
            return true;
        }
    return false;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> e;
    for (int i = 1; i <= e; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
    }
    int matching = 0;
    while(bfs())
        for (int i = 1; i <= n; ++i)
            if(pairu[i] == 0 && dfs(i))
                ++matching;
    fout << matching << "\n";
    for (int i = 1; i <= n; ++i)
        if(pairu[i] != 0)
            fout << i << " " << pairu[i] << "\n";
    return 0;
}
