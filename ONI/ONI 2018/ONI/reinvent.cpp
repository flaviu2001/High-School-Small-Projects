#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100005];
queue<int> q;
int n, m, t, prov[100005], d[100005];
bool ok[100005];

int main()
{   ifstream fin ("reinvent.in");
    ofstream fout ("reinvent.out");
    fin >> n >> m >> t;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= t; ++i){
        int x;
        fin >> x;
        q.push(x);
        prov[x] = x;
        ok[x] = 1;
    }
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i){
            if(!ok[v[k][i]]){
                ok[v[k][i]] = 1;
                prov[v[k][i]] = prov[k];
                q.push(v[k][i]);
                d[v[k][i]] = d[k] + 1;
            }else if (prov[v[k][i]] != prov[k]){
                fout << d[v[k][i]] + d[k] + 1 << "\n";
                fin.close();
                fout.close();
                return 0;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}

