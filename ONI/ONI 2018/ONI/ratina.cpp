#include <bits/stdc++.h>

using namespace std;

struct trie{
    trie *f[30];

    trie(){
        memset(f, 0, sizeof(f));
    }
};

int n, test, sz[10005], v[15];
trie *rad = new trie;
trie **pos[10005];
char c[2005];

int main()
{
    ifstream fin ("ratina.in");
    ofstream fout ("ratina.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i){
        fin >> c;
        int m = strlen(c);
        sz[i] = m;
        pos[i] = new trie*[m+1];
        trie *t = rad;
        for (int j = 0; j < m; ++j){
            pos[i][j] = t;
            int q = c[j]-'a';
            if(t->f[q] == NULL)
                t->f[q] = new trie;
            t = t->f[q];
        }
        pos[i][m] = t;
    }
    while(test--){
        fin >> n;
        for (int i = 1; i <= n; ++i)
            fin >> v[i];
        int m, lo = 0, hi = sz[v[1]], ans;
        for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2){
            bool ok = true;
            for (int i = 1; i <= n; ++i)
                if(pos[v[i]][m] != pos[v[1]][m]){
                    ok = false;
                    break;
                }
            if(ok){
                ans = m;
                lo = m+1;
            }else hi = m-1;
        }
        fout << ans << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

