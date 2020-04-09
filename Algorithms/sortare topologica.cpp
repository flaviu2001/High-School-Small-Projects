#include <fstream>
#include <vector>

using namespace std;

int n, m, p, ordine[50005];
bool ok[50005];
vector<int> v[50005];

void dfs(int x)
{
    ok[x] = 1;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            dfs(v[x][i]);
    ordine[++p] = x;
}

int main()
{
    ifstream fin ("sortaret.in");
    ofstream fout ("sortaret.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
        if(!ok[i])
            dfs(i);
    for (int i = n; i; --i)
        fout << ordine[i] << " ";
    fin.close();
    fout.close();
    return 0;
}

