#include <bits/stdc++.h>

using namespace std;

int n, m;
vector< pair<int, int> > v[100005];
bool ok[100005];

bool bfs(int g)
{
    memset(ok, 0, sizeof(ok));
    queue<int> q;
    q.push(1);
    ok[1] = 1;
    while(!q.empty()){
        int k = q.front();
        if(k == n)
            return true;
        q.pop();
        for (vector< pair<int, int> >::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(!ok[it->first] && it->second >= g){
                ok[it->first] = 1;
                q.push(it->first);
            }
    }
    return false;
}

int main()
{
    ifstream fin ("transport2.in");
    ofstream fout ("transport2.out");
    fin >> n >> m;
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    int lo = 1, hi = 10000, m, ans;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
        if(bfs(m)){
            ans = m;
            lo = m+1;
        }else hi = m-1;
    fout << ans << "\n";
    return 0;
}

