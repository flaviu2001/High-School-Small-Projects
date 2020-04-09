#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, v[100005], tot[1<<20], r[21][1<<20];
ll sol;

int main()
{
    ifstream fin ("aiacubiti.in");
    ofstream fout ("aiacubiti.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 0; i < 20-1; ++i){
        for (int j = i+1; j < 20; ++j)
            for (int t = 1; t <= n; ++t){
                int x = v[t]^((1<<i)+(1<<j));
                sol += tot[x]-r[i][x]-r[j][x];
            }
        for (int j = i+1; j < 20; ++j)
            for (int t = 1; t <= n; ++t){
                int x = v[t]^((1<<i)+(1<<j));
                ++tot[x];
                ++r[j][x];
            }
    }
    fout << sol/6 << "\n";
    fin.close();
    fout.close();
    return 0;
}
