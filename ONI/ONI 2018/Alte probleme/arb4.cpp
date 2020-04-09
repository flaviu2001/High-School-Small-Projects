#include <bits/stdc++.h>

using namespace std;

struct thing{
    int x, y, c, i;
    bool operator<(const thing &obj)const{
        return c < obj.c;
    }
};

struct lca{
    int x, d;
};

int n, m, root = 0, test, p, depth[100005], tt[100005], tti[100005], euclid[200005], first_pos[100005], lg2[200005], ans[100005], c[100005], rng[100005], h[100005];
lca pd[20][200005];
vector< pair<int, int> > v[100005];
vector<thing> e;

lca min(lca a, lca b)
{
    if(a.d < b.d)
        return a;
    return b;
}

lca make_lca(int x, int d)
{
    lca aux;
    aux.x = x;
    aux.d = d;
    return aux;
}

thing make_thing(int x, int y, int c, int i)
{
    thing aux;
    aux.x = x;
    aux.y = y;
    aux.c = c;
    aux.i = i;
    return aux;
}

void dfs (int x, int pred = -1)
{
    tt[x] = pred;
    depth[x] = depth[tt[x]]+1;
    ++p;
    euclid[p] = x;
    first_pos[x] = p;
    vector< pair<int, int> >::iterator rm;
    for (vector< pair<int, int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(it->first != pred){
            dfs(it->first, x);
            euclid[++p] = x;
        }else rm = it;
    if(x != root){
        tti[x] = rm->second;
        v[x].erase(rm);
    }
}

void build_rmq()
{
    for (int i = 1; i < p; ++i){
        pd[0][i] = make_lca(euclid[i], depth[euclid[i]]);
        if(depth[euclid[i]] > depth[euclid[i+1]])
            pd[0][i] = make_lca(euclid[i+1], depth[euclid[i+1]]);
    }
    for (int t = 1; t <= lg2[p-1]; ++t)
        for (int i = 1; i <= p-(1<<t); ++i)
            pd[t][i] = min(pd[t-1][i], pd[t-1][i+(1<<(t-1))]);
}

int query(int x, int y)
{
    if (x == y)
        return x;
    if(first_pos[x] > first_pos[y])
        swap(x, y);
    int sz = lg2[first_pos[y]-first_pos[x]];
    lca aux = min(pd[sz][first_pos[x]], pd[sz][first_pos[y]-(1<<sz)]);
    return aux.x;
}

int find(int x)
{
    int R;
    for (R = x; c[R] != R; R = c[R]);
    while(c[x] != x){
        int y = c[x];
        c[x] = R;
        x = y;
    }
    return R;
}

void unite(int x, int y)
{
    if(rng[x] > rng[y]){
        if(depth[h[y]] < depth[h[x]])
            h[x] = h[y];
        c[y] = x;
    }else{
        if(depth[h[x]] < depth[h[y]])
            h[y] = h[x];
        c[x] = y;
    }
    if(rng[x] == rng[y])
        ++rng[y];
}

void chain(int x, int y, int which) //y - ancestor of x
{
    x = h[find(x)];
    y = h[find(y)];
    if(x == y)
        return;
    int i = x;
    do{
        ans[tti[i]] = which;
        unite(find(i), find(y));
        i = h[find(tt[i])];
    }while(i != y);
}

int main()
{
    ifstream fin ("arb4.in");
    ofstream fout ("arb4.out");
    memset(ans, -1, sizeof(ans));
    fin >> n >> m; m -= n-1;
    for (int i = 1; i < n; ++i){
        int x, y, C;
        fin >> x >> y >> C;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }
    for (int i = 1; i <= n; ++i){
        c[i] = h[i] = i;
        rng[i] = 1;
    }
    for (int i = 1; i <= m; ++i){
        int x, y, c;
        fin >> x >> y >> c;
        e.push_back(make_thing(x, y, c, n+i-2));
    }
    sort(e.begin(), e.end());
    dfs(root);
    lg2[2] = 1;
    for (int i = 3; i < 200005; ++i)
        lg2[i] = lg2[i/2]+1;
    build_rmq();
    for(vector<thing>::iterator it = e.begin(); it != e.end(); ++it){
        int x = it->x, y = it->y;
        int Lca = query(x, y);
        if(x == Lca)
            chain(y, x, it->i);
        else if(y == Lca)
            chain(x, y, it->i);
        else{
            chain(x, Lca, it->i);
            chain(y, Lca, it->i);
        }
    }
    for (int i = 1; i < n; ++i)
        fout << ans[i] << "\n";
    fin.close();
    fout.close();
    return 0;
}

