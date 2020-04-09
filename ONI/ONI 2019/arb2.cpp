#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge{
    ll x, l, c;
};

ll n, up[100005], pd[100005], mx[100005];
vector<edge> v[100005];

void dfs(ll x, edge pred={0,0,0}, ll len = 0)
{
    mx[x] = len;
    up[x] = pred.c;
    ll up2 = 0;
    bool leaf = true;
    for (auto y : v[x])
        if(y.x != pred.x){
            leaf = false;
            dfs(y.x, {x, y.l, y.c}, len+y.l);
            mx[x] = max(mx[x], mx[y.x]);
            up2 += up[y.x];
            pd[x] += pd[y.x];
        }
    if(!leaf)
        up[x] = min(up[x], up2);
    for (auto y : v[x])
        if(y.x != pred.x)
            pd[x] += (mx[x]-mx[y.x])*up[y.x];
}

int main()
{
    ifstream fin ("arb2.in");
    ofstream fout ("arb2.out");
    fin >> n;
    for (ll i = 1; i < n; ++i){
        ll x, y, l, c;
        fin >> x >> y >> l >> c;
        v[x].push_back({y, l, c});
        v[y].push_back({x, l, c});
    }
    dfs(1);
    fout << pd[1] << "\n";
    return 0;
}
