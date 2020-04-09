#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int, int> > v[36006];
queue<int> q;
int n, m, t, d[36006], orig[36006];
bool isfort[36006];

int main()
{
    ifstream fin ("catun.in");
    ofstream fout ("catun.out");
    fin >> n >> m >> t;
    for (int i = 0; i < 36006; ++i)
        d[i] = 2000000000;
    for (int i = 1; i <= t; ++i){
        int x;
        fin >> x;
        d[x] = 0;
        q.push(x);
        orig[x] = x;
        isfort[x] = 1;
    }
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(d[v[k][i].first] > d[k] + v[k][i].second){
                orig[v[k][i].first] = orig[k];
                d[v[k][i].first] = d[k] + v[k][i].second;
                q.push(v[k][i].first);
            }else if (d[v[k][i].first] == d[k] + v[k][i].second)
                orig[v[k][i].first] = min(orig[v[k][i].first], orig[k]),
                q.push(v[k][i].first);
    }
    for (int i = 1; i <= n; ++i)
        if(!isfort[i])
            fout << orig[i] << " ";
        else fout << "0 ";
    fin.close();
    fout.close();
    return 0;
}

