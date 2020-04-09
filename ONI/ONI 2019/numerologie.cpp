#include <bits/stdc++.h>

using namespace std;

vector<int> primes, pr2, g[1300];
int n, m, c[1300], v[1300], guy[1300];
bool used[1300], ok[1300];

int main()
{
    ifstream fin ("numerologie.in");
    ofstream fout ("numerologie.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= m; ++i){
        fin >> c[i];
        if(c[i] != -1)
            primes.push_back(i);
    }
    for (int i = 1; i <= n; ++i){
        for (auto x : primes)
            if(v[i]%x == 0){
                if(x*x > m)
                    guy[i] = x;
                if(!ok[x] && x*x <= m){
                    pr2.push_back(x);
                    ok[x] = 1;
                }
                g[x].push_back(i);
            }
    }
    int mn = 2000000000;
    for (int cf = 0; cf < (1<<pr2.size()); ++cf){
        bool good = true;
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            used[i] = 0;
        memset(ok, 0, sizeof(ok));
        for (int j = 0; j < pr2.size(); ++j)
            if(cf&(1<<j)){
                sum += c[pr2[j]];
                for (auto x : g[pr2[j]])
                    used[x] = 1;
            }
        for (int i = 1; i <= n; ++i)
            if(!used[i] && guy[i] != 0){
                used[i] = 1;
                if(!ok[guy[i]]){
                    sum += c[guy[i]];
                    ok[guy[i]] = 1;
                }
            }
        for (int i = 1; i <= n; ++i)
            good &= used[i];
        if(good)
            mn = min(mn, sum);
    }
    fout << mn << "\n";
    return 0;
}
