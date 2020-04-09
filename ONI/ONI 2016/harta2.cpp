#include <fstream>
#define nmax 1501
#define nnmax 1002

using namespace std;

bool Map[nmax][nmax], ox[nmax], oy[nmax];
int build[nnmax][4], ix[nmax], iy[nmax], v[nnmax];

int main()
{
    freopen ( "harta2.in", "r", stdin );
    freopen ( "harta2.out", "w", stdout );
    int test, n, m, k;
    scanf ( "%d%d%d%d", &test, &n, &m, &k );
    if ( test == 1 )
    {
        int i, a1, a2, b1, b2, maxp = -1, q = 0;
        for ( i = 1; i <= k; ++i )
        {
            scanf( "%d%d%d%d", &a1, &a2, &b1, &b2 );
            if ( b1 - a1 == b2 - a2 && b1 - a1 - 1 > maxp )
                maxp = b1 - a1 - 1;
            v[i] = max ( b1 - a1 + 1, b2 - a2 + 1 );
        }
        for ( i = 1; i <= k; ++i )
            if ( v[i] <= maxp )
                ++q;
        printf ( "%d %d", ( maxp + 2 ) * ( maxp + 2 ),  q );
        return 0;
    }
    else
    {
        int i, j, p;
        for ( i = 1; i <=k; ++i )
        {
            scanf ( "%d%d%d%d", &build[i][0], &build[i][1], &build[i][2], &build[i][3] );
            for ( j = build[i][0]; j <= build[i][2]; ++j )
                ox[j] = 1;
            for ( j = build[i][1]; j <= build[i][3]; ++j )
                oy[j] = 1;
        }
        for ( i = 2; i <= n; ++i )
        {
            ix[i] = ix[i-1];
            if ( ox[i] == 0 && ox[i-1] == 0 )
                ++ix[i];
        }
        for ( i = 2; i <= m; ++i )
        {
            iy[i] = iy[i-1];
            if ( oy[i] == 0 && oy[i-1] == 0 )
                ++iy[i];
        }
        n -= ix[n], m -= iy[m];
        for ( p = 1; p <= k; ++p )
        {
            build[p][0] -= ix[build[p][0]];
            build[p][1] -= iy[build[p][1]];
            build[p][2] -= ix[build[p][2]];
            build[p][3] -= iy[build[p][3]];
            for ( i = build[p][1]; i <= build[p][3]; ++i )
                Map[ build [ p ] [ 0 ] ] [ i ] = 1;
            for ( i = build[p][0] + 1; i <= build[p][2]; ++i )
                Map[ i ] [ build [ p ] [ 3 ] ] = 1;
            for ( i = build[p][3] - 1; i >= build[p][1]; --i )
                Map[ build [ p ] [ 2 ] ] [ i ] = 1;
            for ( i = build[p][2] - 1; i >= build[p][0]; --i )
                Map[ i ] [ build [ p ] [ 1 ] ] = 1;
        }
        for ( i = 1; i <= n; ++i )
        {
            for ( j = 1; j <= m; ++j )
                printf ( "%d ", Map[i][j] );
            printf ( "\n" );
        }
    }
    return 0;
}
