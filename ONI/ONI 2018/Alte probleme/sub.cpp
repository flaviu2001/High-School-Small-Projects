#include <bits/stdc++.h>

using namespace std;

struct trie{
    trie* f[26];
    int cnt, idx;
    bool deleted;
    trie(){
        cnt = 0;
        deleted = 0;
        memset(f, 0, sizeof(f));
    }
};

trie *rada = new trie, *radb = new trie;
char str[305];
int n, m, p = 1, sol, total;

void df_count(trie*t)
{
    for (int i = 0; i < 26; ++i)
        if(t->f[i] != NULL && t->f[i]->cnt == n){
            ++total;
            df_count(t->f[i]);
        }
}

int main()
{
    ifstream fin ("sub.in");
    ofstream fout ("sub.out");
    fin >> n;
    rada->idx = 1;
    for (int i = 1; i <= n; ++i){
        fin >> str;
        int strsz = strlen(str);
        unordered_set<int> s;
        ++rada->cnt;
        for (int tt = 0; tt < strsz; ++tt){
            trie *t = rada;
            for (int j = tt; j < strsz; ++j){
                int q = str[j]-'a';
                if(t->f[q] == NULL){
                    t->f[q] = new trie;
                    t->f[q]->idx = ++p;
                }
                t = t->f[q];
                if(s.find(t->idx) == s.end()){
                    ++t->cnt;
                    s.insert(t->idx);
                }
                if(t->cnt <= i-2)
                    break;
            }
        }
    }
    df_count(rada);
    fin >> m;
    for (int i = 1; i <= m; ++i){
        fin >> str;
        int strsz = strlen(str);
        for (int tt = 0; tt < strsz; ++tt){
            trie *t = rada;
            for (int j = tt; j < strsz; ++j){
                int q = str[j]-'a';
                if(t->f[q] == NULL || t->f[q]->cnt != n){
                    break;
                }
                t = t->f[q];
                if(!t->deleted){
                    ++sol;
                    t->deleted = true;
                }
            }
        }
    }
    fout << total-sol << "\n";
    return 0;
}

