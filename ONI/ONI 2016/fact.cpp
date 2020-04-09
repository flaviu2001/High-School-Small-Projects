#include <fstream>

using namespace std;

struct factori {int x, y, z;}d[11];

int n, b, f;

void bprimes ( int b )
{
    int i, p;
    f = 0;
    for ( i = 2; i <= b; ++i )
    {
        p = 0;
        while( b % i == 0 )
            b /= i, ++p;
        if ( p != 0 )
            d[++f].x = i, d[f].y = p;
    }
}

int digit()
{
    int i, j, p = 1, aux;
    for ( j = 1; j <= f; ++j )
        d[j].z = 0;
    for( i = 1; i <= n; ++i )
    {
        aux = i;
        for ( j = 1; j <= f; ++j )
        {
            while ( aux % d[j].x == 0 )
                ++d[j].z, aux /= d[j].x;
        }
        p = ( p * ( aux % b ) ) % b;
    }
    return p;
}

int minim()
{
    int min = d[1].z / d[1].y;
    for ( int i = 2; i <= f; ++i )
        if ( d[i].z / d[i].y < min )
            min = d[i].z / d[i].y;
    return min;
}

int calculate()
{
    int i, j, p = digit();
    int min = minim();
    for ( i = 1; i <= f; ++i )
        for ( j = 1; j <= d[i].z - d[i].y * min; ++j )
            p = ( p * d[i].x ) % b;
    return p;
}

void write()
{
    int x = calculate();
    if ( x < 10 )
        printf ( "%d\n", x );
    else printf ( "%c\n", 'A' + x - 10 );
}

int main()
{
    freopen ( "fact.in", "r", stdin );
    freopen ( "fact.out", "w", stdout );
    for ( int i = 1; i <= 5; ++i )
    {
        scanf ( "%d%d", &n, &b );
        bprimes(b);
        write();
    }
    return 0;
}
