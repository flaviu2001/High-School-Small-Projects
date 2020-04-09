#include <bits/stdc++.h>

using namespace std;

struct edge{
    int x, y;
};

edge mkE(int x, int y)
{
    edge aux;
    aux.x = x;
    aux.y = y;
    return aux;
}

int n, sum[205], c[205], ans = 2000000007, totalsum, a1, a2;
bool flag[205], iskid[205][205];
edge e[205];
vector<int> v[205], ss;
bool ok[205];

int nod(edge aux, int x)
{
    return (aux.x == x ? aux.y : aux.x);
}

void dfkid(int x)
{
    ss.push_back(x);
    ok[x] = 1;
    sum[x] = c[x];
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it){
        int y = nod(e[*it], x);
        if(!ok[y]){
            e[*it] = mkE(x, y);
            dfkid(y);
            sum[x] += sum[y];
            for (vector<int>::iterator lit = ss.begin(); lit != ss.end(); ++lit)
                if(*lit)
                    iskid[*lit][x] = 1;
            iskid[x][y] = 1;
        }
    }
    ss.pop_back();
}

int dfs(int x)
{
    ok[x] = 1;
    int tot = c[x];
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it){
        int y = e[*it].y;
        if(!ok[y] && !flag[*it]){
            int now = dfs(y);
            tot += now;
            if(max(a1-now, now) < max(a1-a2, a2))
                a2 = now;
        }
    }
    return tot;
}

int main()
{
    ifstream fin ("petrica.in");
    ofstream fout ("petrica.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> c[i];
        totalsum += c[i];
    }
    int cnt = 0, x, y;
    while(fin >> x >> y){
        ++cnt;
        e[cnt] = mkE(x, y);
        v[x].push_back(cnt);
        v[y].push_back(cnt);
    }
    dfkid(1);
    for (int i = 1; i < n-1; ++i)
        for (int j = i+1; j < n; ++j){
            flag[i] = flag[j] = 1;
            memset(ok, 0, sizeof(ok));
            int x, s1, s2;
            if (iskid[e[i].y][e[j].y]){
                x = e[i].y, y = e[j].y;
                s1 = sum[x]-sum[y];
                s2 = sum[y];
            }else if (iskid[e[j].y][e[i].y]){
                x = e[j].y, y = e[i].y;
                s1 = sum[x]-sum[y];
                s2 = sum[y];
            }else{
                x = e[i].y, y = e[j].y;
                s1 = sum[x];
                s2 = sum[y];
            }
            a1 = totalsum-s1-s2, a2 = 0;
            dfs(1);
            int mx = max(s1, max(s2, max(a1-a2, a2)));
            int mn = min(s1, min(s2, min(a1-a2, a2)));
            if(mx-mn < ans)
                ans = mx-mn;
            flag[i] = flag[j] = 0;
        }
    fout << ans << "\n";
    return 0;
}

