#include <fstream>

using namespace std;

long long int v [50001];

int main()
{
    FILE * fin = fopen ( "miere.in", "r" );
    FILE * fout = fopen ( "miere.out", "w" );
    long long int n, mi, i, j, m, st, d, x, s = 0;
    fscanf ( fin, "%lld", &n );
    for ( i = 1; i <= n; ++i )
        fscanf( fin, "%lld", &x ), v[i] = v[i-1] + x;
    fscanf( fin, "%lld", &mi );
    for ( i = 0; i < mi; ++i )
    {
        fscanf( fin, "%lld", &x );
        st = 1, d = n;
        while ( st <= d )
        {
            m = ( st + d ) / 2;
            if ( x < v[m] + m * i )
                d = m - 1;
            else if ( x > v[m] + m * i )
                st = m + 1;
                else break;
        }
        if ( m > n ) m = n;
        if ( v[m] + m * i > x ) --m;
            else if ( v[m + 1] + ( m + 1 ) * i < x && m < n ) ++m;
        fprintf( fout, "%lld\n", m );
    }
    return 0;
}