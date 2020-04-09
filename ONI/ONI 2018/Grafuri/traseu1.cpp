#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int, int> > v[505];
int home, work, d[505], n, m;

int main()
{
    ifstream fin ("traseu1.in");
    ofstream fout ("traseu1.out");
    fin >> n >> m;
    for (int i = 0; i < 505; ++i)
        d[i] = 110000;
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    fin >> home >> work;
    queue<int> q;
    q.push(home);
    d[home] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(d[v[k][i].first] > max(d[k], v[k][i].second)){
                d[v[k][i].first] = max(d[k], v[k][i].second);
                q.push(v[k][i].first);
            }
    }
    fout << d[work] << "\n";
    fin.close();
    fout.close();
    return 0;
}

