#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int n, m, g[nmax];
bool ok[nmax*3];
vector<int> euler;
vector< pair<int, int> > v[nmax];

void df(int x)
{
    for (vector< pair<int, int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[it->second]){
            ok[it->second] = 1;
            df(it->first);
        }
    euler.push_back(x);
}

int main()
{
    ifstream fin ("ratway.in");
    ofstream fout ("ratway.out");
    fin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
        ++g[x];
        ++g[y];
    }
    vector<int> t;
    for (int i = 1; i <= n; ++i){
        if(g[i]%2 == 1)
            t.push_back(i);
        if(t.size() == 2){
            v[t[0]].push_back({t[1], m++});
            v[t[1]].push_back({t[0], m-1});
            t.clear();
        }
    }
    if(m%2 == 1)
        v[1].push_back({1, m++});
    df(1);
    fout << m << "\n";
    for (unsigned i = 1; i < euler.size(); ++i)
        if(i%2 == 1)
            fout << euler[i-1] << " " << euler[i] << "\n";
        else fout << euler[i] << " " << euler[i-1] << "\n";
    return 0;
}

