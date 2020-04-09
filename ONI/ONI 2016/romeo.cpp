#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    freopen ( "romeo.in", "r", stdin );
    freopen ( "romeo.out", "w", stdout );
    int x, y;
    scanf ( "%d%d", &x, &y );
    if ( x >= y - 1 )
        printf ( "%d", y * 2 + x - y );
    else if ( x == 0 )
        printf ( "%d", y * ( y + 1 ) / 2 );
        else
        {
            int z = y / ( x + 1 ), n, m, s = 0;
            n = y - z * ( x + 1 ), m = x + 1 - n;
            s += z * ( z + 1 ) / 2 * m + ( z + 1 ) * ( z + 2 ) / 2 * n;
            s += x;
            printf ( "%d", s );
        }
    return 0;
}
