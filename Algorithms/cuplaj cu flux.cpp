#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, m, e;
vector< vector<int> > v, f, c;
vector< pair<int, int> > p;
vector<int> r, r2, fiu;
vector<bool> ok;

bool bfs()
{
    for (unsigned i = 0; i < ok.size(); ++i)
        ok[i] = 0;
    queue<int> q;
    q.push(0);
    ok[0] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(f[k][v[k][i]] != c[k][v[k][i]] && !ok[v[k][i]]){
                fiu[v[k][i]] = k;
                ok[v[k][i]] = 1;
                q.push(v[k][i]);
                if(v[k][i] == n+m+1)
                    return 1;
            }
    }
    return 0;
}

int main()
{
    ifstream fin ("cuplaj.in");
    ofstream fout ("cuplaj.out");
    fin >> n >> m >> e;
    for (int i = 0; i <= n+m+1; ++i)
        r2.push_back(0);
    for (int i = 0; i <= n+m+1; ++i){
        v.push_back(r);
        f.push_back(r2);
        c.push_back(r2);
        ok.push_back(0);
        fiu.push_back(0);
    }
    while(e--){
        int x, y;
        fin >> x >> y;
        if(c[0][x] == 0){
            c[0][x] = 1;
            v[0].push_back(x);
            v[x].push_back(0);
        }
        v[x].push_back(n+y);
        v[n+y].push_back(x);
        c[x][n+y] = 1;
        if(c[n+y][n+m+1] == 0){
            c[n+y][n+m+1] = 1;
            v[n+y].push_back(n+m+1);
            v[n+m+1].push_back(n+y);
        }
    }
    int flow = 0;
    while(bfs())
        for (unsigned j = 0; j < v[n+m+1].size(); ++j)
            if(c[v[n+m+1][j]][n+m+1] != f[v[n+m+1][j]][n+m+1] && ok[v[n+m+1][j]]){
                int fmin = 2000000000;
                fiu[n+m+1] = v[n+m+1][j];
                for (int i = n+m+1; i != 0; i = fiu[i])
                    fmin = min(fmin, c[fiu[i]][i] - f[fiu[i]][i]);
                if(fmin == 0)
                    continue;
                flow += fmin;
                for (int i = n+m+1; i != 0; i = fiu[i]){
                    f[fiu[i]][i] += fmin;
                    f[i][fiu[i]] -= fmin;
                }
            }
    fout << flow << "\n";
    for (int i = 1; i <= n; ++i)
        for (unsigned j = 0; j < v[i].size(); ++j)
            if(v[i][j] >= n+1 && v[i][j] <= n+m && f[i][v[i][j]] == 1)
                fout << i << " " << v[i][j]-n << "\n";
    fin.close();
    fout.close();
    return 0;
}

