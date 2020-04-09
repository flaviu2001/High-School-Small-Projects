#include <fstream>
#define nmax 10000001
using namespace std;

struct pereche
{
    int a, b;
};

bool sieve [nmax];
int primes [664580], bb[nmax];
pereche v[nmax];

void primegen()
{
    int d , i;
    for( d = 2; d * d <= nmax; ++d )
        if( sieve[d] == 0 )
            for( i = d * d; i <= nmax; i += d)
                sieve[i] = 1;
    d=1;
    for( i = 2; i <= 10000000; ++i)
        if( sieve[i] == 0 )
            primes[d] = i, ++d;
}

void sipet()
{
    int n, p1, s, d, m, p2, p3, a, b, c, pos, r ,R, A = 0, B = 0, C = 0;
    bool found;
    scanf ( "%d%d", &n, &p1 );
    s = 1, d = 664579;
    for ( m = ( s + d ) >> 1; s <= d; m = ( s + d ) >> 1 )
    {
        if ( p1 < primes[m] )
            d = m - 1;
            else if ( p1 > primes[m] )
                s = m + 1;
                else break;
    }
    p2 = primes[m + 1];
    p3 = primes[m + 2];
    for ( a = 0; a * p1 <= n; ++a )
            for ( b = 0; a * p1 + b * p2 <= n && b < p1; ++b )
            {
                pos = a * p1 + b * p2;
                v[pos].a = a;
                v[pos].b = b;
                bb[pos] = 1;
            }

        found = 0; R = -1;
        for ( r = 0; r <= p1 && R == -1; ++r )
            for ( c = 0; r + c * p3 <= n && c <= p1; ++c )
            {
                pos = c * p3 + r;
                if ( bb[n - pos] && (R == -1 || R != -1 && A + B + C < v[n - pos].a + v[n - pos].b + c ))
                {
                    found = 0;
                    A = v[n - pos].a;
                    B = v[n - pos].b;
                    C = c;
                    R = r;
                }
            }

        for ( a = 0; a * p1 <= n; ++a )
            for ( b = 0; a * p1 + b * p2 <= n && b < p1; ++b )
            {
                pos = a * p1 + b * p2;
                bb[pos] = 0;
            }

        printf("%d %d %d %d %d\n", A + B + C, A, B, C, R);

}

int main()
{
    freopen ( "sipet.in", "r", stdin );
    freopen ( "sipet.out", "w", stdout );
    int t, i;
    scanf ( "%d", &t );
    primegen();
    for ( i = 1; i <= t; ++i )
        sipet();
    return 0;
}
