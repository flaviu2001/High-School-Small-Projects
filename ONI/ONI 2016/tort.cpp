#include <fstream>
#define MAX 501
using namespace std;

int n, m, k, v[MAX][MAX], b[MAX][MAX], mint, np;

void read()
{
    freopen ( "tort1.in", "r", stdin );
    scanf ( "%d%d%d", &m, &n, &k );
    for ( int i = 1; i <= m; ++i )
        for ( int j = 1; j <= n; ++j )
        scanf ( "%d", &v[i][j] );
    fclose(stdin);
}

void solve()
{
    int s;
    b[1][1] = v[1][1];
    mint = n * m + 1;
    for ( int i = 2; i <= m; ++i )
        b[i][1] = b[i-1][1] + v[i][1];
    for ( int j = 2; j <= n; ++j )
        b[1][j] = b[1][j] = b[1][j-1] + v[1][j];
    for ( int i = 2; i <= m; ++i )
        for ( int j = 2; j <= n; ++j )
        b[i][j] = b[i][j-1] + b[i-1][j] - b[i-1][j-1] + v[i][j];
    for ( int k1 = 0; k1 <= k; ++k1 )
        for ( int i = m - k1; i <= m; ++i )
            for ( int j = n - k + k1; j <= n; ++j )
            {
                s = b[i][j] - b[i-m + k1][j] - b[i][j-n + k-k1] + b[i-m + k1][j-n + k-k1];
                if ( s < mint ) mint = s, np = 1;
                else if ( s == mint ) ++np;
            }
}

void write()
{
    freopen ( "tort1.out", "w", stdout );
    printf ( "%d\n%d\n",b[m][n] - mint, np );
    fclose(stdout);
}

int main()
{
    read();
    solve();
    write();
    return 0;
}
