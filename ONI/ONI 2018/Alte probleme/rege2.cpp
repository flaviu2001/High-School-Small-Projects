#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int test, n, s, tt[nmax], c[nmax], r[nmax], g[nmax], gg[nmax];
vector< pair<int, int> > v[nmax];

void df(int x, int pred = 0)
{
    tt[x] = pred;
    for (vector< pair<int, int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(it->first != pred){
            df(it->first, x);
            ++g[x];
            ++gg[x];
        }else c[x] = it->second;
}

bool possible(int valmax)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i){
        r[i] = 2000000000;
        g[i] = gg[i];
    }
    for (int i = 1; i <= n; ++i)
        if(g[i] == 0){
            q.push(i);
            r[i] = 0;
        }
    int cnt = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        if(c[k] > valmax)
            return false;
        int ctup = r[k]+c[k];
        if(ctup > valmax){
            ++cnt;
            r[k] = 0;
            ctup = c[k];
        }
        --g[tt[k]];
        r[tt[k]] = min(r[tt[k]], ctup);
        if(g[tt[k]] == 0){
            if(tt[k] == 1)
                cnt += gg[tt[k]];
            else cnt += gg[tt[k]]-1;
            if(tt[k] != 1)
                q.push(tt[k]);
        }
        if(cnt > s)
            return false;
    }
    return true;
}

int main()
{
    ifstream fin ("rege2.in");
    ofstream fout ("rege2.out");
    fin >> test;
    while(test--){
        fin >> n >> s;
        for (int i = 1; i <= n; ++i)
            v[i].clear();
        for (int i = 1; i < n; ++i){
            int x, y, z;
            fin >> x >> y >> z;
            v[x].push_back({y, z});
            v[y].push_back({x, z});
        }
        memset(g, 0, sizeof(g));
        memset(gg, 0, sizeof(gg));
        df(1);
        int st = 0, dr = 2000000000, m, ans = -1;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(possible(m)){
                //cout << m << "\n";
                ans = m;
                dr = m-1;
            }else st = m+1;
        fout << ans << "\n";
    }
    return 0;
}

