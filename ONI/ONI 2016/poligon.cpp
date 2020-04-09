#include <fstream>
#include <cmath>

#define MAX 1001
#define NMAX 10001

using namespace std;

int n, r[MAX];
int x[NMAX], y[NMAX];

int main()
{
    freopen ( "poligon4.in", "r", stdin );
    freopen ( "poligon4.out", "w", stdout );
    scanf ( "%d", &n );
    int i, j, k, c = 0, aux, s;
    for ( i = 1; i <= n; ++i )
    {
        scanf ( "%d", &r[i] );
        for ( j = 1; j <= r[i]-1; ++j )
        {
            k = (int)sqrt((double)r[i] * r[i] - j * j);
            if ( k * k + j * j == r[i] * r[i] )
                x[++c] = j, y[c] = k;
        }
    }
    printf ( "%d\n", c );
    for ( i = 1; i <= c; ++i )
        for ( j = i + 1; j <= c; ++j )
            if ( x[i] * y[j] > x[j] * y[i] )
                aux = x[i], x[i] = x[j], x[j] = aux,
                aux = y[i], y[i] = y[j], y[j] = aux;
    x[0] = 0, y[0] = 1, s = 0;
    for ( i = 1; i <= c; ++i )
        if ( x[i-1] * y[i] < x[i] * y[i-1] )
            ++s;
    printf ( "%d\n", s );
    s = 1;
    for ( i = 2; i <= c; ++i )
        if ( x[i-1] * y[i] == x[i] * y[i-1] )
            ++s;
        else
            printf ( "%d ", s ), s = 1;
    printf ( "%d\n", s );
    fclose(stdin), fclose(stdout);
    return 0;
}
