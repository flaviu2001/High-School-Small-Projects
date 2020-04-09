#include <bits/stdc++.h>

using namespace std;

int n, m, p, ordine[2][150005], nxt[2][150005], vecini[2][150005], ord[150005], no, k, mapto[150005];
bool ok[2][150005], vis[150005];
vector<int> v[2][150005], sol, r[2][150005], ctc[150005];

void dfs(int x, int caz)
{

    ok[caz][x] = 1;
    for (unsigned i = 0; i < v[caz][x].size(); ++i)
        if(!ok[caz][v[caz][x][i]])
            dfs(v[caz][x][i], caz);
    ordine[caz][++p] = x;
}

void solve(int caz)
{
    memset(ok, 0, sizeof(ok));
    p = 0;
    for (int i = 1; i <= k; ++i)
        if(!ok[caz][i])
            dfs(i, caz);
    for (int i = 0; i <= k+2; ++i)
        ok[caz][i] = 0;
    for (int i = 1; i <= k; ++i){
        int x = ordine[caz][i];
        ok[caz][x] = 1;
        for (vector<int>::iterator it = v[1-caz][x].begin(); it != v[1-caz][x].end(); ++it)
            if(!ok[caz][*it])
                nxt[caz][*it] = x;
    }
    for (int i = k; i; --i){
        int x = ordine[caz][i];
        vecini[caz][nxt[caz][x]] += vecini[caz][x]+1;
    }
}

void df(int x)
{
    vis[x] = 1;
    for (vector<int>::iterator it = r[0][x].begin(); it != r[0][x].end(); ++it)
        if(!vis[*it])
            df(*it);
    ord[++no] = x;
}

void dft(int x)
{
    vis[x] = 0;
    mapto[x] = k;
    ctc[k].push_back(x);
    for(vector<int>::iterator it = r[1][x].begin(); it != r[1][x].end(); ++it)
        if(vis[*it])
            dft(*it);
}

int main()
{
    ifstream fin ("drumuri2.in");
    ofstream fout ("drumuri2.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        r[0][x].push_back(y);
        r[1][y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if(!vis[i])
            df(i);
    for (int i = n; i; --i)
        if(vis[ord[i]]){
            ++k;
            dft(ord[i]);
        }
    for (int i = 1; i <= n; ++i)
        for (vector<int>::iterator it = r[0][i].begin(); it != r[0][i].end(); ++it)
            if(mapto[i] != mapto[*it]){
                v[0][mapto[i]].push_back(mapto[*it]);
                v[1][mapto[*it]].push_back(mapto[i]);
            }
    solve(0);
    solve(1);
    for (int i = 1; i <= k; ++i)
        if(vecini[0][i] + vecini[1][i] == k-1)
            for (vector<int>::iterator it = ctc[i].begin(); it != ctc[i].end(); ++it)
                sol.push_back(*it);
    sort(sol.begin(), sol.end());
    fout << sol.size() << "\n";
    for (vector<int>::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << *it << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

