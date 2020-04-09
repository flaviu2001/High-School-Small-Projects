#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, c[1005][1005], f[1005][1005], fiu[1005];
bool ok[1005];
vector<int> v[1005], sol;
pair<int, int> edges[10005];
 
bool bfs()
{
    memset(ok, 0, sizeof(ok));
    queue<int> q;
    q.push(1);
    ok[1] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (vector<int>::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(f[k][*it] != c[k][*it] && !ok[*it]){
                fiu[*it] = k;
                ok[*it] = 1;
                q.push(*it);
                if(*it == n)
                    return 1;
            }
    }
    return 0;
}
 
int main()
{
    ifstream fin ("critice.in");
    ofstream fout ("critice.out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, z;
        fin >> x >> y >> z;
        edges[i] = make_pair(x, y);
        c[x][y] = z;
        c[y][x] = z;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int flow = 0;
    while(bfs())
        for (vector<int>::iterator it = v[n].begin(); it != v[n].end(); ++it)
            if(f[*it][n] != c[*it][n] && ok[*it]){
                int fmin = 1<<29;
                fiu[n] = *it;
                for (int i = n; i != 1; i = fiu[i])
                    fmin = min(fmin, c[fiu[i]][i] - f[fiu[i]][i]);
                if(fmin == 0)
                    continue;
                for (int i = n; i != 1; i = fiu[i]){
                    f[fiu[i]][i] += fmin;
                    f[i][fiu[i]] -= fmin;
                }
                flow += fmin;
            }
    bfs();
    for (int i = 1; i <= m; ++i){
        int x = edges[i].first;
        int y = edges[i].second;
        if((ok[x] && !ok[y])||(!ok[x] && ok[y]))
            sol.push_back(i);
    }
    fout << sol.size() << "\n";
    for (vector<int>::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << *it << "\n";
    fin.close();
    fout.close();
    return 0;
}
