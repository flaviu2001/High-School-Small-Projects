#include <fstream>
#include <vector>

using namespace std;

int n, m, ordine[100005], no;
vector<int> v[100005], vt[100005], r;
vector< vector<int> > sol;
bool vis[100005];

void dfs(int x)
{
    vis[x] = 1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!vis[v[x][i]])
            dfs(v[x][i]);
    ordine[++no] = x;
}

void dfst(int x)
{
    vis[x] = 0;
    r.push_back(x);
    for (unsigned i = 0; i < vt[x].size(); ++i)
        if(vis[vt[x][i]])
            dfst(vt[x][i]);
}

int main()
{
    ifstream fin ("ctc.in");
    ofstream fout ("ctc.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        vt[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    for (int i = n; i; --i)
        if(vis[ordine[i]]){
            r.clear();
            dfst(ordine[i]);
            sol.push_back(r);
        }
    fout << sol.size() << "\n";
    for (unsigned i = 0; i < sol.size(); ++i){
        for (unsigned j = 0; j < sol[i].size(); ++j)
            fout << sol[i][j] << " ";
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

