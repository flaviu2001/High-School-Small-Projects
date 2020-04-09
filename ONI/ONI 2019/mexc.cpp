#include <bits/stdc++.h>
#define ff first
#define ss second
 
using namespace std;
typedef pair<int, int> pi;
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m, d, c[805*805], rng[805*805], f[805*805], mat[805][805], ans[805][805];
vector<pi> v[100005];
 
int find(int x)
{
    if(x == c[x])
        return x;
    c[x] = find(c[x]);
    return c[x];
}
 
void unite(int x, int y)
{
    if(x == y)
        return;
    if(rng[x] > rng[y]){
        c[y] = x;
        f[x] += f[y];
    }else{
        c[x] = y;
        f[y] += f[x];
    }
    if(rng[x] == rng[y])
        ++rng[y];
}
 
int cv(pi x)
{
    return x.ff*805+x.ss;
}
 
int main()
{
    ifstream fin ("mexc.in");
    ofstream fout ("mexc.out");
    fin >> n >> m >> d;
    int mx = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int x;
            fin >> x;
            mat[i][j] = x;
            mx = max(mx, x);
            v[x].push_back({i, j});
        }
    for (int i = 0; i < 805*805; ++i){
        c[i] = i;
        rng[i] = 1;
    }
    for (int t = mx; t >= -d; --t){
        if(t >= 0){
            for (auto p : v[t])
                for (int e = 0; e < 4; ++e){
                    pi now = p;
                    now.ff += dx[e];
                    now.ss += dy[e];
                    if(now.ff < 1 || now.ff > n || now.ss < 1 || now.ss > m || mat[now.ff][now.ss] < t)
                        continue;
                    unite(find(cv(p)), find(cv(now)));
                }
        }
        if(t+d <= mx){
            for (auto p : v[t+d])
                ++f[find(cv(p))];
            for (auto p : v[t+d])
                ans[p.ff][p.ss] = f[find(cv(p))];
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            fout << ans[i][j] << " ";
        fout << "\n";
    }
    return 0;
}