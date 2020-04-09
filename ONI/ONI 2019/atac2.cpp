#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "atac2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100*100, gmax = 10005;

int n, m, N, M, u, t, D[nmax][nmax], c[nmax][nmax], f[nmax][nmax], e[nmax][nmax], prv[nmax], old[nmax], d[nmax], trued[nmax], edge[nmax][nmax], Entry, Exit, flow, cost;
vector<int> v[gmax], r, E;
bool ok[gmax], inq[nmax];

void bfs(int nod)
{
    memset(ok, 0, sizeof(ok));
    queue<int> q;
    q.push(r[nod]);
    ok[r[nod]] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (auto x : v[k])
            if(!ok[x]){
                D[nod][x] = D[nod][k]+1;
                ok[x] = 1;
                q.push(x);
            }
    }
}

void bell()
{
    queue<int> q;
    q.push(Entry);
    memset(inq, 0, sizeof(inq));
    for (int i = 1; i <= n; ++i)
        old[i] = inf;
    old[Entry] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        inq[k] = 0;
        for (auto x : v[k])
            if(c[k][x] && old[k]+e[k][x] < old[x]){
                old[x] = old[k]+e[k][x];
                if(!inq[x])
                    q.push(x);
                inq[x] = 1;
            }
    }
}

int dijkstra()
{
    priority_queue<pi> q;
    q.push({0, Entry});
    for (int i = 1; i <= n; ++i)
        d[i] = inf,
        trued[i] = inf;
    d[Entry] = 0;
    trued[Entry] = 0;
    while(!q.empty()){
        int k = q.top().ss, w = q.top().ff;
        q.pop();
        if(d[k] != -w)
            continue;
        for (auto x : v[k])
            if(f[k][x] < c[k][x] && old[k]-old[x]+d[k]+e[k][x] < d[x]){
                d[x] = old[k]-old[x]+d[k]+e[k][x];
                trued[x] = trued[k]+e[k][x];
                q.push({-d[x], x});
                prv[x] = k;
            }
    }
    for (int i = 1; i <= n; ++i)
        old[i] = trued[i];
    return trued[Exit];
}

void maxflow()
{
    bell();
    int add;
    while((add = dijkstra()) != inf){
        int now = Exit, mn = inf;
        while(now != Entry){
            mn = min(mn, c[prv[now]][now]-f[prv[now]][now]);
            now = prv[now];
        }
        flow += mn;
        cost += add*mn;
        now = Exit;
        while(now != Entry){
            f[prv[now]][now] += mn;
            f[now][prv[now]] -= mn;
            now = prv[now];
        }
    }
}


int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> u >> t;
    for (int i = 1; i <= u; ++i){
        int x;
        fin >> x;
        r.push_back(x);
    }
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (auto x : v[t])
        E.push_back(x);
    for (int i = 0; i < r.size(); ++i)
        bfs(i);
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    N = r.size();
    M = E.size();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j){
            int x = i+2, y = N+j+2;
            c[x][y] = 1;
            v[x].push_back(y);
            v[y].push_back(x);
            e[x][y] = D[i][E[j]];
            e[y][x] = -D[i][E[j]];
        }
    n = N+M+2;
    for (int i = 1; i <= N; ++i){
        v[1].push_back(i+1);
        e[1][i+1] = e[i+1][1] = 0;
        c[1][i+1] = 1;
    }
    for (int i = 1; i <= M; ++i){
        v[i+N+1].push_back(n);
        e[i+N+1][n] = e[n][i+N+1] = 0;
        c[i+N+1][n] = 1;
    }
    Entry = 1;
    Exit = n;
    maxflow();
    fout << cost << "\n";
    return 0;
}
