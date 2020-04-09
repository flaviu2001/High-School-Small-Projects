#include <bits/stdc++.h>

using namespace std;

int n, k, m, p, test, ans[20005], c[35];
string s[20005][20], t[30005];
unordered_map<string, int> mp;

int main()
{
    ifstream fin ("sabin.in");
    ofstream fout ("sabin.out");
    fin >> n >> k >> m >> p >> test;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= k; ++j)
            fin >> s[i][j];
        string now;
        for (int j1 = 1; j1 <= p; ++j1){
            for (int j2 = 1; j2 <= k; ++j2)
                now += s[i][j2][j1-1];
            ++mp[now];
        }
    }
    for (int i = 1; i <= m; ++i)
        fin >> t[i];
    for (int i = 1; i <= test; ++i){
        int x, all = 0, rem = 0;
        fin >> x;
        for (int j = 1; j <= k; ++j)
            fin >> c[j];
        string sall, srem;
        for (int j = 1; j <= x; ++j){
            if(x != 0)
                for (int j2 = 1; j2 <= k; ++j2)
                    sall += t[c[j2]][j-1];
            if(x != p)
                for (int j2 = 1; j2 <= k; ++j2)
                    srem += t[c[j2]][j-1];
        }
        if(x != p)
                for (int j2 = 1; j2 <= k; ++j2)
                    srem += t[c[j2]][x];
        if(x == 0)
            all = n;
        else all = mp[sall];
        if(x != n)
            rem += mp[srem];
        fout << all-rem << "\n";
    }
    return 0;
}
