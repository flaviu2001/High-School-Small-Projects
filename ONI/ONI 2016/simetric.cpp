#include <fstream>
#define MAX 405

using namespace std;

int v[MAX][MAX], b[MAX][MAX];
int n, m, maxr, r[MAX];

void read()
{
    freopen ( "simetric.in", "r", stdin );
    scanf ( "%d%d", &n, &m );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            scanf ( "%d", &v[i][j] );
}

void solve()
{
    int i, j, k;
    for ( i = n; i; --i )
        for ( j = m; j; --j )
        {
            for ( k = 1; i + k <= n && j + k <= m && v[i+k][j] == v[i][j+k]; ++k )
            b[i][j] = min( b[i+1][j+1] + 1, k );
            if ( b[i][j] > maxr )
                maxr = b[i][j];
            ++r[b[i][j]];
        }
    for ( i = maxr - 1; i; --i )
        r[i] += r[i+1];
}

void write()
{
    freopen ( "simetric.out", "w", stdout );
    printf ( "%d\n", n * m );
    for ( int i = 1; i <= maxr; ++i )
        printf ( "%d\n", r[i] );
}

int main()
{
    read();
    solve();
    write();
    return 0;
}
