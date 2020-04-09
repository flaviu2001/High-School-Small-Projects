#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, m, d[100005];
vector<int> v[100005], xes;
queue<int> q;
bool mx[100005];

int main()
{
    ifstream fin ("grafxy.in");
    ofstream fout ("grafxy.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 0; i < 100005; ++i)
        d[i] = 2000000000;
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        xes.push_back(x);
        mx[x] = 1;
    }
    fin >> m;
    for (int i = 1; i <= m; ++i){
        int x;
        fin >> x;
        d[x] = 0;
        q.push(x);
    }
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(d[v[k][i]] > d[k] + 1){
                d[v[k][i]] = d[k] + 1;
                q.push(v[k][i]);
            }
    }
    for (unsigned i = 0; i < xes.size(); ++i)
        fout << d[xes[i]] << "\n";
    fin.close();
    fout.close();
    return 0;
}

