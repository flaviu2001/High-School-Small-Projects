#include <bits/stdc++.h>

using namespace std;

const int nmax = 5005;
int n, m, restrict, p = 1, mapto[nmax], c[105][105], f[105][105], prv[nmax];
bool ok[nmax];
vector<int> v[nmax], t[105][105];
pair<int, int> e[nmax];
set<int> mp, sol;

bool bfs()
{
    queue<int> q;
    q.push(1);
    memset(ok, 0, sizeof(ok));
    ok[1] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (vector<int>::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(!ok[*it] && f[k][*it] < c[k][*it]){
                ok[*it] = 1;
                prv[*it] = k;
                q.push(*it);
                if(*it == n)
                    return true;
            }
    }
    return false;
}

int main()
{
    ifstream fin ("ghizi.in");
    ofstream fout ("ghizi.out");
    fin >> n >> restrict;
    for (int i = 1; i <= n; ++i){
        fin >> e[i].first >> e[i].second;
        mp.insert(e[i].first);
        mp.insert(e[i].second);
    }
    mapto[0] = 1;
    for (auto x : mp)
        mapto[x] = ++p;
    for (int i = 1; i <= n; ++i){
        e[i].first = mapto[e[i].first];
        e[i].second = mapto[e[i].second];
        v[e[i].first].push_back(e[i].second);
        v[e[i].second].push_back(e[i].first);
        t[e[i].first][e[i].second].push_back(i);
        ++c[e[i].first][e[i].second];
    }
    e[n+1] = {1, 2};
    v[1].push_back(2);
    v[2].push_back(1);
    c[1][2] = restrict;
    ++n;
    m = n;
    n = p;
    int flow = 0;
    while(bfs())
        for (vector<int>::iterator it = v[n].begin(); it != v[n].end(); ++it)
            if(ok[*it]){
                prv[n] = *it;
                int mn = 2000000000, k = n;
                while(k != 1){
                    mn = min(mn, c[prv[k]][k]-f[prv[k]][k]);
                    k = prv[k];
                }
                if(mn == 0)
                    continue;
                flow += mn;
                k = n;
                while(k != 1){
                    f[prv[k]][k] += mn;
                    f[k][prv[k]] -= mn;
                    k = prv[k];
                }
            }
    for (int i = 2; i < p; ++i)
        for (int j = i+1; j <= p; ++j)
            for (int k = 1; k <= f[i][j]; ++k)
                sol.insert(t[i][j][k-1]);
    fout << sol.size() << "\n";
    for (auto x : sol)
        fout << x << " ";
    return 0;
}

