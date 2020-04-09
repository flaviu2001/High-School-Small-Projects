#include <bits/stdc++.h>

using namespace std;

struct edge{
    int x, y, c;
    bool ok;

    bool operator<(const edge &e)const{
        return c < e.c;
    }
};

int n, m, c[50005], rng[50005], mn, t[50005];
edge e[100005];
vector< pair<int, int> > sol;

edge make_edge(int x, int y, int c)
{
    edge aux;
    aux.x = x;
    aux.y = y;
    aux.c = c;
    aux.ok = 1;
    return aux;
}

int find(int x)
{
    int R;
    for (R = x; R != c[R]; R = c[R]);
    for (int i = x; i != R;){
        int go = c[i];
        c[i] = R;
        i = go;
    }
    return R;
}

void unite(int x, int y)
{
    if(rng[x] < rng[y])
        c[x] = y;
    else c[y] = x;
    if(rng[x] == rng[y])
        ++rng[y];
}

int kruskal(bool type)
{
    for (int i = 1; i <= m; ++i){
        c[i] = i;
        rng[i] = 1;
    }
    int sum = 0, p = 0;
    for (int i = 1; i <= m; ++i)
        if(e[i].ok == 1 && find(e[i].x) != find(e[i].y)){
            sum += e[i].c;
            unite(find(e[i].x), find(e[i].y));
            if(type)
                t[++p] = i;
        }
    return sum;
}

int main()
{
    ifstream fin ("vitale.in");
    ofstream fout ("vitale.out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, c;
        fin >> x >> y >> c;
        e[i] = make_edge(x, y, c);
    }
    sort(e+1, e+m+1);
    mn = kruskal(1);
    for (int i = 1; i <= n-1; ++i){
        e[t[i]].ok = 0;
        if(kruskal(0) != mn)
            sol.push_back(make_pair(min(e[t[i]].x, e[t[i]].y), max(e[t[i]].x, e[t[i]].y)));
        e[t[i]].ok = 1;
    }
    sort(sol.begin(), sol.end());
    fout << sol.size() << "\n";
    for (vector< pair<int, int> >::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    fin.close();
    fout.close();
    return 0;
}

