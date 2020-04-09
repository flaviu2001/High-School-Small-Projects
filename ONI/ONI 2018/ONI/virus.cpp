#include <bits/stdc++.h>
using namespace std;

struct trie{
    vector<int> v;
    trie *f[2], *fail;
    int n0;
    trie(){
        n0 = 0;
        fail = NULL;
        memset(f, 0, sizeof(f));
    }
};

trie *rad = new trie;
char c[1000005], qq[10005];
int n, m, sol[1005], vf;
vector<trie*> q;

void bf()
{
    vf = -1;
    q.push_back(rad);
    rad->fail = rad;
    while(vf != int(q.size())-1){
        trie *t = q[++vf];
        for (int i = 0; i <= 1; ++i)
            if(t->f[i]){
                trie *fail = t->fail;
                for (; fail != rad && fail->f[i] == NULL; fail = fail->fail);
                if(fail->f[i] != NULL && fail->f[i] != t->f[i])
                    fail = fail->f[i];
                t->f[i]->fail = fail;
                q.push_back(t->f[i]);
            }
    }
    rad->fail = NULL;
}

int main()
{
    ifstream fin ("virus.in");
    ofstream fout ("virus.out");
    fin >> m >> n >> c;
    for (int i = 1; i <= n; ++i){
        trie *t = rad;
        fin >> m >> qq;
        for (int j = 0; j < m; ++j){
            int ch = qq[j] - '0';
            if(t->f[ch] == NULL)
                t->f[ch] = new trie;
            t = t->f[ch];
        }
        t->v.push_back(i);
    }
    bf();
    trie *t = rad;
    m = strlen(c);
    for (int i = 0; i < m; ++i){
        int ch = c[i]-'0';
        for (; t->f[ch] == NULL && t != rad; t = t->fail);
        if(t->f[ch] != NULL)
            t = t->f[ch];
        ++t->n0;
    }
    for (int i = vf; i >= 0; --i){
        t = q[i];
        if(t->fail != NULL)
            t->fail->n0 += t->n0;
        for (vector<int>::iterator it = t->v.begin(); it != t->v.end(); ++it)
            sol[*it] = t->n0;
    }
    for (int i = 1; i <= n; ++i)
        fout << sol[i] << "\n";
    fin.close();
    fout.close();
    return 0;
}

