#include <bits/stdc++.h>

using namespace std;

struct trie{
    trie *f[2];
    int st;
    trie(){
        memset(f, 0, sizeof(f));
        st = 0;
    }
};

int n, pr[100005], mx=-1, st, dr;
trie *rad = new trie;

int main()
{
    ifstream fin ("xormax.in");
    ofstream fout ("xormax.out");
    fin >> n;
    trie *t = rad;
    for (int i = 0; i < 20; ++i){
        t->f[0] = new trie;
        t->st = 0;
        t = t->f[0];
    }
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        pr[i] = pr[i-1]^x;
        int sol = 0, pw = (1<<20), where;
        x = pr[i];
        t = rad;
        while(pw){
            where = t->st;
            int bit = 0;
            if(x >= pw)
                x -= pw, ++bit;
            if(t->f[1-bit] != NULL){
                if(1-bit == 1)
                    sol += pw;
                t = t->f[1-bit];
            }else{
                if(bit == 1)
                    sol += pw;
                t = t->f[bit];
            }
            pw /= 2;
        }
        if((sol^pr[i]) > mx){
            mx = sol^pr[i];
            st = where+1;
            dr = i;
        }
        x = pr[i];
        pw = (1<<20);
        t = rad;
        while(pw){
            t->st = i;
            int bit = 0;
            if(x >= pw)
                x -= pw, ++bit;
            if(t->f[bit] == NULL)
                t->f[bit] = new trie;
            t = t->f[bit];
            pw /= 2;
        }
    }
    fout << mx << " " << st << " " << dr << "\n";
    return 0;
}

