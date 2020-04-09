#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pi;

int n, m, p, ans[220005];
vector<int> v[100005];
pi edges[220005];
bool ok[100005];

void dfs(int x)
{
    ok[x] = 1;
    for (auto e : v[x]){
        int y = edges[e].ff;
        if(y == x)
            y = edges[e].ss;
        if(ok[y]){
            if(ans[e] == 0)
                ans[e] = ++p;
            continue;
        }
        ans[e] = ++p;
        dfs(y);
    }
}

int main()
{
    ifstream fin ("nogcd.in");
    ofstream fout ("nogcd.out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        edges[i] = {x, y};
        v[x].push_back(i);
        v[y].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= m; ++i)
        fout << edges[i].ff << " " << edges[i].ss << " " << ans[i] << "\n";
    return 0;
}
