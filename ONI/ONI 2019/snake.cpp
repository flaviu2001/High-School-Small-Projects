#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;

const string file = "snake";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, nmax = 300005;

int n, m, l, v[105][105], p, pairu[nmax], pairv[nmax], dist[nmax];
vector<pi> can[105*105], lst;
vector<int> g[105*105];
int mp[105][105];
pi guys[105*105];
bool over;

bool check(pi x)
{
    return x.ff >= 1 && x.ff <= n && x.ss >= 1 && x.ss <= m && v[x.ff][x.ss] == 0;
}

int dst(pi x, pi y)
{
    return abs(x.ff-y.ff) + abs(x.ss-y.ss);
}

bool bfs()
{
    queue<int> q;
    for (int i = 1; i <= l/2; ++i)
        if(pairu[i] == 0){
            q.push(i);
            dist[i] = 0;
        }else dist[i] = inf;
    dist[0] = inf;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        if(dist[k] < dist[0])
            for (vector<int>::iterator it = g[k].begin(); it != g[k].end(); ++it)
                if(dist[pairv[*it]] == inf){
                    dist[pairv[*it]] = dist[k]+1;
                    q.push(pairv[*it]);
                }
    }
    return dist[0] != inf;
}

bool dfs(int x)
{
    if(x != 0){
        for (vector<int>::iterator it = g[x].begin(); it != g[x].end(); ++it)
            if(dist[pairv[*it]] == dist[x]+1 && dfs(pairv[*it])){
                pairu[x] = *it;
                pairv[*it] = x;
                return true;
            }
        return false;
    }
    return true;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> l;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            fin >> v[i][j];
            if(v[i][j] > 0)
                guys[v[i][j]] = {i, j};
        }
    ++p;
    lst.push_back({0, 0});
    for (int i = 2; i <= l; i += 2)
        for (int d = 0; d < 4; ++d){
            pi now = guys[i-1];
            now.ff += dx[d];
            now.ss += dy[d];
            if(!check(now))
                continue;
            if(i+1 <= l && dst(now, guys[i+1]) == 1){
                can[i].push_back(now);
                if(mp[now.ff][now.ss] == 0){
                    lst.push_back(now);
                    mp[now.ff][now.ss] = p++;
                }
                g[i/2].push_back(mp[now.ff][now.ss]);
            }
        }
    int matches = 0;
    while(bfs())
        for (int i = 1; i <= l/2; ++i)
            if(pairu[i] == 0 && dfs(i))
                ++matches;
    for (int i = 1; i <= l/2; ++i)
        if(pairu[i] != 0)
            v[lst[pairu[i]].ff][lst[pairu[i]].ss] = i*2;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            fout << v[i][j] << " ";
        fout << "\n";
    }
    return 0;
}
