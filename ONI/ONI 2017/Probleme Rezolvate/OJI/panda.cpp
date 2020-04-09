#include <fstream>
#include <queue>
#define ff first
#define ss second
 
using namespace std;
 
int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
int test, n, m, t, l, c, k, s, t1, num, sec = 2000000000;
int food[505][505];
bool v[505][505], kBin[10];
 
void read();
bool complementary(int);
void lee();
 
int main()
{
    ofstream fout ("panda.out");
    read();
    if(test == 1){
        fout << t1 << "\n";
        fout.close();
        return 0;
    }
    lee();
    fout << sec - 1 << " " << num << "\n";
    fout.close();
    return 0;
}
 
void read()
{
    ifstream fin ("panda.in");
    fin >> test;
    fin >> n >> m >> t;
    fin >> l >> c >> k >> s;
    int p = k;
    for (int i = 1; i <= s; ++i)
        kBin[i] = p % 2,
        p /= 2;
    for (int i = 1; i <= t; ++i){
        int a, b;
        fin >> a >> b;
        food[a][b] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int x;
            fin >> x;
            v[i][j] = complementary(x);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (food[i][j] && !v[i][j])
                food[i][j] = 0;
    --t1;
    fin.close();
}
 
bool complementary(int x)
{
    bool xBin[10];
    for (int i = 1; i <= s; ++i){
        xBin[i] = x % 2,
        x /= 2;
        if (xBin[i] == kBin[i])
            return false;
    }
    ++t1;
    return true;
}
 
void lee()
{
    queue< pair<int, int> > q;
    int r[505][505];
    for (int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            r[i][j] = (v[i][j] ? 0 : -1);
    for (int i = 0; i <= n+1; ++i)
        r[i][0] = r[i][m+1] = -1;
    for (int j = 0; j <= m + 1; ++j)
        r[0][j] = r[n+1][j] = -1;
    r[l][c] = 1;
    q.push(make_pair(l, c));
    while(!q.empty()){
        int k = r[q.front().ff][q.front().ss];
        for (int i = 0; i < 4; ++i)
            if (r[q.front().ff + dx[i]][q.front().ss + dy[i]] == 0){
                r[q.front().ff + dx[i]][q.front().ss + dy[i]] = k + 1;
                q.push(make_pair(q.front().ff + dx[i], q.front().ss + dy[i]));
                if (food[q.front().ff + dx[i]][q.front().ss + dy[i]]){
                    if (r[q.front().ff + dx[i]][q.front().ss + dy[i]] <= sec)
                        sec = r[q.front().ff + dx[i]][q.front().ss + dy[i]],
                        ++num;
                    else return;
                }
            }
        q.pop();
    }
}
