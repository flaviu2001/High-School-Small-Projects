#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
 
using namespace std;
typedef pair<double, double> point;
 
vector<point> v;
int n, m;
double e = 1e-10;
 
double cross_product(point O, point A, point B) {
    return (A.first - O.first) * (B.second - O.second) - (B.first - O.first) * (A.second - O.second);
}
 
int infasuratoare()
{
    sort(v.begin(), v.end());
    bool vis[200005] = {0};
    int st[200005], p = 0, n = v.size()-1;
    st[1] = 1;
    st[2] = 2;
    p = 2;
    vis[2] = 1;
    for (int i = 1, pp = 1; i > 0; i += pp){
        pp = (i == n ? -pp : pp);
        if(vis[i])
            continue;
        while(p >= 2 && cross_product(v[st[p-1]], v[st[p]], v[i]) < e)
            vis[st[p--]] = 0;
        st[++p] = i;
        vis[i] = 1;
    }
    return p-1;
}
 
int main()
{
    ifstream fin ("terenuri.in");
    ofstream fout ("terenuri.out");
    fin >> n >> m;
    v.push_back(make_pair(-1000000000, -1000000000));
    for (int i = 1; i <= n; ++i){
        double x, y;
        fin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    fout << infasuratoare() << "\n";
    for (int i = 1; i <= m; ++i){
        double x, y;
        fin >> x >> y;
        v.push_back(make_pair(x, y));
        fout << infasuratoare() << "\n";
    }
    return 0;
}
