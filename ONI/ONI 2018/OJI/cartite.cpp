#include <fstream>
#include <vector>
#include <queue>
 
using namespace std;
 
ifstream fin ("cartite.in");
ofstream fout ("cartite.out");
int dx[] = {0, 1, 0, -1, 0, 2, 0, -2, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 2, 0, -2, 0, 1, -1, 1, -1};
int test, n, m, px, py, vulpi, galerii, v[205][205], ind[205][205], p;
pair<int, int> nd[205];
bool ok[205];
vector< pair<int, int> > g[205];
 
bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m;
}
 
void df(int x)
{
    for (unsigned i = 0; i < g[x].size(); ++i)
        if(!ok[g[x][i].second]){
            ok[g[x][i].second] = 1;
            df(g[x][i].first);
        }
    fout << nd[x].first << " " << nd[x].second << "\n";
}
 
int main()
{
    fin >> test >> n >> m >> px >> py >> vulpi;
    while(vulpi--){
        int x, y, radius;
        fin >> x >> y >> radius;
        switch(radius){
            case 0:
                v[x][y] = -1;
                break;
            case 1:
                for (int i = 0; i < 4; ++i)
                    v[x+dx[i]][y+dy[i]] = -1;
                break;
            case 2:
                for (int i = 0; i < 12; ++i)
                    v[x+dx[i]][y+dy[i]] = -1;
        }
    }
    fin >> galerii;
    for (int i = 1; i <= galerii; ++i){
        int x, y, xx, yy;
        fin >> x >> y >> xx >> yy;
        if(v[x][y] == 0)
            v[x][y] = -2;
        if(v[xx][yy] == 0)
            v[xx][yy] = -2;
        if(ind[x][y] == 0){
            ind[x][y] = ++p;
            nd[p] = make_pair(x, y);
        }
        if(ind[xx][yy] == 0){
            ind[xx][yy] = ++p;
            nd[p] = make_pair(xx, yy);
        }
        g[ind[x][y]].push_back(make_pair(ind[xx][yy], i));
        g[ind[xx][yy]].push_back(make_pair(ind[x][y], i));
    }
    if(test == 1){
        if(v[px][py] == -2)
            fout << px << " " << py << " 0\n";
        else{
            queue< pair<int, int> > q;
            q.push(make_pair(px, py));
            v[px][py] = 1;
            bool ok = true;
            while(!q.empty() && ok){
                pair<int, int> k = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                    if(check(k.first + dx[i], k.second + dy[i]) && v[k.first + dx[i]][k.second + dy[i]] == 0){
                        v[k.first + dx[i]][k.second + dy[i]] = v[k.first][k.second] + 1;
                        q.push(make_pair(k.first + dx[i], k.second + dy[i]));
                    }else if(check(k.first + dx[i], k.second + dy[i]) && v[k.first + dx[i]][k.second + dy[i]] == -2){
                        fout << k.first + dx[i] << " " << k.second + dy[i] << " " << v[k.first][k.second] << "\n";
                        ok = false;
                        break;
                    }
            }
        }
    }else{
        int i;
        for (i = 1; i <= p; ++i)
            if(v[nd[i].first][nd[i].second] != -1)
                break;
        df(i);
    }
    fin.close();
    fout.close();
    return 0;
}
