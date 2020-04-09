#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "delay";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 16004;

int n, test, p, p2, c[nmax], e[nmax*2], e2[nmax*2], aint[nmax*8], pos[2][nmax], first[nmax], dep[nmax];
pi aintlca[nmax*8];
vector<int> v[nmax];

void dfs(int x, int pred = 0)
{
    dep[x] = dep[pred]+1;
    e[++p] = x;
    e2[++p2] = x;
    first[x] = p2;
    pos[0][x] = p;
    for (auto y : v[x])
        if(y != pred){
            dfs(y, x);
            e2[++p2] = x;
        }
    e[++p] = -x;
    pos[1][x] = p;
}

int sgn(int x)
{
    return (x < 0 ? -1 : 1);
}

void build(int nod, int st, int dr)
{
    if(st == dr)
        aint[nod] = sgn(e[st])*c[abs(e[st])];
    else{
        int mid = (st+dr)/2;
        build(nod*2, st, mid);
        build(nod*2+1, mid+1, dr);
        aint[nod] = aint[nod*2]+aint[nod*2+1];
    }
}

void buildlca(int nod, int st, int dr)
{
    if(st == dr)
        aintlca[nod] = {dep[e2[st]], e2[st]};
    else{
        int mid = (st+dr)/2;
        buildlca(nod*2, st, mid);
        buildlca(nod*2+1, mid+1, dr);
        aintlca[nod] = min(aintlca[nod*2], aintlca[nod*2+1]);
    }
}

pi querylca(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return aintlca[nod];
    int mid = (st+dr)/2;
    pi ans = {inf, -1};
    if(mid >= l)
        ans = querylca(nod*2, st, mid, l, r);
    if(mid+1 <= r)
        ans = min(ans, querylca(nod*2+1, mid+1, dr, l, r));
    return ans;
}

int lca(int x, int y)
{
    return querylca(1, 1, p2, min(first[x], first[y]), max(first[x], first[y])).ss;
}

void update(int nod, int st, int dr, int pos, int val)
{
    if(st == dr)
        aint[nod] = val;
    else{
        int mid = (st+dr)/2;
        if(mid >= pos)
            update(nod*2, st, mid, pos, val);
        else update(nod*2+1, mid+1, dr, pos, val);
        aint[nod] = aint[nod*2]+aint[nod*2+1];
    }
}

int query(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return aint[nod];
    int mid = (st+dr)/2, ans = 0;
    if(mid >= l)
        ans = query(nod*2, st, mid, l, r);
    if(mid+1 <= r)
        ans += query(nod*2+1, mid+1, dr, l, r);
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> c[i];
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    build(1, 1, p);
    buildlca(1, 1, p2);
    fin >> test;
    while(test--){
        int t, x, y;
        fin >> t >> x >> y;
        if(t == 1){
            c[x] = y;
            update(1, 1, p, pos[0][x], y);
            update(1, 1, p, pos[1][x], -y);
        }else{
            int lf = lca(x, y);
            int ans = -c[lf];
            ans += query(1, 1, p, pos[0][lf], pos[0][x]);
            ans += query(1, 1, p, pos[0][lf], pos[0][y]);
            fout << ans << "\n";
        }
    }
    return 0;
}
