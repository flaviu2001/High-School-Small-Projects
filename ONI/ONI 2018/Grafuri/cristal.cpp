#include <fstream>
#include <vector>

using namespace std;

vector<int> v[1005];
int n, m, num, low[1005], dfn[1005], start, nrfii, art[1005];

void biconex(int t, int tu)
{
    low[t] = dfn[t] = ++num;
    for (unsigned i = 0; i < v[t].size(); ++i){
        int x = v[t][i];
        if(x == tu)
            continue;
        if(dfn[x] == -1){
            if(t == start)
                ++nrfii;
            biconex(x, t);
            low[t] = min(low[t], low[x]);
            if(low[x] >= dfn[t] && t != start && !art[t]){
                art[t] = 1;
            }
        }else low[t] = min(low[t], dfn[x]);
    }
}

int main()
{
    ifstream fin ("cristal.in");
    ofstream fout ("cristal.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 0; i < n+2; ++i)
        low[i] = dfn[i] = -1;
    for (int i = 1; i <= n; ++i)
        if(dfn[i] == -1){
            num = 0;
            start = i;
            nrfii = 0;
            biconex(i, -1);
            if(nrfii > 1)
                art[i] = 1;
        }
    for (int i = 1; i <= n; ++i)
        if(!art[i])
            fout << i << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

