#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, c;
    bool valid;

    bool operator< (const edge &obj) const{
        return this->c < obj.c;
    }
};

vector<edge> e;
vector<int> tt, rnk;
int n, m, t, solSZ;

edge make_edge(int x, int y, int c)
{
    edge aux;
    aux.x = x;
    aux.y = y;
    aux.c = c;
    return aux;
}

int find(int x)
{
    int root = x;
    for (; root != tt[root]; root = tt[root]);
    for (int i = x; i != root;){
        int y = tt[i];
        tt[i] = root;
        i = y;
    }
    return root;
}

void unite(int x, int y)
{
    if(rnk[x] < rnk[y])
        tt[x] = y;
    else tt[y] = x;
    if(rnk[x] == rnk[y])
        ++rnk[y];
}

int main()
{
    ifstream fin ("urgenta.in");
    ofstream fout ("urgenta.out");
    fin >> n >> m >> t;
    for (int i = 0; i <= n; ++i){
        tt.push_back(i);
        rnk.push_back(1);
    }
    for (int i = 0; i < m; ++i){
        int x, y, c;
        fin >> x >> y >> c;
        e.push_back(make_edge(x, y, c));
    }
    sort(e.begin(), e.end());
    int muchiiSelectate = 0, cost = 0;
    for (vector<edge>::iterator it = e.begin(); it != e.end(); ++it)
        if(find(it->x) != find(it->y) && muchiiSelectate < n-t){
            ++muchiiSelectate;
            unite(find(it->x), find(it->y));
            it->valid = 0;
        }else{
            cost += it->c;
            it->valid = 1;
            ++solSZ;
        }
    fout << cost << "\n" << solSZ << "\n";
    for (vector<edge>::iterator it = e.begin(); it != e.end(); ++it)
        if(it->valid)
            fout << it->x << " " << it->y << "\n";
    fin.close();
    fout.close();
}

