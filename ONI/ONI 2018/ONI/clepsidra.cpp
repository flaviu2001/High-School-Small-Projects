#include <bits/stdc++.h>
#define ff first
#define ss second
#define M 666013

using namespace std;

int n, m, dfn[200005], low[200005], num, f[200005];
vector<int> v[200005];
stack< pair<int, int> > q;

void add_sol(int x, int u)
{
    vector<int> r;
    int tx, ty;
    do{
        tx = q.top().ff, ty = q.top().ss;
        r.push_back(tx);
        r.push_back(ty);
        q.pop();
    }while(tx != x || ty != u);
    sort(r.begin(), r.end());
    ++f[r[0]];
    for (int i = 1; i < r.size(); ++i)
        if(r[i] != r[i-1])
            ++f[r[i]];
}

void dfs(int u, int tu)
{
    dfn[u] = low[u] = ++num;
    for (unsigned i = 0; i < v[u].size(); ++i){
        int x = v[u][i];
        if(x == tu)
            continue;
        if(dfn[x] == -1){
            q.push(make_pair(u, x));
            dfs(x, u);
            low[u] = min(low[u], low[x]);
            if(low[x] >= dfn[u])
                add_sol(u, x);
        }else low[u] = min(low[u], dfn[x]);
    }
}

int lgpw(int x)
{
    int p = 1, y = 2;
    while(x)
        if(x%2 == 0){
            y = (1LL*y*y)%M;
            x >>= 1;
        }else{
            p = (1LL*p*y)%M;
            --x;
        }
    p -= 2;
    if(p < 0)
        p += M;
    return p;
}

int main()
{
    ifstream fin ("clepsidra.in");
    ofstream fout ("clepsidra.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        dfn[i] = -1;
    dfs(1, -1);
    for (int i = 1; i <= n; ++i)
        if(f[i] > 1)
            //cout << i << ": " << f[i] << "\n",
            fout << lgpw(f[i]) << "\n";
        else fout << "0\n";
    fin.close();
    fout.close();
    return 0;
}

