#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct edge{
    int x;
    int y;
    int es;
    int val;
 
    bool operator< (const edge &obj) const{
        if(es <  obj.es)
            return true;
        if(es > obj.es)
            return false;
        if(val < obj.val)
            return true;
        return false;
    }
};
 
edge e[32000];
int n, m, test, c[32000], rng[32000], nodes;
bool ok[32000];
vector<edge> sol;
vector<int> v[32000];
 
edge make_edge(int x, int y, int es, int val)
{
    edge aux;
    aux.x = x;
    aux.y = y;
    aux.es = es;
    aux.val = val;
    return aux;
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
    if(rng[x] > rng[y])
        c[y] = x;
    else c[x] = y;
    if(rng[x] == rng[y])
        ++rng[y];
}
 
void df(int x)
{
    ok[x] = 1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            df(v[x][i]);
}
 
int main()
{
    ifstream fin ("ninjago.in");
    ofstream fout ("ninjago.out");
    fin >> test >> n >> m;
    for (int j = 1; j <= m; ++j){
        int x, y, es = 0, val = 0, mult = 1;
        char q;
        fin >> x >> y;
        for (int i = 0; i < 4; ++i){
            fin >> q;
            if(q == 'E')
                ++es;
            else
                switch(q){
                    case 'A':
                        val += mult*1;
                        break;
                    case 'B':
                        val += mult*2;
                        break;
                    case 'C':
                        val += mult*3;
                        break;
                    case 'D':
                        val += mult*4;
                        break;
                }
            mult *= 5;
        }
        e[j] = make_edge(x, y, es, val);
    }
    sort(e+1, e+m+1);
    for (int i = 0; i < 32000; ++i){
        c[i] = i;
        rng[i] = 1;
    }
    int muchiiselectate = 0, cost = 0, Es = 0, walls = 0;
    for (int i = 1; muchiiselectate < n-1; ++i)
        if(find(e[i].x) != find(e[i].y)){
            ++muchiiselectate;
            sol.push_back(e[i]);
            cost += e[i].val;
            if(e[i].es > 0){
                Es += e[i].es;
                ++walls;
            }else{
                v[e[i].x].push_back(e[i].y);
                v[e[i].y].push_back(e[i].x);
            }
            unite(find(e[i].x), find(e[i].y));
        }
    switch(test){
        case 1:
            df(1);
            for (int i = 0; i < 32000; ++i)
                if(ok[i])
                    ++nodes;
            fout << nodes << "\n";
            break;
        case 2:
            fout << walls << "\n" << Es << "\n";
            break;
        case 3:
            fout << cost << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
