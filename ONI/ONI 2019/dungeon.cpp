#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "dungeon";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100015;

int test, n, cuplaj1[2][nmax], cuplaj2[2][nmax], go1[nmax], go2[nmax];
vector<int> a1[nmax], a2[nmax], v[nmax], sol;
bool ok[nmax];

void dfs(int nod, vector<int> a[], int cuplaj[][nmax], int go[], int pred = 0)
{
    if(a[nod].empty())
        return;
    for (auto x : a[nod])
        if(x != pred)
            dfs(x, a, cuplaj, go, nod);
    for (auto x : a[nod])
        if(x != pred)
            cuplaj[0][nod] += cuplaj[1][x];
    cuplaj[1][nod] = cuplaj[0][nod];
    int orig = cuplaj[1][nod];
    for (auto x : a[nod])
        if(x != pred && cuplaj[1][nod] < orig-cuplaj[1][x]+cuplaj[0][x]+1){
            cuplaj[1][nod] = orig-cuplaj[1][x]+cuplaj[0][x]+1;
            go[nod] = x;
        }
}

void build(int nod, vector<int> a[], int go[], int in = 1, int pred = 0)
{
    if(in){
        v[nod].push_back(go[nod]);
        v[go[nod]].push_back(nod);
    }
    for (auto x : a[nod])
        if(x != pred){
            if(in && x == go[nod])
                build(x, a, go, 0, nod);
            else build(x, a, go, 1, nod);
        }
}

void finish(int nod)
{
    sol.push_back(nod);
    ok[nod] = 1;
    for (auto x : v[nod])
        if(!ok[x])
            finish(x);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test;
    while(test--){
        //Reset memory
        memset(cuplaj1, 0, sizeof(cuplaj1));
        memset(cuplaj2, 0, sizeof(cuplaj2));
        memset(go1, 0, sizeof(go1));
        memset(go2, 0, sizeof(go2));
        for (int i = 0; i < nmax; ++i){
            a1[i].clear();
            a2[i].clear();
            v[i].clear();
        }
        fin >> n;
        for (int i = 1; i < n; ++i){
            int x, y;
            fin >> x >> y;
            a1[x].push_back(y);
            a1[y].push_back(x);
        }
        for (int i = 1; i < n; ++i){
            int x, y;
            fin >> x >> y;
            a2[x].push_back(y);
            a2[y].push_back(x);
        }
        for (int i = 1; i <= n; ++i){
            int x, y;
            fin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(n%2 == 1){
            fout << "-1\n";
            continue;
        }
        dfs(1, a1, cuplaj1, go1);
        dfs(n+1, a2, cuplaj2, go2);
        if(cuplaj1[1][1] + cuplaj2[1][n+1] != n){
            fout << "-1\n";
            continue;
        }
        build(1, a1, go1);
        build(n+1, a2, go2);
        sort(v[1].begin(), v[1].end());
        sol.clear();
        memset(ok, 0, sizeof(ok));
        sol.push_back(1);
        ok[1] = 1;
        if(v[1].size() > 1)
            finish(v[1][1]);
        if(sol.size() != n+n){
            fout << "-1\n";
            continue;
        }
        for (auto x : sol)
            fout << x << " ";
        fout << "\n";
    }
    return 0;
}
