#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct point{
    int x;
    int y;
};

struct edge{
    int x;
    int y;
    double c;

    inline bool operator< (const edge &obj) const{
        return c < obj.c;
    }
};

vector<edge> w, we;
vector<point> r;
int n, tt[510000], rng[510000];

double dist(point t1, point t2)
{
    return sqrt((t1.x-t2.x) * (t1.x-t2.x) + (t1.y-t2.y) * (t1.y-t2.y));
}

edge make_edge(int x, int y, double c)
{
    edge e;
    e.x = x;
    e.y = y;
    e.c = c;
    return e;
}

int find (int x)
{
    int root = x;
    for (; root != tt[root]; root = tt[root]);
    for (int i = x; i != tt[i];){
        int y = tt[i];
        tt[i] = root;
        i = y;
    }
    return root;
}

void unite(int x, int y)
{
    if(rng[x] < rng[y])
        tt[x] = y;
    else tt[y] = x;
    if(rng[x] == rng[y])
        ++rng[x];
}

double apm(int n)
{
    int muchiiSelectate = 0;
    double cost = 0;
    we.clear();
    for (int i = 0; muchiiSelectate < n-1; ++i)
        if(find(w[i].x) != find(w[i].y)){
            ++muchiiSelectate;
            cost += w[i].c;
            we.push_back(w[i]);
            unite(find(w[i].x), find(w[i].y));
        }
    w.clear();
    for (unsigned i = 0; i < we.size(); ++i)
        w.push_back(we[i]);
    return cost;
}

int main()
{
    ifstream fin ("desen.in");
    ofstream fout ("desen.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        point t;
        fin >> t.x >> t.y;
        for (unsigned j = 0; j < r.size(); ++j){
            w.push_back(make_edge(i, j+1, dist(r[j], t)));
            tt[j] = j;
            rng[j] = 1;
        }
        tt[i-1] = i-1;
        tt[i] = i;
        rng[i-1] = rng[i] = 1;
        r.push_back(t);
        sort(w.begin(), w.end());
        fout << fixed << setprecision(6) << apm(i) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

