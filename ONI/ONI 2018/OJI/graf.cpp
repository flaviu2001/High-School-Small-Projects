#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, m, home, work, D[2][7505], f[7505];
vector<int> v[7505];

void bf(int p, int d[])
{
    queue<int> q;
    q.push(p);
    d[p] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(d[v[k][i]] == 0){
                d[v[k][i]] = d[k] + 1;
                q.push(v[k][i]);
            }
    }
    for (int i = 1; i <= n; ++i)
        if(d[i] > 0)
            --d[i];

}

int main()
{
    ifstream fin ("graf.in");
    ofstream fout ("graf.out");
    fin >> n >> m >> home >> work;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bf(home, D[0]);
    bf(work, D[1]);
    for (int i = 1; i <= n; ++i)
        if(D[0][i] + D[1][i] == D[0][work])
            ++f[D[0][i]];
    int nodes = 0;
    for (int i = 1; i <= n; ++i)
        if(D[0][i] + D[1][i] == D[0][work] && f[D[0][i]] == 1)
            ++nodes;
    fout << nodes << "\n";
    for (int i = 1; i <= n; ++i)
        if(D[0][i] + D[1][i] == D[0][work] && f[D[0][i]] == 1)
            fout << i << " ";
    fin.close();
    fout.close();
    return 0;
}

