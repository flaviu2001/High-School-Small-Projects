#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m, c[100005], sz[100005];
vector< pair<int, int> > v[100005];
bool ok[100005], imp[100005], need[100005];
long long sol;

int df(int x)
{
    ok[x] = 1;
    bool needx = imp[x];
    for (vector< pair<int, int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[it->first])
            needx |= df(it->first);
    need[x] = needx;
    return needx;
}

void parcurgere(int x)
{
    ok[x] = 1;
    for (vector< pair<int, int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[it->first] && need[it->first]){
            parcurgere(it->first);
            sol += it->second*2;
            //sol += c[x];
        }
}

int main()
{
    ifstream fin ("posta2.in");
    ofstream fout ("posta2.out");
    fin >> n >> m;
    for (int i = 2; i <= n; ++i){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    for (int i = 1; i <= n; ++i)
        fin >> c[i];
    int aux;
    for (int i = 1; i <= m; ++i){
        fin >> aux;
        imp[aux] = 1;
    }
    df(aux);
    for (int i = 1; i <= n; ++i)
        for (vector< pair<int, int> >::iterator it = v[i].begin(); it != v[i].end(); ++it)
            if(need[it->first])
                ++sz[i];
    memset(ok, 0, sizeof(ok));
    parcurgere(aux);
    int mx = 0;
    for (int i = 1; i <= n; ++i)
        if(need[i]){
            mx = max(mx, (sz[i]-1)*c[i]);
            sol += (sz[i]-1)*c[i];
        }
    sol -= mx;
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

