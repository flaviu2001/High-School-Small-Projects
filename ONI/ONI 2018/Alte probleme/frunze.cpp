#include <bits/stdc++.h>

using namespace std;

const int64_t M = 29989;
int64_t s[100][100], v[100][100], n, p, ans;

int main()
{
    ifstream fin ("frunze.in");
    ofstream fout ("frunze.out");
    fin >> n >> p;
    s[1][1] = 1;
    for (int64_t i = 2; i < 100; ++i)
        for (int64_t j = 1; j <= i; ++j)
            s[i][j] = (s[i-1][j-1] + j*s[i-1][j])%M;
    v[1][0] = v[1][1] = 1;
    for (int64_t i = 2; i <= n; ++i){
        v[i][0] = 1;
        for (int64_t j = 1; j <= i; ++j)
            v[i][j] = (v[i-1][j] + v[i-1][j-1])%M;
    }
    int64_t fact = 1;
    for (int64_t i = 1; i <= n-p; ++i)
        fact = (fact*i)%M;
    ans = (v[n][p]*s[n-2][n-p]*fact)%M;
    if(ans < 0)
        ans += M;
    fout << ans << "\n";
    fin.close();
    fout.close();
    return 0;
}
