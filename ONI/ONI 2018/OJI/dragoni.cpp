#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

set<int> vals;
queue< pair<int, int> > q;
queue<int> s;
vector<int> r;
vector< pair<int, int> > v[805];
int n, m, dm[805], to[50005], d[805][805], test;
bool ok[805];

int cerinta1()
{
    s.push(1);
    ok[1] = 1;
    int dk = dm[1], ans = dm[1];
    while(!s.empty()){
        int k = s.front();
        s.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(dk >= v[k][i].second && !ok[v[k][i].first]){
                s.push(v[k][i].first);
                ok[v[k][i].first] = 1;
                ans = max(ans, dm[v[k][i].first]);
            }
    }
    return ans;
}

int cerinta2()
{
    int ans = 2000000000;
    for (int i = 0; i < 805; ++i)
        for (int j = 0; j < 805; ++j)
            d[i][j] = 2000000000;
    d[1][1] = 0;
    q.push(make_pair(1, 1));
    while(!q.empty()){
        int k = q.front().first, dk = q.front().second;
        q.pop();
        for(unsigned i = 0; i < v[k].size(); ++i)
            if(r[dk] >= v[k][i].second && d[v[k][i].first][dk] > d[k][dk] + v[k][i].second){
                int ddk = dk;
                if(r[dk] < r[to[dm[v[k][i].first]]])
                    ddk = to[dm[v[k][i].first]];
                q.push(make_pair(v[k][i].first, ddk));
                d[v[k][i].first][dk] = d[k][dk] + v[k][i].second;
                d[v[k][i].first][ddk] = min(d[v[k][i].first][ddk], d[v[k][i].first][dk]);
                if(v[k][i].first == n)
                    ans = min(ans, d[v[k][i].first][dk]);
            }
    }
    return ans;
}

int main()
{
    ifstream fin ("dragoni.in");
    ofstream fout ("dragoni.out");
    fin >> test >> n >> m;
    r.push_back(2000000000);
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        dm[i] = x;
        if(vals.find(x) == vals.end()){
            vals.insert(x);
            r.push_back(x);
            to[x] = r.size()-1;
        }
    }
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    if(test == 1)
        fout << cerinta1() << "\n";
    else fout << cerinta2() << "\n";
    fin.close();
    fout.close();
    return 0;
}

