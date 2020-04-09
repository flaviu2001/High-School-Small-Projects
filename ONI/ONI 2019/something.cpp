#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int n, m, color[nmax];
vector<int> v[nmax], r, cycle;
bool ok[nmax];

void dfs(int x, int pred = 0)
{
    r.push_back(x);
    ok[x] = 1;
    for (auto y : v[x])
        if(!ok[y])
            dfs(y, x);
        else if(y != pred && cycle.size() == 0){
            cycle = r;
            int first = 0;
            while(cycle[first] != y)
                ++first;
            if(first != 0)
                cycle.erase(cycle.begin(), cycle.begin()+first);
        }
    r.pop_back();
}

void dfssol(int x, int col)
{
    color[x] = col;
    for (auto y : v[x])
        if(color[y] == 0)
            dfssol(y, col);
}

int main()
{
    ifstream fin ("something.in");
    ofstream fout ("something.out");
    fin >> n >> m;
    if(m == n-1){
        fout << "-1\n";
        return 0;
    }
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    color[cycle[0]] = 1;
    color[cycle[1]] = 2;
    color[cycle[2]] = 3;
    dfssol(cycle[0], 1);
    dfssol(cycle[1], 2);
    dfssol(cycle[2], 3);
    for (int i = 1; i <= n; ++i)
        fout << color[i] << " ";
    return 0;
}

