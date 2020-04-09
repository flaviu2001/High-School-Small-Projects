#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "metrou2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

struct chain{
    int st, uses, nuses;
};

struct cycle{
    int st, dr, val[2][2]; //00 no uses, 11 uses both, 01 uses dr, 10 uses st
    cycle(){
        memset(val, 0, sizeof(val));
    }
};

int n, m, c[nmax], g[nmax], pd[nmax];
vector<chain> l1;
vector<cycle> l2;
vector<int> v[nmax], r, fat;
bool ok[nmax], yes[30][30];

void dfs(int x, int prev)
{
    ok[x] = 1;
    r.push_back(x);
    if(g[x] == 2)
        for (auto y : v[x])
            if(y != prev)
                dfs(y, x);
}

void dfs2(int x, int prev, int source)
{
    ok[x] = 1;
    r.push_back(x);
    for (auto y : v[x])
        if(y != prev && y != source)
            dfs2(y, x, source);
}

void dfs3(int x, int prev)
{
    ok[x] = 1;
    r.push_back(x);
    for (auto y : v[x])
        if(y != prev)
            dfs3(y, x);
}


int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> c[i];
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        ++g[x];
        ++g[y];
    }
    //corner when no nodes above degree 3
    bool any = false;
    for (int u = 1; u <= n; ++u)
        if(g[u] > 2){
            any = true;
            fat.push_back(u);
            ok[u] = 1;
            for (auto x : v[u])
                if(!ok[x] && g[x] <= 2){
                    r.clear();
                    int st = u, dr = -1;
                    dfs(x, u);
                    if(g[r.back()] > 2){
                        dr = r.back();
                        r.pop_back();
                    }
                    if(dr == -1){
                        int uses = 0, nuses = 0;

                        pd[0] = c[r[0]];
                        if(r.size() > 1)
                            pd[1] = max(c[r[0]], c[r[1]]);
                        for (int i = 2; i < r.size(); ++i)
                            pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
                        uses = pd[r.size()-1];

                        pd[0] = 0;
                        if(r.size() > 1)
                            pd[1] = c[r[1]];
                        for (int i = 2; i < r.size(); ++i)
                            pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
                        nuses = pd[r.size()-1];
                        l1.push_back({u, uses, nuses});
                    }else{
                        //corner when cycle len is 1?
                        cycle now;
                        now.st = st, now.dr = dr;

                        if(r.size() > 2){
                            pd[0] = 0;
                            pd[1] = c[r[1]];
                            for (int i = 2; i < r.size()-1; ++i)
                                pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
                            now.val[0][0] = pd[r.size()-2];
                        }

                        pd[0] = c[r[0]];
                        if(r.size() > 1)
                            pd[1] = max(c[r[0]], c[r[1]]);
                        for (int i = 2; i < r.size(); ++i)
                            pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
                        now.val[1][1] = pd[r.size()-1];

                        pd[0] = 0;
                        if(r.size() > 1)
                            pd[1] = c[r[1]];
                        for (int i = 2; i < r.size(); ++i)
                            pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
                        now.val[0][1] = pd[r.size()-1];

                        pd[0] = c[r[0]];
                        if(r.size() > 1)
                            pd[1] = max(c[r[0]], c[r[1]]);
                        for (int i = 2; i < r.size()-1; ++i)
                            pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
                        if(r.size() > 1)
                            now.val[1][0] = pd[r.size()-2];
                        l2.push_back(now);
                    }
                }
        }
    if(!any){
        int mn = 2, I;
        for (int i = 1; i <= n; ++i)
            if(g[i] < mn){
                mn = g[i];
                I = i;
            }
        if(mn == 1){
            dfs3(I, 0);
            pd[0] = c[r[0]];
            if(r.size() > 1)
                pd[1] = max(c[r[0]], c[r[1]]);
            for (int i = 2; i < r.size(); ++i)
                pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
            fout << pd[r.size()-1] << "\n";
            return 0;
        }else{
            dfs2(1, v[1][0], 1);
            pd[0] = c[r[0]];
            if(r.size() > 1)
                pd[1] = max(c[r[0]], c[r[1]]);
            for (int i = 2; i < r.size(); ++i)
                pd[i] = max(pd[i-1], pd[i-2]+c[r[i]]);
            fout << pd[r.size()-1] << "\n";
            return 0;
        }
    }
    for (int i = 0; i < fat.size()-1; ++i)
        for (int j = i+1; j < fat.size(); ++j)
            for (auto x : v[fat[i]])
                if(x == fat[j])
                    yes[i][j] = yes[j][i] = 1;
    int ans = 0;
    for (int t = 0; t < (1<<fat.size()); ++t){
        int now = 0;
        for (int i = 0; i < fat.size(); ++i)
            if(t&(1<<i)){
                ok[fat[i]] = 1;
                now += c[fat[i]];
            }else ok[fat[i]] = 0;
        bool good = true;
        for (int i = 0; i < fat.size()-1; ++i)
            for (int j = i+1; j < fat.size(); ++j)
                if(ok[fat[i]] && ok[fat[j]] && yes[i][j])
                    good = false;
        if(!good)
            continue;
        for (auto l : l1)
            if(ok[l.st])
                now += l.nuses;
            else now += l.uses;
        for (auto l : l2)
            now += l.val[1-ok[l.st]][1-ok[l.dr]];
        ans = max(ans, now);
    }
    fout << ans << "\n";
    return 0;
}
