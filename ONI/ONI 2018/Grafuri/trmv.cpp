#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int, int> > v[1000002];
int n, statii, start, t, d[1000002];
bool ok[1000002];
queue<int> q;

int main()
{
    ifstream fin ("trmv.in");
    ofstream fout ("trmv.out");
    fin >> n >> statii >> start >> t;
    while(statii--){
        int m;
        fin >> m;
        int x1, x2, x3;
        fin >> x1 >> x2 >> x3;
        v[x1].push_back(make_pair(x3, x2));
        v[x3].push_back(make_pair(x1, x2));
        for(int i = 2; i < m; ++i){
            x1 = x3;
            fin >> x2 >> x3;
            v[x1].push_back(make_pair(x3, x2));
            v[x3].push_back(make_pair(x1, x2));
        }
    }
    d[start] = 1;
    q.push(start);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        ok[k] = 0;
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(d[v[k][i].first] == 0 || d[v[k][i].first] > d[k] + v[k][i].second){
                d[v[k][i].first] = d[k] + v[k][i].second;
                if(!ok[v[k][i].first])
                    q.push(v[k][i].first);
                ok[v[k][i].first] = 1;
            }
    }
    for (int i = 1; i <= t; ++i){
        int x;
        fin >> x;
        fout << d[x]-1 << " ";
    }
    fin.close();
    fout.close();
    return 0;
}

