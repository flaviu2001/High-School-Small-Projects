#include <bits/stdc++.h>
#define M 10000

using namespace std;

const int offset = 50000;
int n, m, t, v[2][100000];
bool ok[100000];

int main()
{
    ifstream fin ("diamant.in");
    ofstream fout ("diamant.out");
    fin >> n >> m >> t;
    int mx = 0, mn = 0;
    v[1][0+offset] = 1;
    bool now = 0;
    for (int i1 = 1; i1 <= n; ++i1)
        for (int j1 = 1; j1 <= m; ++j1){
            memset(v[now], 0, sizeof(v[now]));
            int mx2 = 0, mn2 = 0;
            int x = i1*j1;
            for (int i = mn; i <= mx; ++i)
                if(v[now][i+offset] + v[1-now][i+offset] > 0){
                    mx2 = max(mx2, i+x);
                    mn2 = min(mn2, i-x);
                    v[now][i+offset] = (v[now][i+offset] + v[1-now][i+offset])%M;
                    v[now][i+x+offset] = (v[now][i+x+offset] + v[1-now][i+offset])%M;
                    v[now][i-x+offset] = (v[now][i-x+offset] + v[1-now][i+offset])%M;
                }
            mx = max(mx, mx2);
            mn = min(mn, mn2);
            now = 1-now;
        }
    if(abs(t) <= 44100)
        fout << v[1-now][t+offset] << "\n";
    else fout << "0\n";
    fin.close();
    fout.close();
    return 0;
}

