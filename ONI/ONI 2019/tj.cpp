#include <bits/stdc++.h>

using namespace std;

int test, n, m, g[260];
vector<int> v[260];
bitset<260> bs[260];
bool ok[260];

int dfs(int x)
{
    ok[x] = 1;
    int val = 1;
    for (auto y : v[x])
        if(!ok[y])
            val += dfs(y);
    return val;
}

bool conn_check()
{
    memset(ok, 0, sizeof(ok));
    return dfs(1) == n;
}

int main()
{
    ifstream fin ("tj.in");
    ofstream fout ("tj.out");
    fin >> test;
    while(test--){
        for (int i = 1; i <= 256; ++i)
            v[i].clear(),
            bs[i].reset(),
            bs[i][i] = 1;
        fin >> n >> m;
        for (int i = 1; i <= m; ++i){
            int x, y;
            fin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
            bs[x][y] = bs[y][x] = 1;
        }
        if(!conn_check()){
            fout << "NU\n";
            continue;
        }
        memset(ok, 0, sizeof(ok));
        int rem = n;
        while(rem > 1){
            bool good = true;
            for (int i = 1; i <= n; ++i)
                if(!ok[i])
                    for (int j = 1; j <= n; ++j)
                        if(!ok[j] && i != j && ((bs[i]&bs[j]) == bs[j])){
                            --rem;
                            for (auto x : v[j])
                                bs[x][j] = 0;
                            ok[j] = 1;
                            good = false;
                        }
            if(good)
                break;
        }
        fout << (rem == 1 ? "DA" : "NU") << "\n";
    }
    return 0;
}

