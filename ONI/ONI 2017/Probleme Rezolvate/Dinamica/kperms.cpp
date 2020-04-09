#include <fstream>

using namespace std;

int n, k;
long long dp[1005][1005];

void read();
long long solve();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    ifstream fin ("kperms.in");
    fin >> n >> k;
    fin.close();
}

long long solve()
{
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            dp[i][j] = ((i-j+1) * dp[i-1][j-1] + j * dp[i-1][j]) % 666013;
    return dp[n][k];
}

void write()
{
    ofstream fout ("kperms.out");
    fout << solve() << "\n";
    fout.close();
}
