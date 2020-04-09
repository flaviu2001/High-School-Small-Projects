#include <fstream>
#include <cmath>
#define MAX 10001
#define D double

using namespace std;

bool poz[MAX], neg[MAX];

int main()
{
    freopen ( "ec.in", "r", stdin );
    freopen ( "ec.out", "w", stdout );
    int n, k, i, x, a, b, c, d, t1 = 0, t2 = 0, t11 = 0, t22 = 0, x1, x2, delta;
    bool type;
    char y;
    scanf ( "%d%d", &n, &k );
    for ( i = 1; i <= n * n; ++i )
    {
        scanf ( "%d", &x );
        if ( x >= 0 )
            poz[x] = 1;
        else neg[-x] = 1;
    }
    for ( ; k > 0; --k )
    {
        scanf ( "%d", &a );
        scanf ( "%c%c", &y, &y );
        if ( y == '^' )
            type = 1;
        else type = 0;
        if ( !type )
        {
            ++t1;
            scanf ( "%d%c%d", &b, &y, &c );
            if ( !a && c == b )
                continue;
            else if ( !a )
                continue;
            if ( ( c - b ) / a != ( ( D(c) - D(b) ) / D(a) ) )
                continue;
            x1 = ( c - b ) / a;
            if ( x1 >= 0 && poz[x1] )
                ++t11;
            else if ( x1 < 0 && neg[-x1] )
                ++t11;
        }
        else
        {
            ++t2;
            scanf ( "%c%c%d%c%c%d%c%d", &y, &y, &b, &y, &y, &c, &y, &d );
            c -= d;
            if ( a == 0 )
            {
                if ( !b && !c )
                    continue;
                else if ( !b )
                    continue;
                if ( -c / b != -D(c) / D(b) )
                    continue;
                x1 = -c / b;
                if ( x1 >= 0 && poz[x1] )
                    ++t22;
                else if ( x1 < 0 && neg[-x1] )
                    ++t22;
                continue;
            }
            delta = b * b - 4 * a * c;
            if ( delta < 0 )
                continue;
            if ( sqrt (delta) != int(sqrt(delta)) )
                continue;
            if ( ( -b + delta ) % ( 2 * a ) != 0 )
                continue;
            if ( ( -b - delta ) % ( 2 * a ) != 0 )
                continue;
            x1 = ( -b + sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
            x2 = ( -b - sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
            if ( x1 > 0 && x2 > 0 && poz[x1] && poz[x2] )
                ++t22;
            else if ( x1 > 0 && x2 < 0 && poz[x1] && neg[-x2] )
                ++t22;
            else if ( x1 < 0 && x2 < 0 && neg[-x1] && neg[-x2] )
                ++t22;
            else if ( x1 < 0 && x2 > 0 && neg[-x1] && poz[x2] )
                ++t22;
        }
    }
    printf ( "%d %d\n%d %d", t1, t11, t2, t22 );
    return 0;
}
