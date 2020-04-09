#include <fstream>

using namespace std;

int v[5656860];

int main()
{
    freopen ( "progresie.in", "r", stdin );
    freopen ( "progresie.out", "w", stdout );
    int n, i = 2, d = 3, j;
    scanf ( "%d", &n );
    v[1] = 1, v[2] = 2;
    while ( i < n )
    {
        for ( j = 1; j <= i; ++j )
            v[j+i] = v[j] + d;
        i *= 2, d *= 3;
    }
    for ( i = 1; i <= n; ++i )
        printf ( "%d ", v[i] );
    return 0;
}
