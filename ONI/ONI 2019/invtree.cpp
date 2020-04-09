#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "invtree";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

struct edge{
    ll y, c, s;
    bool operator<(const edge &aux)const{
        return c < aux.c;
    }
};

ll n, sb[nmax], cc[nmax];
multiset<edge> v[nmax];
bool ans[nmax];

void predfs(ll x, ll pred = 0)
{
    for (auto y : v[x])
        if(y.y != pred){
            predfs(y.y, x);
            cc[y.y] = y.c;
            sb[x] += y.c+sb[y.y];
        }
}

void build(ll nod, ll st, ll dr, edge aint[], vector<edge> &r)
{
    if(st == dr)
        aint[nod] = r[st-1];
    else{
        ll m = (st+dr)/2;
        build(nod*2, st, m, aint, r);
        build(nod*2+1, m+1, dr, aint, r);
        aint[nod] = aint[nod*2];
        if(aint[nod*2+1].c > aint[nod].c)
            aint[nod] = aint[nod*2+1];
    }
}

edge query(ll nod, ll st, ll dr, ll le, ll ri, ll lf, edge aint[])
{
    ll m = (st+dr)/2;
    if(st >= le && dr <= ri){
        if(st == dr)
            return aint[nod];
        if(aint[nod*2].c+lf > 0)
            return query(nod*2, st, m, le, ri, lf, aint);
        return query(nod*2+1, m+1, dr, le, ri, lf ,aint);
    }
    edge ans = {0, -INF/2, 0};
    if(le <= m)
        ans = query(nod*2, st, m, le, ri, lf, aint);
    if(m+1 <= ri && ans.c+lf <= 0)
        ans = query(nod*2+1, m+1, dr, le, ri, lf, aint);
    return ans;
}

void dfs(ll x, ll pred, ll h)
{
    ans[x] = 1;
    vector<edge> r;
    ll sum = 0;
    for (auto y : v[x])
        if(y.y != pred){
            r.push_back({y.y, y.c-sum, sum});
            sum += sb[y.y]+y.c;
        }
    if(r.size() == 0)
        return;
    r.push_back({0, INF, sum});
    edge aint[(r.size()+1)*4];
    build(1, 1, r.size(), aint, r);
    for (unsigned i = 0; i < r.size()-1; ++i){
        if(r[i].c-h > 0)
            break;
        dfs(r[i].y, x, query(1, 1, r.size(), i+2, r.size(), sb[r[i].y]-h, aint).s-sb[r[i].y]+h-2*cc[r[i].y]);
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    ll h;
    fin >> n >> h;
    for (ll i = 1; i < n; ++i){
        ll x, y, c;
        fin >> x >> y >> c;
        v[x].insert({y, c});
        v[y].insert({x, c});
    }
    predfs(1);
    dfs(1, 0, h);
    for(ll i = 1; i <= n; ++i)
        fout << ans[i];
    return 0;
}
