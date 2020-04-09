#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100010];
int furthest, mx, d1[100010], d2[100010], n;
bool ok1[100010], ok2[100010];

void bfs(int nod, int d[], bool ok[])
{
    queue<int> q;
    q.push(nod);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        ok[k] = 1;
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(!ok[v[k][i]]){
                d[v[k][i]] = d[k] + 1;
                mx = d[v[k][i]];
                furthest = v[k][i];
                q.push(v[k][i]);
            }
    }
}

int main()
{
    ifstream fin ("darb.in");
    ofstream fout ("darb.out");
        fin >> n;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1, d1, ok1);
    bfs(furthest, d2, ok2);
    fout << mx + 1 << "\n";
    fin.close();
    fout.close();
    return 0;
}
