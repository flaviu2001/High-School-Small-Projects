#include <fstream>

int k, n;
char c[50000];

void read();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "zigzag.in", "r", stdin );
    char q;
    int l = 1, m = 1, d, dt;
    scanf ( "%d%d%c", &k, &n, &q );
    dt = 2 * k - 2;
    for ( int i = 1; i <= n; ++i )
    {
        scanf ( "%c", &q );
        if ( m == 1 )
        {
            c[l] = q;
            if ( i == 7 )
                printf ( "%c", q );
            ++m;
            if ( m > n/(k-1)+1 )
                ++l, m = 1;
            continue;
        }
        else if ( m == 2 && l != k )
        {
            c[2*k-l] = q;
            ++m;
            if ( m > n/(k-1) + 1 )
                ++l, m = 1;
            continue;
        }
        if ( ( (m%2) && l == 1 ) || ( !(m%2) && l == k ) )
            ++m;
        if ( m > n/(k-1) + 1 )
            ++l, m = 1;
        if ( m%2 )
        {
            if ( l+(m-1)/2*dt > n )
                ++l, m = 1, c[l] = q;
            else c[l+(m-1)/2*dt] = q;
        }
        else if ( !(m%2) )
        {
            if ( 2*k-l+(m-2)/2*dt > n )
                ++l, m = 1, c[l] = q;
            else c[2*k-l+(m-2)/2*dt] = q;
        }
        ++m;
    }
}

void write()
{
    freopen ( "zigzag.out", "w", stdout );
    for ( int i = 1; i <= n; ++i )
        printf ( "%c", c[i] );
    fclose(stdout);
}
