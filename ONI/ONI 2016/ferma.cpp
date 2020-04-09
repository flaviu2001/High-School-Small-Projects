#include <fstream>

using namespace std;

int v[5001], s[5001], r[10002];

int main()
{
    FILE * fin = fopen ( "ferma.in", "r" );
    FILE * fout = fopen ( "ferma.out", "w" );
    int n, x, i, j, d = 0, k = 0, p, m, ok;
    fscanf( fin, "%d", &n );
    for ( i = 1; i <= n; ++i )
        fscanf( fin, "%d", &v[i] );
    while ( n > 0 )
    {
        ok = 0;
        for ( i = 1; i <= n && ok == 0; ++i )
        {
            s[i] = s[i - 1] + v[i];
            if ( s[i] % n == 0 )
                ok = i;
        }
        if ( ok != 0 )
        {
            ++k;
            r[++d] = ok;
            for ( j = 1; j <= ok; ++j )
                r[++d] = v[j];
            for ( j = 1; j <= n - ok ; ++j )
                v[j] = v[j+ok];
            n -= ok;
        }
        else
        {
            ++k;
            for ( i = 1; i < n && ok == 0; ++i )
                for ( j = i + 1; j <= n && ok == 0; ++j )
                    if ( ( s[j] - s[i] ) % n == 0 )
                        ok = 1;
            --j, p = i, m = j - i + 1;
            r[++d] = m;
            for ( ; i <= j; ++i )
                r[++d] = v[i];
            for ( ; p <= n - m ; ++p )
                v[p] = v[p + m];
            n -= m;
        }
    }
    fprintf ( fout, "%d\n", k );
    for ( i = 1; i <= d; ++i )
        fprintf ( fout, "%d\n", r[i] );
    return 0;
}
