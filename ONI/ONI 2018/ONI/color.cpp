#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[16005];
int n, fr[16005], tt[16005];
bool ok[16005], sus[16005], jos[16005];

void dfr(int x)
{
    ok[x] = 1;
    int f[2], F = -1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            f[++F] = v[x][i];
    if(F == 1){
        fr[f[0]] = f[1];
        fr[f[1]] = f[0];
    }
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            dfr(v[x][i]);
}

void df(int x)
{
    ok[x] = 1;
    int f[2], F = -1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            f[++F] = v[x][i];
    if(F == -1)
        jos[x] = 1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            df(v[x][i]);
    if(F == 1)
        jos[x] = (!jos[f[0]]) && (!jos[f[1]]);

}

void dfs(int x)
{
    ok[x] = 1;
    if(x != 1){
        sus[x] = (!sus[tt[x]]) || jos[fr[x]];
    }else
        sus[x] = 1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            dfs(v[x][i]);
}

int main()
{
    ifstream fin ("color.in");
    ofstream fout ("color.out");
    fin >> n;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        tt[y] = x;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfr(1);
    memset(ok, 0, sizeof(ok));
    df(1);
    memset(ok, 0, sizeof(ok));
    dfs(1);
    int k = 0;
    for (int i = 1; i <= n; ++i)
        if(sus[i] && jos[i])
            ++k;
    fout << k << "\n";
    for (int i = 1; i <= n; ++i)
        if(sus[i] && jos[i])
            fout << i << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

