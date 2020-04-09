#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, c;

    edge(int xx, int yy, int cc){
        x = xx;
        y = yy;
        c = cc;
    }

    bool operator< (const edge &obj) const{
        return c < obj.c;
    }
};

vector<edge> e;
vector<int> pd;
int n, m, t, tt[1005], rnk[1005];
bool ok[50005];

int add_shit(int x)
{
    int cnt = 0;
    vector<int>::iterator end = pd.end();
    for (vector<int>::iterator it = pd.begin(); it != end; ++it)
        if(*it+x <= t && !ok[*it+x]){
            ok[*it+x] = 1;
            pd.push_back(*it+x);
            ++cnt;
        }
    return cnt;
}

int find(int x)
{
    int root = x;
    for (; root != tt[root]; root = tt[root]);
    for (; x != tt[x];){
        int y = tt[x];
        tt[x] = root;
        x = y;
    }
    return root;
}

void unite(int x, int y)
{
    if(rnk[x] < rnk[y])
        tt[x] = y;
    else tt[y] = x;
    if(rnk[x] == rnk[y])
        ++rnk[x];
}

int main()
{
    ifstream fin ("retea.in");
    ofstream fout ("retea.out");
    fin >> n >> m >> t;
    for (int i = 0; i <= n; ++i){
        tt[i] = i;
        rnk[i] = 1;
    }
    for (int i = 0; i < m; ++i){
        int x, y, z;
        fin >> x >> y >> z;
        e.push_back(edge(x, y, z));
    }
    sort(e.begin(), e.end());
    ok[0] = 1;
    pd.push_back(0);
    int muchiiSelectate = 0, cost = 0, mascari = 1;
    for (vector<edge>::iterator it = e.begin(); muchiiSelectate < n-1; ++it)
        if(find(it->x) != find(it->y)){
            ++muchiiSelectate;
            mascari += add_shit(it->c);
            cost += it->c;
            unite(find(it->x), find(it->y));
        }
    fout << cost << " " << mascari << "\n";
    fin.close();
    fout.close();
    return 0;
}

