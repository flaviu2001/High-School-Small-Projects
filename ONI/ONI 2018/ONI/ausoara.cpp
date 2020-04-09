#include <bits/stdc++.h>

using namespace std;

int f[1000005], mn[1000005], n, v[1005], solsz;
vector< pair<int, int> > sol;

int main()
{
    ifstream fin ("ausoara.in");
    ofstream fout ("ausoara.out");
    fin >> n;
    for (int i = 1; i <= 1000000; ++i)
        mn[i] = 2000000000;
    for (int i = 1; i <= n; ++i){
        int m;
        fin >> m;
        if(m == 1){
            int x;
            fin >> x;
            mn[x] = min(mn[x], 1);
            ++f[x];
        }else{
            int k = 1;
            fin >> v[1];
            v[m+1] = 2000000000;
            for (int i = 2; i <= m+1; ++i){
                if(i != m+1)
                    fin >> v[i];
                if(v[i] == v[i-1])
                    ++k;
                else{
                    ++f[v[i-1]];
                    mn[v[i-1]] = min(mn[v[i-1]], k);
                    if(f[v[i-1]] == n){
                        solsz += mn[v[i-1]];
                        sol.push_back(make_pair(v[i-1], mn[v[i-1]]));
                    }
                    k = 1;
                }
            }

        }
    }
    fout << solsz << " ";
    for (vector< pair<int, int> >::iterator it = sol.begin(); it != sol.end(); ++it){
        int k = it->second;
        int x = it->first;
        for (int i = 1; i <= k; ++i)
            fout << x << " ";
    }
    fin.close();
    fout.close();
    return 0;
}

