#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> v[215];
char s[10005];
int n, m, c[215][215], f[215][215], fiu[215];
bool ok[215];

bool bf()
{
    memset(ok, 0, sizeof(ok));
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
    ifstream fin ("senat.in");
    ofstream fout ("senat.out");
    fin >> n >> m;
    fin.get();
    for (int i = 1; i <= m; ++i){
        fin.getline(s, 10005);
        stringstream sin(s);
        int x;
        c[0][i] = 1;
        v[0].push_back(i);
        v[i].push_back(0);
        while(sin>>x){
            v[i].push_back(m+x);
            v[m+x].push_back(i);
            c[i][m+x] = 1;
            v[m+x].push_back(n+m+1);
            v[n+m+1].push_back(m+x);
            c[m+x][n+m+1] = 1;
        }
    }
    int flow = 0;
    while(bf())
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
    if(flow != m){
        fout << "0\n";
        goto here;
    }
    for (int i = 1; i <= m; ++i)
        for (unsigned j = 0; j < v[i].size(); ++j)
            if(v[i][j] >= m+1 && v[i][j] <= n+m && f[i][v[i][j]] == 1){
                fout << v[i][j]-m << "\n";
                break;
            }
    here:
    fin.close();
    fout.close();
    return 0;
}

