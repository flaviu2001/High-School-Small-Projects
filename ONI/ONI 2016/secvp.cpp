#include <fstream>

using namespace std;

bool sieve[1000001];
int primes[78505];
short int r[100000];

int main()
{
    FILE * fin = fopen ( "secvp.in" , "r" );
    FILE * fout = fopen ( "secvp.out" , "w" );
    int n=1000000, d , i, k, x, m, s, t = 0, a1, a2, a3, min1, app = 1, u = 1;
    for( d = 2; d * d <= n; ++d )
        if( sieve[d] == 0 )
            for( i = d * d; i <= n; i += d)
                sieve[i] = 1;
    d=1, primes[78499]=1000003;
    for( i = 2; i <= 1000000; ++i)
        if( sieve[i] == 0 )
            primes[d] = i, ++d;
    fscanf( fin , "%d%d" , &n , &k );
    for( i=1; i <= n; ++i )
    {
        fscanf( fin, "%d", &x );
        s = 1, d = 78499;
        while( s <= d )
        {
            m = ( s + d ) / 2;
            if( primes[m] < x )
                s = m + 1;
                else if( primes[m] > x)
                    d = m - 1;
                    else break;
        }
        a1 = x - primes[m];
            if( a1 < 0 ) a1 = -a1;
        a2 = x - primes [m + 1];
            if( a2 < 0 ) a2 = -a2;
        a3 = x - primes [m - 1];
            if( a3 < 0 ) a3 = -a3;
        if ( a2 < a1 )
            a1 = a2;
        if ( a3 < a1)
            a1 = a3;
        if( x == 0 ) a1 = 2;
        t += a1, s = 0;
        r[u] = a1, ++u;
    }
    s = 0;
    for( i = 1; i <= k; ++i)
        s += r[i];
    min1 = s;
    for( i = k + 1; i <= n; ++i)
        {
            s -= r[i-k], s+=r[i];
            if( s < min1 ) min1 = s, app = 1;
            else if ( s == min1 ) ++app;
        }
    fprintf( fout , "%d\n%d %d" , t, min1, app );
    return 0;
}
