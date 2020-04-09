#include <fstream>
#include <cstring>
#define MAX 1510

using namespace std;

ifstream fin ("sablon3.in");
ofstream fout ("sablon3.out");

bool ok1[MAX][MAX], ok2[MAX][MAX], prt[MAX][MAX];
int n, m;
char s[MAX], c[MAX];

void go1(int n, int m, bool dp[][MAX]);
void go2(int n, int m, bool dp[][MAX]);

int main()
{
    fin >> (s+1) >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> (c+1);
        int n = strlen(s+1);
        int m = strlen(c+1);
        memset(ok1, 0, sizeof(ok1));
        memset(ok2, 0, sizeof(ok2));
        go1(n, m, ok1);
        go2(n, m, ok2);
        bool ok = ok1[1][1];
        for (int i = 1; i <= n; ++i)
            if ('a' <= s[i] && s[i] <= 'z')
                for (int j = 0; j <= m; ++j)
                    if (ok2[i-1][j] && ok1[i+1][j+1])
                        ok = 1;
        fout << ok << '\n';
    }
    fin.close();
    fout.close();
}

void go1(int n, int m, bool dp[][MAX])
{
    memset(prt, 0, sizeof(prt));
    dp[n+1][m+1] = 1;
    prt[n+1][m+1] = 1;
    for (int i = 1; i <= m; ++i)
        prt[n+1][i] = 1;
    for (int i = n; i && s[i] == '*'; --i)
        dp[i][m+1] = 1,
        prt[i][m+1] = 1;
    for (int i = n; i; --i)
        for (int j = m; j; --j)
        {
            if (s[i] == c[j])
                dp[i][j] = dp[i+1][j+1];
            else if (s[i] == '?')
                dp[i][j] = dp[i+1][j+1];
            else if (s[i] == '*')
                dp[i][j] = prt[i+1][j];
            else dp[i][j] = 0;
            prt[i][j] = prt[i][j+1] || dp[i][j];
        }
}

void go2(int n, int m, bool dp[][MAX])
{
    memset(prt, 0, sizeof(prt));
    dp[0][0] = 1;
    prt[0][0] = 1;
    for (int i = 1; i <= m; ++i)
        prt[0][i] = 1;
    for (int i = 1; i <= n && s[i] == '*'; ++i)
        dp[i][0] = 1,
        prt[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (s[i] == c[j])
                dp[i][j] = dp[i-1][j-1];
            else if (s[i] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if (s[i] == '*')
                dp[i][j] = prt[i-1][j];
            else dp[i][j] = 0;
            prt[i][j] = prt[i][j-1] || dp[i][j];
        }
}