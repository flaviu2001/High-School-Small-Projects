#include <bits/stdc++.h>

using namespace std;

int n, m, ubuntz, c[30][30], pd[(1<<18)+1][30], means[2005], p;
vector<int> ub, t[30];
vector< pair<int, int> > v[2005];

void bfs(int x)
{
    int r[2005];
    for (int i = 0; i < 2005; ++i)
        r[i] = 2000000000;
    queue<int> q;
    q.push(x);
    r[x] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (vector< pair<int, int> >::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(r[it->first] > r[k] + it->second){
                r[it->first] = r[k] + it->second;
                q.push(it->first);
            }
    }
    for (vector<int>::iterator it = ub.begin(); it != ub.end(); ++it)
        if(*it != x){
            c[means[x]][means[(*it)]] = r[*it];
            t[means[(*it)]].push_back(means[x]);
        }
}

int rec(int conf, int last)
{
    if(pd[conf][last] != -1)
        return pd[conf][last];
    pd[conf][last] = 2000000000;
    for (vector<int>::iterator it = t[last].begin(); it != t[last].end(); ++it)
        if(conf & (1<<(*it)) && !(*it == 0 && conf != (1<<last)+1))
            pd[conf][last] = min(pd[conf][last], rec(conf ^ (1<<last), *it) + c[*it][last]);
    return pd[conf][last];
}

int main()
{
    ifstream fin ("ubuntzei.in");
    ofstream fout ("ubuntzei.out");
    fin >> n >> m >> ubuntz;
    ub.push_back(1);
    means[1] = 0;
    for (int i = 1; i <= ubuntz; ++i){
        int x;
        fin >> x;
        ub.push_back(x);
        means[x] = ++p;
    }
    ubuntz += 2;
    means[n] = ++p;
    ub.push_back(n);
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    memset(c, -1, sizeof(c));
    memset(pd, -1, sizeof(pd));
    for (vector<int>::iterator it = ub.begin(); it != ub.end(); ++it)
        bfs(*it);
    pd[1][0] = 0;
    fout << rec((1<<ubuntz)-1, p) << "\n";
    fin.close();
    fout.close();
    return 0;
}

