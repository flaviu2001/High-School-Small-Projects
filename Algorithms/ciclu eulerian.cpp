#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "ciclueuler";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, m;
vector<int> v[nmax], sol;
bool ok[nmax*5];
pi e[nmax*5];

void dfs(int x)
{
    for (int i = v[x].size()-1; i >= 0; --i)
        if(!ok[v[x][i]]){
            ok[v[x][i]] = 1;
            int y = e[v[x][i]].ff;
            if(y == x)
                y = e[v[x][i]].ss;
            dfs(y);
        }
    sol.push_back(x);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        e[i] = {x, y};
        v[x].push_back(i);
        v[y].push_back(i);
    }
    bool any = false;
    for (int i = 1; i <= n; ++i)
        if(v[i].size()%2 == 1)
            any = true;
    if(any){
        fout << "-1";
        return 0;
    }
    dfs(1);
    sol.pop_back();
    for (auto x : sol)
        fout << x << " ";
    return 0;
}
