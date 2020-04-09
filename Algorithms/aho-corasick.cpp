#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const string file = "ahocorasick";
const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647;

struct trie{
    trie *f[26], *fail;
    int occ, in;
    trie(){
        memset(f, 0, sizeof(f));
        fail = 0;
        occ = in = 0;
    }
};

string s, v[105];
int n, ans[105];
trie *rad = new trie;
unordered_map<string, int> mp;

void add(trie *&t, string &x, unsigned in, int in2)
{
    if(in == x.size()){
        t->in = in2;
        return;
    }
    if(t->f[x[in]-'a'] == 0)
        t->f[x[in]-'a'] = new trie;
    add(t->f[x[in]-'a'], x, in+1, in2);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> s >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        if(mp.find(v[i]) != mp.end())
            continue;
        add(rad, v[i], 0, i);
        mp[v[i]] = i;
    }
    int p = 0;
    vector<trie*> q;
    q.push_back(rad);
    rad->fail = rad;
    while(p != q.size()){
        trie *t = q[p++];
        for (int i = 0; i < 26; ++i)
            if(t->f[i] != 0){
                q.push_back(t->f[i]);
                trie *fail = t->fail;
                while(fail != rad && fail->f[i] == 0)
                    fail = fail->fail;
                if(fail->f[i] != 0 && fail->f[i] != t->f[i])
                    fail = fail->f[i];
                t->f[i]->fail = fail;
            }
    }
    trie *t = rad;
    for (auto x : s){
        while(t != rad && t->f[x-'a'] == 0)
            t = t->fail;
        if(t->f[x-'a'] != 0)
            t = t->f[x-'a'];
        ++t->occ;
    }
    reverse(q.begin(), q.end());
    for (auto x : q)
        x->fail->occ += x->occ;
    for (auto x : q)
        if(x->in != 0)
            ans[x->in] = x->occ;
    for (int i = 1; i <= n; ++i)
        fout << ans[mp[v[i]]] << "\n";
    return 0;
}
