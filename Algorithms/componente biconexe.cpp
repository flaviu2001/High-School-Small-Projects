#include <bits/stdc++.h>

using namespace std;

int n, m, p, dfn[100005], low[100005], nrfii, nrart;
bool ok[100005], art[100005];
vector<int> v[100005];
stack< pair<int, int> > s;
vector< unordered_set<int> > sol;

void add_comp(int y, int x)
{
    sol.push_back({});
    pair<int, int> pr;
    do{
        pr = s.top();
        s.pop();
        sol.back().insert(pr.first);
        sol.back().insert(pr.second);
    }while(!((pr.first == x && pr.second == y) || (pr.first == y && pr.second == x)));
}

void dfs(int x, int pred = 0)
{
    ok[x] = 1;
    dfn[x] = ++p;
    low[x] = dfn[x];
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it){
        if(!ok[*it]){
            if(pred == 1)
                ++nrfii;
            s.push({x, *it});
            dfs(*it, x);
            low[x] = min(low[x], low[*it]);
            if(low[*it] >= dfn[x]){
                if(!art[x])
                    ++nrart;
                art[x] = 1;
                add_comp(*it, x);
            }
        }else
            low[x] = min(low[x], dfn[*it]);
    }
}

int main()
{
    ifstream fin ("biconex.in");
    ofstream fout ("biconex.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    if(nrfii > 1 && !art[1]){
        art[1] = 1;
        ++nrart;
    }
    fout << sol.size() << "\n";
    for (vector< unordered_set<int> >::iterator it = sol.begin(); it != sol.end(); ++it){
        for (unordered_set<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
            fout << *it2 << " ";
        fout << "\n";
    }
    fout << nrart << "\n";
    for (int i = 1; i <= n; ++i)
        if(art[i])
            fout << i << " ";
    return 0;
}

