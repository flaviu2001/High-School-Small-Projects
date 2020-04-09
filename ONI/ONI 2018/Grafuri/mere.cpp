#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct apple{
    int x, y, z, r;
}r[220];

vector<int> v[220];
int n, m, k;
bool ok[220];

double dist(int i, int j)
{
    return sqrt((r[i].x - r[j].x) * (r[i].x - r[j].x) + (r[i].y - r[j].y) * (r[i].y - r[j].y));
}

void dfs(int x)
{
    if(!ok[x])
        ++k;
    ok[x] = 1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            dfs(v[x][i]);
}

int main()
{
    ifstream fin ("mere.in");
    ofstream fout ("mere.out");
    fin >> n;
    for (int i = 0; i < n; ++i){
        int x, y, z, R;
        fin >> x >> y >> z >> R;
        r[i].x = x;
        r[i].y = y;
        r[i].z = z;
        r[i].r = R;
        for (int j = 0; j < i; ++j)
            if(dist(i, j) <= r[i].r + r[j].r){
                if(r[i].z + r[i].r > r[j].z + r[j].r)
                    v[i].push_back(j);
                else v[j].push_back(i);
            }
    }
    dfs(0);
    fout << k << "\n";
    fin.close();
    fout.close();
    return 0;
}

