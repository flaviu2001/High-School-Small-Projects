#include <fstream>
#include <vector>
#define MAX 30003

using namespace std;

int n, v[MAX], min_G = MAX, sa = MAX, sb, ina, st[MAX], dr[MAX];

void read()
{
    freopen ( "secv.in", "r", stdin );
    scanf ( "%d", &n );
    int i;
    for ( i = 1; i <= n; ++i )
        scanf ( "%d", &v[i] );
    dr[n] = v[n];
    for ( i = n - 1; i > 0; --i )
        if ( v[i] < dr[i+1] )
            dr[i] = dr[i+1];
        else dr[i] = v[i];
    fclose(stdin);
}

void solve_a()
{
    int i, x = 0, y, z;
    for ( i = 1; i < n - 1; ++i )
    {
        if ( v[i] > x )
            x = v[i];
        y = v[i+1];
        z = dr[i+2];
        if ( sa > x + y + z )
            sa = x + y + z, ina = i, printf ( "%d\n", dr[i+2] );
    }
}

void solve_b()
{
    int x = 0;
    for ( int j = 2; j < n; ++j )
    {
        if ( v[j] > x )
            x = v[j];
    }
    sb = v[1] + v[n] + x;
}

void write()
{
    freopen ( "secv.out", "w", stdout );
    if ( sa < sb )
        printf ( "%d\n%d %d", sa, ina, ina + 1 );
    else printf ( "%d\n1 %d", sb, n-1 );
    fclose (stdout);
}

int main()
{
    read();
    solve_a();
    solve_b();
    write();
    return 0;
}
