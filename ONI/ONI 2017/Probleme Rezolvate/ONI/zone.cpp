#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> e[303*303];
int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};
int n, m, t, sz, p, r[303*303];
char v[303][303];
bool ok[903][903], ok2[303*303];
int w[303][303];

bool check(int x, int y)
{
    return (x > 0 && y > 0 && x <= n && y <= m);
}

void fll(int x, int y, int q)
{
    if(check(x, y) && v[x][y] == q && !ok[x][y]){
        ++sz;
        ok[x][y] = 1;
        w[x][y] = p+1;
        fll(x+1, y, q);
        fll(x, y+1, q);
        fll(x-1, y, q);
        fll(x, y-1, q);
    }
}

void dfs(int x)
{
    if(!ok2[x]){
        ok2[x] = 1;
        sz += r[x];
        for (unsigned i = 0; i < e[x].size(); ++i)
            if(!ok2[e[x][i]])
                dfs(e[x][i]);

    }
}

bool check2(int x, int y)
{
    for (unsigned i = 0; i < e[x].size(); ++i)
        if(e[x][i] == y)
            return true;
    return false;
}

int main()
{
    ifstream fin ("zone.in");
    ofstream fout ("zone.out");
    fin >> n >> m >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(!ok[i][j]){
                sz = 0;
                fll(i, j, v[i][j]);
                r[++p] = sz;
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k < 4; ++k){
                if(check(i+dx[k], j+dy[k]) && w[i][j] != w[i+dx[k]][j+dy[k]] && !check2(w[i][j], w[i+dx[k]][j+dy[k]])){
                    e[w[i+dx[k]][j+dy[k]]].push_back(w[i][j]);
                    e[w[i][j]].push_back(w[i+dx[k]][j+dy[k]]);
                }
            }
    queue<int> q;
    for (int i = 1; i <= p; ++i)
        if((int)e[i].size() < t)
            q.push(i);

    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (int i = e[k].size()-1; i >= 0; --i){
            int k1 = e[k].back();
            for (int j = 0; j < (int)e[k1].size(); ++j)
                if(e[k1][j] == k){
                    e[k1].erase(e[k1].begin()+j);
                    break;
                }
            if((int)e[k1].size() < t)
                q.push(k1);
            e[k].pop_back();
        }
    }
    int mx = 0;
    for (int i = 1; i <= p; ++i)
        if(e[i].size() && !ok2[i]){
            sz = 0;
            dfs(i);
            if(sz > mx)
                mx = sz;
        }
    fout << mx << "\n";
    fin.close();
    fout.close();
    return 0;
}

