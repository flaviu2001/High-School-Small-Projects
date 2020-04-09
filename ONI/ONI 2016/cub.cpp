#include <fstream>
#define nmax 201

using namespace std;


long long int a[nmax][nmax], b[nmax][nmax];
bool ciur[8000001];

int main()
{
    freopen ( "cub.in", "r", stdin );
    freopen ( "cub.out", "w", stdout );
    long long int test, n;
    scanf ( "%lld%lld", &test, &n );
    if ( test == 1 )
    {
        int k = 0, i = 1, j = 0, p, h = 0, g = 0, v;
        scanf ( "%lld", &v );
        bool c1 = 0, c2 = 0, ok;
        while ( v > 2 * n * n )
            v -= 2 * n * n, k += 2;
        for ( p = 1; p <= n * n; ++p )
        {
            if ( !c1 && !c2 )
            {
                a[i][++j] = p;
                if ( j + h == n )
                    c2 = 1;
            }
            else if ( !c1 && c2 )
            {
                a[++i][j] = p;
                if ( i + g == n )
                    c1 = 1;
            }
            else if ( c1 && c2 )
            {
                a[i][--j] = p;
                if ( j - h == 1 )
                    c2 = 0, ++h;
            }
            else if ( c1 && !c2 )
            {
                a[--i][j] = p;
                if ( i - g == 2 )
                    c1 = 0, ++g;
            }
        }
        for ( i = 1; i <= n; ++i )
            for ( j = 1; j <= n; ++j )
                b[i][j] = 2 * n * n + 1 - a[i][j];
        ok = 1;
        if ( v > n * n )
        {
            for ( i = 1; i <= n && ok; ++i )
                for ( j = 1; j <= n && ok; ++j )
                    if ( b[i][j] == v )
                        ok = 0, k += 2;
        }
        else
            for ( i = 1; i <= n && ok; ++i )
                for ( j = 1; j <= n && ok; ++j )
                    if ( a[i][j] == v )
                        ok = 0, ++k;
        printf ( "%lld %lld %lld", --i, --j, k );
    }
    else
    {
        long long int i, j, k, d;
        ciur [1] = 1, ciur [0] = 0;
        for ( i = 2; i <= n * n * n; ++i )
            if ( ciur[i] == 0 )
                for ( j = i * i; j <= n * n * n; j += i )
                    ciur[j] = 1;
        k = 0, d = 1;
        for ( i = 1; i <= n; ++i )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        for ( i = 2 * n * n; d <= n; --i, ++d )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        printf ( "%lld\n", k );

        k = 0, d = 1;
        for ( i = n; i <= 2 * n - 1; ++i )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        for ( i = 2 * n * n - n + 1; d <= n; --i, ++d )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        printf ( "%lld\n", k );

        k = 0, d = 1;
        for ( i = 2 * n - 1; i <= 3 * n - 2; ++i )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        for ( i = 2 * n * n - 2 * n + 2; d <= n; --i, ++d )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        printf ( "%lld\n", k );

        k = 0, d = 1;
        for ( i = 3 * n - 2; i <= 4 * n - 4; ++i )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        for ( j = 1; j <= n * n * n; j += 2 * n * n )
            if ( ciur[j] == 0 ) ++ k;
        for ( i = 2 * n * n - 3 * n + 3; d < n; --i, ++d )
            for ( j = i; j <= n * n * n; j += 2 * n * n )
                if ( ciur[j] == 0 ) ++k;
        for ( j = 2 * n * n; j <= n * n * n; j += 2 * n * n )
            if ( ciur[j] == 0 ) ++k;
        printf ( "%lld", k );
    }
    return 0;
}
