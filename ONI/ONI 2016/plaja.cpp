#include <fstream>
#define NMAX 2016

using namespace std;

int m, n, a, b, u, x[128], y[128];
int s[NMAX][NMAX], res;

int main()
{
    int i, j, x1, y1, x2, y2;
    bool ok(0);
    freopen ( "plaja.in", "r", stdin );
    freopen ( "plaja.out", "w", stdout );
    scanf ( "%d%d%d", &a, &b, &u );
    for ( i = 1; i <= u; ++i )
        scanf ( "%d%d", &x[i], &y[i] );
    scanf ( "%d", &n );
    for ( i = 1; i <= n; ++i )
    {
        scanf ( "%d%d%d%d", &x1, &y1, &x2, &y2 );
        for ( j = 1, ok = 1; j <= u && ok; ++j )
            if ( x1 <= x[j] && x[j] <= x2 && y1 <= y[j] && y[j] <= y2 )
                ok = 0;
        if ( !ok )
            continue;
        ++res;
        ++s[x1][y1];
        ++s[x2+1][y2+1];
        --s[x1][y2+1];
        --s[x2+1][y1];
    }
    printf ( "%d ", res );
    for ( i = 1; i <= a; ++i )
        for ( j = 1; j <= b; ++j )
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    for ( i = 1; i <= u; ++i )
        s[x[i]][y[i]] = 1;
    for ( i = 1; i <= a; ++i )
        for ( j = 1; j <= b; ++j )
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + ( s[i][j] != 0 );
    res = 0;
    for ( scanf ( "%d", &m ); m--; )
    {
        scanf ( "%d %d %d %d", &x1, &y1, &x2, &y2 );
        res += s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1] == 0;
    }
    printf ( "%d\n", res );
    return 0;
}
