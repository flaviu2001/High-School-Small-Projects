#include <fstream>
#define nmax 50005

using namespace std;

bool sieve[nmax];
int primes[nmax], d;

FILE * fin = fopen( "maxd.in", "r" );
FILE * fout = fopen( "maxd.out", "w" );

void primeGen()
{
    long long i, j;
    for ( i = 2; i <= 50000; ++i )
        if( sieve[i] == 0 )
        {
            j = 2;
            while ( i * j <= 50000 )
                sieve[ i * j ] = 1, ++j;
            primes[++d] = i;
        }
}

int main()
{
    int a, b, c, i, j, nd, e, m = 0, k, cf;
    fscanf( fin, "%d%d", &a, &b );
    primeGen();
    for ( i = a; i <= b; ++i )
    {
        c = i, nd = 1;
        for ( j = 1; primes[j] * primes[j] <= c && j <= d; ++j )
        {
            for ( e = 0; c % primes[j] == 0; ++e, c /= primes[j] );
            if ( e ) nd *= ( 1 + e );
        }
    if ( c > 1 ) nd *= 2;
    if ( nd > m ) m = nd, k = i, cf = 1;
    else if ( nd == m ) ++cf;
    }
    fprintf( fout, "%d %d %d", k, m, cf );
    return 0;
}
