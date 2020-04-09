#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "maxflow";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1005;

int n, m, c[nmax][nmax], f[nmax][nmax], prv[nmax];
vector<int> v[nmax];
bool ok[nmax];

bool bfs()
{
    memset(ok, 0, sizeof(ok));
    queue<int> q;
    q.push(1);
    ok[1] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (auto x : v[k])
            if(!ok[x] && f[k][x] < c[k][x]){
                ok[x] = 1;
                q.push(x);
                prv[x] = k;
                if(x == n)
                    return true;
            }
    }
    return false;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back(y);
        v[y].push_back(x);
        c[x][y] = z;
    }
    int flow = 0;
    while(bfs())
        for (auto nod : v[n])
            if(ok[nod]){
                prv[n] = nod;
                int now = n, mx = inf;
                while(now != 1){
                    mx = min(mx, c[prv[now]][now]-f[prv[now]][now]);
                    now = prv[now];
                }
                flow += mx;
                now = n;
                while(now != 1){
                    f[prv[now]][now] += mx;
                    f[now][prv[now]] -= mx;
                    now = prv[now];
                }
            }
    fout << flow << "\n";
    return 0;
}
