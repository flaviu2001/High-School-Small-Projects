#include <bits/stdc++.h>

using namespace std;

int test, M, m, a, b, ans, v[2005];
unordered_map<int, int> mp;

int pw(int x, int y)
{
    int p = 1;
    while(y)
        if(y%2 == 0){
            x = (1ll*x*x)%M;
            y /= 2;
        }else{
            p = (1ll*p*x)%M;
            --y;
        }
    return p;
}

int main()
{
    ifstream fin ("dlog.in");
    ofstream fout ("dlog.out");
    v[0] = 1;
    fin >> test;
    while(test--){
        mp.clear();
        mp[1] = 0;
        fin >> M >> a >> b;
        m = ceil(sqrt(M));
        for (int i = 1; i < m; ++i){
            v[i] = (1ll*v[i-1]*a)%M;
            mp[v[i]] = i;
        }
        int y = pw(pw(a, m), M-2);
        for (int i = 0; i*m < M; ++i){
            if(mp.find(b) != mp.end()){
                ans = i*m+mp[b];
                break;
            }
            b = (1ll*b*y)%M;
        }
        fout << ans << "\n";
    }
    return 0;
}
