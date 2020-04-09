#include <fstream>
#include <vector>

using namespace std;

vector<int> v[305], r[305]; // r e graful transpus al lui v
bool ok[305][305], ko[305][305];
int k;

void dfs(int x, vector<int> w[], bool o[])
{
    o[x] = 1;
    ++k;
    for(unsigned i = 0; i < w[x].size(); ++i)
        if(!o[w[x][i]])
            dfs(w[x][i], w, o);
}

int main()
{
    ifstream fin ("bile1.in");
    ofstream fout ("bile1.out");
    int n, m;
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        r[y].push_back(x);
    }
    int sol = 0;
    for (int i = 1; i <= n; ++i){
        k = 0;
        dfs(i, v, ok[i]);
        if(k > (n+1)/2){
            ++sol;
            continue;
        }
        k = 0;
        dfs(i, r, ko[i]);
        if(k > (n+1)/2)
            ++sol;
    }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}
