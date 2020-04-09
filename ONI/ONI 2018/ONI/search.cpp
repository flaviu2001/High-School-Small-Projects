#include <bits/stdc++.h>

using namespace std;

int n, m, sz[102], r[30], sol[102][5005], first[102][30];
short v[102][5005][30];
char c[102][5005];

int main()
{
    ifstream fin ("search.in");
    ofstream fout ("search.out");
    fin >> n >> m;
    for (int p = 1; p <= n; ++p){
        fin >> c[p];
        sz[p] = strlen(c[p]);
        memset(r, -1, sizeof(r));
        for (int i = sz[p]-1; i >= 0; --i){
            for (int j = 'a'; j <= 'z'; ++j)
                v[p][i][j-'a'] = r[j-'a'];
            r[c[p][i]-'a'] = i;
        }
        for (int j = 'a'; j <= 'z'; ++j)
            first[p][j-'a'] = r[j-'a'];
    }
    --m;
    int k = 0;
    char q;
    fin >> q;
    for (int i = 1; i <= n; ++i){
        sol[i][++sol[i][0]] = first[i][q-'a'];
        if(sol[i][sol[i][0]] != -1)
            ++k;
    }
    fout << k << "\n";
    while(m--){
        fin >> q;
        if(q >= 'a' && q <= 'z'){
            k = 0;
            for (int i = 1; i <= n; ++i){
                if(sol[i][sol[i][0]] != -1)
                    sol[i][sol[i][0]+1] = v[i][sol[i][sol[i][0]]][q-'a'];
                else sol[i][sol[i][0]+1] = -1;
                ++sol[i][0];
                if(sol[i][sol[i][0]] != -1)
                    ++k;
            }
            fout << k << "\n";
        }else{
            k = 0;
            for (int i = 1; i <= n; ++i){
                --sol[i][0];
                if(sol[i][sol[i][0]] != -1)
                    ++k;
            }
            fout << k << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}

