#include <fstream>
#include <vector>

using namespace std;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};
int n, m, t, sz;
bool ok[252][252], v[40005];
vector<int> s, r;

bool check(int x, int y)
{
    return (x > 0 && y > 0 && x <= n && y <= m);
}

void fill(int x, int y)
{
    if(check(x, y) && ok[x][y]){
        ok[x][y] = 0;
        ++sz;
        for(int i = 0; i < 8; ++i)
            fill(x+dx[i], y+dy[i]);
    }
}

int functia_fara_nume()
{
    if(r.size() == 0)
        return 0;
    int mx = 0;
    v[0] = 1;
    s.push_back(0);
    for (unsigned k = 0; k < r.size(); ++k){
        int e = s.size();
        for (int i = 0; i < e; ++i)
            if(s[i]+r[k] <= t && !v[s[i]+r[k]]){
                v[s[i]+r[k]] = 1;
                s.push_back(s[i]+r[k]);
                mx = max(mx, s[i]+r[k]);
            }
    }
    return mx;
}

int main()
{
    ifstream fin ("parcela.in");
    ofstream fout ("parcela.out");
    fin >> n >> m >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> ok[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(ok[i][j]){
                sz = 0;
                fill(i, j);
                r.push_back(sz);
            }
    fout << functia_fara_nume() << "\n";
    fin.close();
    fout.close();
    return 0;
}

