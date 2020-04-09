#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const string file = "lca";
const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647, nmax = 100005;

int n, test, p, dep[nmax], first[nmax], lg2[nmax*2];
vector<int> v[nmax];
pi pd[20][nmax*2];

void dfs(int nod, int pred)
{
    dep[nod] = dep[pred]+1;
    pd[0][++p] = {dep[nod], nod};
    first[nod] = p;
    for (auto x : v[nod])
        if(x != pred){
            dfs(x, nod);
            pd[0][++p] = {dep[nod], nod};
        }
}

int query(int a, int b)
{
    if(a == b)
        return a;
    a = first[a];
    b = first[b];
    if(a > b)
        swap(a, b);
    int len = lg2[b-a+1];
    return min(pd[len][a], pd[len][b-(1<<len)+1]).ss;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> test;
    for (int i = 2; i <= n; ++i){
        int x;
        fin >> x;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    dfs(1, 0);
    for (int i = 2; i < nmax*2; ++i)
        lg2[i] = lg2[i/2]+1;
    for (int t = 1; (1<<t) <= p; ++t)
        for (int i = 1; i+(1<<t)-1 <= p; ++i)
            pd[t][i] = min(pd[t-1][i], pd[t-1][i+(1<<(t-1))]);
    while(test--){
        int a, b;
        fin >> a >> b;
        fout << query(a, b) << "\n";
    }
    return 0;
}
