#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "cli";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

struct trie{
    trie *f[26];
    bool hasend;
    trie(){
        memset(f, 0, sizeof(f));
        hasend = 0;
    }
};

int n, k, p;
trie *rad = new trie;
vector<pi> v[1000005];
vector<int> pd[1000005];
bool has[1000005];

void dfs_construct(trie *nod, int prev = -1, int cost = 0)
{
    if(prev == -1){
        p = 1;
        prev = 1;
        pd[p].resize(k+2);
    }else if(nod->hasend){
        v[++p].push_back({prev, cost});
        v[prev].push_back({p, cost});
        has[p] = 1;
        pd[p].resize(k+2);
        prev = p;
        cost = 0;
    }else{
        int cnt = 0;
        for (int i = 0; i <= 'z'-'a'; ++i)
            if(nod->f[i] != NULL)
                ++cnt;
        if(cnt >= 2){
            v[++p].push_back({prev, cost});
            v[prev].push_back({p, cost});
            pd[p].resize(k+2);
            prev = p;
            cost = 0;
        }
    }
    for (int i = 0; i <= 'z'-'a'; ++i)
        if(nod->f[i] != NULL)
            dfs_construct(nod->f[i], prev, cost+1);
}

void dfs(int x, int prev = 0)
{
    for (int i = 1; i <= k; ++i)
        pd[x][i] = inf;
    if(has[x])
        pd[x][1] = 0;
    pd[x][0] = 0;
    for (auto y : v[x])
        if(y.ff != prev){
            dfs(y.ff, x);
            vector<int> tmp(k+2);
            for (int i = 1; i <= k; ++i)
                tmp[i] = inf;
            for (int i = 0; i <= k && pd[x][i] != inf; ++i){
                tmp[i] = min(pd[x][i], tmp[i]);
                for (int j = 1; i+j <= k && pd[y.ff][j] != inf; ++j)
                    tmp[i+j] = min(tmp[i+j], pd[x][i] + y.ss + pd[y.ff][j]);
            }
            for (int i = 1; i <= k; ++i)
                pd[x][i] = tmp[i];
        }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i){
        string s;
        fin >> s;
        trie *t = rad;
        for (auto x : s){
            if(t->f[x-'a'] == NULL)
                t->f[x-'a'] = new trie;
            t = t->f[x-'a'];
        }
        t->hasend = true;
    }
    dfs_construct(rad);
    dfs(1);
    for (int i = 1; i <= k; ++i)
        fout << pd[1][i]*2 << "\n";
    return 0;
}
