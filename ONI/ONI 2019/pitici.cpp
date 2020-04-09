#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pi;
const int nmax = 1025, inf = 2147483647;

struct thing{
    int nod, first, val;
    bool operator>(const thing &obj)const{
        return val > obj.val;
    }
};

int n, m, k, pd[nmax];
bool ok[nmax];
vector<pi> v[nmax], pdl[nmax];
priority_queue< thing, vector<thing>, greater<thing> > q;

void dfs(int x)
{
    ok[x] = 1;
    pd[x] = inf;
    if(x == n)
        pd[x] = 0;
    for (auto y : v[x]){
        if(!ok[y.ff])
            dfs(y.ff);
        if(pd[y.ff] != inf){
            pd[x] = min(pd[x], pd[y.ff]+y.ss);
            pdl[x].push_back({pd[y.ff]+y.ss, y.ff});
        }
    }
}

int main()
{
    ifstream fin ("pitici.in");
    ofstream fout ("pitici.out");
    fin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        int x, y, c;
        fin >> x >> y >> c;
        v[x].push_back({y, c});
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        sort(pdl[i].begin(), pdl[i].end());
    thing baga;
    baga.nod = 1;
    baga.first = 0;
    baga.val = pdl[1][0].ff;
    q.push(baga);
    for (int t = 1; t <= k; ++t){
        thing now = q.top();
        q.pop();
        fout << now.val << " ";
        if(now.first+1 < pdl[now.nod].size()){
            baga.nod = now.nod;
            baga.first = now.first+1;
            baga.val = now.val + pdl[now.nod][now.first+1].ff-pdl[now.nod][now.first].ff;
            q.push(baga);
        }
        int x = pdl[now.nod][now.first].ss;
        while(x != n){
            if(pdl[x].size() > 1){
                baga.nod = x;
                baga.first = 1;
                baga.val = now.val + pdl[x][1].ff-pdl[x][0].ff;
                q.push(baga);
            }
            x = pdl[x][0].ss;
        }
    }
    return 0;
}
