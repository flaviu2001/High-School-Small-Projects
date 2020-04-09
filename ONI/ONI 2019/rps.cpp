#include <bits/stdc++.h>

using namespace std;

struct trie{
    trie *f[3];
    int best, bnext, fii;
    trie(){
        memset(f, 0, sizeof(f));
        best = 0;
        bnext = 0;
        fii = 0;
    }
};

ifstream fin ("rps.in");
ofstream fout ("rps.out");
trie *rad = new trie;
int n, k, w, d, con[1000];
char noc[3];
string s;

void add(int it, trie *t)
{
    if(it < k){
        if(t->f[con[s[it]]] == NULL)
            t->f[con[s[it]]] = new trie;
        ++t->fii;
        add(it+1, t->f[con[s[it]]]);
    }else{
        ++t->fii;
        t->best = d*(t->fii);
        return;
    }
    int best = 0, bnext = 0;
    if(t->f[1] != NULL)
        best += t->f[1]->fii*w;
    if(t->f[0] != NULL)
        best += t->f[0]->best;
    int best2 = 0;
    if(t->f[2] != NULL)
        best2 += t->f[2]->fii*w;
    if(t->f[1] != NULL)
        best2 += t->f[1]->best;
    if(best2 > best){
        best = best2;
        bnext = 1;
    }
    int best3 = 0;
    if(t->f[0] != NULL)
        best3 += t->f[0]->fii*w;
    if(t->f[2] != NULL)
        best3 += t->f[2]->best;
    if(best3 > best){
        best = best3;
        bnext = 2;
    }
    t->best = best;
    t->bnext = bnext;
}

void show(int it, trie *t)
{
    if(it < k){
        fout << noc[t->bnext];
        if(t->f[t->bnext] != NULL)
            show(it+1, t->f[t->bnext]);
        else{
            for (int i = it+1; i < k; ++i)
                fout << "P";
            fout << "\n";
        }
    }else fout << "\n";
}

int main()
{
    con['P'] = 0, con['R'] = 1, con['S'] = 2;
    noc[0] = 'P', noc[1] = 'R', noc[2] = 'S';
    fin >> n >> k >> w >> d;
    for (int t = 1; t <= n; ++t){
        fin >> s;
        add(0, rad);
        show(0, rad);
    }
    return 0;
}

