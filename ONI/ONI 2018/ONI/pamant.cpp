#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100005], sol, things;
int n, m, num, low[100005], dfn[100005], start, nrfii, art[100005];

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
                sol.push_back(t);
            }
        }else low[t] = min(low[t], dfn[x]);
    }
}

int main()
{
    ifstream fin ("pamant.in");
    ofstream fout ("pamant.out");
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
            things.push_back(i);
            num = 0;
            start = i;
            nrfii = 0;
            biconex(i, -1);
            if(nrfii > 1)
                sol.push_back(i);
        }
    fout << things.size() << "\n";
    for(unsigned i = 0; i < things.size(); ++i)
        fout << things[i] << " ";
    fout << "\n";
    sort(sol.begin(), sol.end());
    fout << sol.size() << "\n";
    for (unsigned i = 0; i < sol.size(); ++i)
        fout << sol[i] << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

