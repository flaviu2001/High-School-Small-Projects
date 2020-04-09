#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct muchie{
    int x, y, c;

    bool operator< (const muchie &obj) const{
        return c < obj.c;
    }
};

muchie g[400005];
vector<muchie> sol;
int n, m, cost;
int c[200005], rng[200005];


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
    if(rng[x] > rng[y])
        c[y] = x;
    else c[x] = y;
    if(rng[x] == rng[y])
        ++rng[y];
}

int main()
{
    ifstream fin ("urgenta.in");
    ofstream fout ("urgenta.out");
    fin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x, y, c;
        fin >> x >> y >> c;
        g[i].x = x;
        g[i].y = y;
        g[i].c = c;
    }
    sort(g+1, g+m+1);
    for (int i = 1; i <= n; ++i)
        c[i] = i,
        rng[i] = 1;
    int muchiiSelectate = 0;
    for (int i = 1; muchiiSelectate < n-1; ++i)
        if(find(g[i].x) != find(g[i].y)){
            ++muchiiSelectate;
            sol.push_back(g[i]);
            cost += g[i].c;
            unite(find(g[i].x), find(g[i].y));
        }
    fout << cost << "\n" << muchiiSelectate << "\n";
    for (unsigned i = 0; i < sol.size(); ++i)
        fout << sol[i].x << " " << sol[i].y << "\n";
    fin.close();
    fout.close();
    return 0;
}

