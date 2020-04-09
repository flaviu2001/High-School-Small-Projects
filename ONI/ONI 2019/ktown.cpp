#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (1LL<<61)-1;
ll sol, n, k, b[3005], v[3005], pd[3004][3004];

int main()
{
    ifstream fin ("ktown.in");
    ofstream fout ("ktown.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        b[i] = v[i]-(i-1)*k;
        v[i] = b[i];
        pd[i][0] = INF;
    }
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            pd[i][j] = min(pd[i][j - 1], pd[i - 1][j] + abs(b[j] - v[i]));
    fout << pd[n][n] << "\n";
    return 0;
}

