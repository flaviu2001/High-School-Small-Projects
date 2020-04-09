#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 1000005;
int n, k, v[nmax], f[nmax/10+5], mn = nmax;
 
int main()
{
    ifstream fin ("maxk.in");
    ofstream fout ("maxk.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    int cnt = 0, id = 0;
    for (int i = 1; i <= n; ++i){
        ++f[v[i]];
        if(f[v[i]] == k+1)
            ++cnt;
    }
    if(cnt == 0){
        fout << "0\n";
        return 0;
    }
    while(cnt){
        ++id;
        --f[v[id]];
        if(f[v[id]] == k)
            --cnt;
    }
    ++id;
    mn = min(mn, id-1);
    for (int i = 1; i <= n; ++i){
        ++f[v[i]];
        if(f[v[i]] == k+1){
            bool found = false;
            for (int j = id; j <= n; ++j)
                if(v[j] == v[i]){
                    found = true;
                    for (int t = id; t <= j; ++t)
                        --f[v[t]];
                    id = j+1;
                    break;
                }
            if(!found)
                break;
        }
        //cout << i << " " << id << "\n";
        mn = min(mn, id-i-1);
    }
    fout << mn << "\n";
    return 0;
}
