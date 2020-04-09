#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "fmcm";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1005;

int n, m, c[nmax][nmax], f[nmax][nmax], e[nmax][nmax], prv[nmax], d[nmax], Entry, Exit;
vector<int> v[nmax];
bool inq[nmax];

int bell()
{
    queue<int> q;
    q.push(Entry);
    memset(inq, 0, sizeof(inq));
    for (int i = 1; i <= n; ++i)
        d[i] = inf;
    d[Entry] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        inq[k] = 0;
        for (auto x : v[k])
            if(f[k][x] < c[k][x] && d[k]+e[k][x] < d[x]){
                d[x] = d[k]+e[k][x];
                if(!inq[x])
                    q.push(x);
                inq[x] = 1;
                prv[x] = k;
            }
    }
    return d[Exit];
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> Entry >> Exit;
    for (int i = 1; i <= m; ++i){
        int x, y, z1, z2;
        fin >> x >> y >> z1 >> z2;
        v[x].push_back(y);
        v[y].push_back(x);
        c[x][y] = z1;
        e[x][y] = z2;
        e[y][x] = -z2;
    }
    int cost = 0, flow = 0, add;
    while((add = bell()) != inf){
        int now = Exit, mx = inf;
        while(now != Entry){
            mx = min(mx, c[prv[now]][now]-f[prv[now]][now]);
            now = prv[now];
        }
        flow += mx;
        cost += add*mx;
        now = Exit;
        while(now != Entry){
            f[prv[now]][now] += mx;
            f[now][prv[now]] -= mx;
            now = prv[now];
        }
    }
    fout << cost << "\n";
    //fout << flow << "\n";
    return 0;
}
