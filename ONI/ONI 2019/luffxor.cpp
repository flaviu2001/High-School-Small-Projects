#include <bits/stdc++.h>

using namespace std;

struct trie{
    trie *f[2];
    int guys;
    trie(){
        guys = 0;
        memset(f, 0, sizeof(f));
    }
    ~trie(){
        for (int i = 0; i < 2; ++i)
            if(f[i] != NULL){
                delete f[i];
                f[i] = 0;
            }
    }
};

int test, p, v[200005];
trie *rad = new trie;

int main()
{
    ifstream fin ("luffxor.in");
    ofstream fout ("luffxor.out");
    fin >> test;
    while(test--){
        int tt, pw = (1<<30), y, x, k, ans = 0;
        trie *t = rad;
        fin >> tt >> x;
        switch(tt){
            case 0:
                y = x;
                v[++p] = x;
                while(pw){
                    int bit = 0;
                    if(y >= pw){
                        y -= pw;
                        bit = 1;
                    }
                    ++t->guys;
                    if(t->f[bit] == NULL)
                        t->f[bit] = new trie;
                    t = t->f[bit];
                    pw /= 2;
                }
                ++t->guys;
                break;
            case 1:
                y = v[x];
                while(pw){
                    int bit = 0;
                    if(y >= pw){
                        y -= pw;
                        bit = 1;
                    }
                    --t->f[bit]->guys;
                    if(t->f[bit]->guys == 0){
                        delete t->f[bit];
                        t->f[bit] = 0;
                        break;
                    }
                    t = t->f[bit];
                    pw /= 2;
                }
                break;
            case 2:
                fin >> k; ++k, y = k;
                while(pw){
                    int bit1 = 0, bit2 = 0;
                    if(y >= pw){
                        y -= pw;
                        bit1 = 1;
                    }
                    if(x >= pw){
                        x -= pw;
                        bit2 = 1;
                    }
                    if(bit1 == 0 && t->f[bit2] == NULL)
                        break;
                    if(bit1 == 0)
                        t = t->f[bit2];
                    else{
                        if(t->f[bit2] != NULL)
                            ans += t->f[bit2]->guys;
                        if(t->f[1-bit2] == NULL)
                            break;
                        t = t->f[1-bit2];
                    }
                    pw /= 2;
                }
                fout << ans << "\n";
                break;
        }
    }
    return 0;
}

