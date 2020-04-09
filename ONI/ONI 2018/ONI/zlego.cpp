#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int nmax = 250005;
int test, n, v[nmax], urm[nmax], g[nmax], tt[nmax];
ll sol[nmax];

int main()
{
    ifstream fin ("zlego.in");
    ofstream fout ("zlego.out");
    fin >> test;
    while(test--){
        fin >> n;
        for (int i = 0; i < n; ++i)
            fin >> v[i];
        for (int i = 0; i < n; ++i)
            fin >> sol[i];
        int k = 0;
        urm[0] = 0;
        for (int i = 1; i < n; ++i){
            while(k > 0 && v[k] != v[i])
                k = urm[k-1];
            if(v[k] == v[i])
                ++k;
            urm[i] = k;
        }
        memset(g, 0, sizeof(g));
        memset(tt, -1, sizeof(g));
        for (int i = n-1; i >= 0; --i){
            tt[i] = urm[i]-1;
            ++g[urm[i]-1];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if(g[i] == 0)
                q.push(i);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if(tt[k] != -1){
                --g[tt[k]];
                sol[tt[k]] += sol[k];
                if(g[tt[k]] == 0)
                    q.push(tt[k]);
            }
        }
        for (int i = 0; i < n; ++i)
            fout << sol[i] << "\n";
    }
    return 0;
}

