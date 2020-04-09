#include <bits/stdc++.h>

using namespace std;

struct thing{
    int x, d;
    bool operator<(const thing &obj)const{
        return d < obj.d;
    }
}pd[20][66000];

int cnt, euclid[66000], first_pos[33000], lg2[66000], n, m, p, d[33000];
pair<int, int> tt[33000], r[33000][20];
vector< pair<int, int> >v[33000];

void df(int x, int pred = 0)
{
    d[x] = d[pred]+1;
    for (vector< pair<int, int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(it->first == pred){
            tt[x] = *it;
            break;
        }
    if(x != 1){
        r[x][0] = tt[x];
        int pw = 1;
        while(d[x] - (1<<pw) >= 1){
            r[x][pw].first = r[r[x][pw-1].first][pw-1].first;
            r[x][pw].second = min(r[r[x][pw-1].first][pw-1].second, r[x][pw-1].second);
            ++pw;
        }
    }
    euclid[++cnt] = x;
    first_pos[x] = cnt;
    for (vector< pair<int, int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(it->first != pred){
            df(it->first, x);
            euclid[++cnt] = x;
        }
}

thing make_thing(int x, int d)
{
    thing aux;
    aux.x = x;
    aux.d = d;
    return aux;
}

void build_rmq()
{
    for (int i = 1; i < cnt; ++i){
        pd[0][i] = make_thing(euclid[i], d[euclid[i]]);
        if(d[euclid[i]] > d[euclid[i+1]])
            pd[0][i] = make_thing(euclid[i+1], d[euclid[i+1]]);
    }
    for (int t = 1; t <= lg2[cnt-1]; ++t)
        for (int i = 1; i <= cnt-(1<<t); ++i)
            pd[t][i] = min(pd[t-1][i], pd[t-1][i+(1<<(t-1))]);
}

int query_lca(int x, int y)
{
    if (x == y)
        return x;
    if(first_pos[x] > first_pos[y])
        swap(x, y);
    int sz = lg2[first_pos[y]-first_pos[x]];
    thing aux = min(pd[sz][first_pos[x]], pd[sz][first_pos[y]-(1<<sz)]);
    return aux.x;
}

int pw2(int x)
{
    int ans = 0;
    for (; (1<<ans) <= x; ++ans);
    return ans-1;
}

int min_per_chain(int x, int y) //y - ancestor for x
{
    if(x == y)
        return 0;
    int aux = pw2(d[x]-d[y]);
    if(r[x][aux].first == y)
        return r[x][aux].second;
    return min(r[x][aux].second, min_per_chain(r[x][aux].first, y));
}

int main()
{
    ifstream fin ("atac.in");
    ofstream fout ("atac.out");
    fin >> n >> m >> p;
    for (int i = 2; i <= n; ++i){
        int u, vv;
        fin >> u >> vv;
        v[u].push_back({i, vv});
        v[i].push_back({u, vv});
    }
    df(1);
    lg2[2] = 1;
    for (int i = 3; i < 66000; ++i)
        lg2[i] = lg2[i/2]+1;
    build_rmq();
    int x, y, a, b, c, d, ans;
    fin >> x >> y >> a >> b >> c >> d;
    if(x == query_lca(x, y))
        ans = min_per_chain(y, query_lca(x, y));
    else if (y == query_lca(x, y))
        ans = min_per_chain(x, query_lca(x, y));
    else ans = min(min_per_chain(x, query_lca(x, y)), min_per_chain(y, query_lca(x, y)));
    if(p == m)
        fout << ans << "\n";
    for (int t = 2; t <= m; ++t){
        int X, Y;
        X = (x*a+y*b)%n+1;
        Y = (y*c+ans*d)%n+1;
        if(X == query_lca(X, Y))
            ans = min_per_chain(Y, query_lca(X, Y));
        else if (Y == query_lca(X, Y))
            ans = min_per_chain(X, query_lca(X, Y));
        else ans = min(min_per_chain(X, query_lca(X, Y)), min_per_chain(Y, query_lca(X, Y)));
        if(t+p > m)
            fout << ans << "\n";
        x = X;
        y = Y;
    }
    fin.close();
    fout.close();
    return 0;
}

