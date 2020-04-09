#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "dijkstra";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 50005;

int n, m, dist[nmax];
vector<pi> v[nmax];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    while(m--){
        int x, y, c;
        fin >> x >> y >> c;
        v[x].push_back({y, c});
    }
    for (int i = 1; i <= n; ++i)
        dist[i] = inf;
    dist[1] = 0;
    priority_queue< pi, vector<pi>, greater<pi> > q;
    q.push({0, 1});
    while(!q.empty()){
        if(q.top().ff != dist[q.top().ss]){
            q.pop();
            continue;
        }
        int nod = q.top().ss;
        q.pop();
        for (auto x : v[nod])
            if(dist[x.ff] > dist[nod]+x.ss){
                dist[x.ff] = dist[nod]+x.ss;
                q.push({dist[x.ff], x.ff});
            }
    }
    for (int i = 2; i <= n; ++i)
        fout << (dist[i] == inf ? 0 : dist[i]) << " ";
    return 0;
}
