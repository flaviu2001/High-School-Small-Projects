#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "online";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647;

struct edge{
    int x, y, i, c;
    bool operator<(const edge &obj)const{
        return c < obj.c;
    }
};

int n, m, test, p, c[20005], rng[20005], rem;
edge e[20005], e2[20005];

int find(int x)
{
    if(c[x] == x)
        return x;
    x = find(c[x]);
    return x;
}

void unite(int x, int y)
{
    if(rng[x] < rng[y])
        c[x] = y;
    else c[y] = x;
    if(rng[x] == rng[y])
        ++rng[x];
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        fin >> e2[i].x >> e2[i].y >> e2[i].c; e2[i].i = i;
        c[i] = i;
        rng[i] = 1;
    }
    sort(e2+1, e2+m+1);
    int ans = 0;
    for (int i = 1; i <= m; ++i){
        edge E = e2[i];
        if(find(E.x) != find(E.y)){
            ans += E.c;
            e[++p] = E;
            unite(find(E.x), find(E.y));
        }
    }
    fout << ans << "\n";
    fin >> test;
    while(test--){
        ++p;
        fin >> e[p].x >> e[p].y >> e[p].c; e[p].i = p;
        ans = 0;
        for (int i = p; i >= 2; --i)
            if(e[i-1].c > e[i].c)
                swap(e[i-1], e[i]);
        for (int i = 1; i <= p; ++i)
            c[i] = i, rng[i] = 1;
        for (int i = 1; i <= p; ++i){
            edge E = e[i];
            if(find(E.x) != find(E.y)){
                ans += E.c;
                unite(find(E.x), find(E.y));
            }else rem = i;
        }
        for (int i = rem; i < p; ++i)
            e[i] = e[i+1];
        --p;
        fout << ans << "\n";
    }
    return 0;
}
