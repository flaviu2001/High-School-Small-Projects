#include <fstream>
#define MAX 243
using namespace std;

int n, v[MAX][MAX], max_in, r;
bool how;

void read()
{
    freopen ( "sotron.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            scanf ( "%d", &v[i][j] );
    fclose(stdin);
}

void dump()
{
    //freopen ( "sotron.out", "w", stdout );
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= n; ++j )
            printf ( "%d ", v[i][j] );
        printf ( "\n" );
    }
    //fclose (stdout);
}

int sim( int k, int p )
{
    r = v[k][p], max_in = r;
    while ( k > 0 && p <= n )
    {
        if ( k % 2 == p % 2 )
            --k;
        else ++p;
        r += v[k][p];
        if ( r > max_in )
            max_in = r;
    }
    return max_in;
}

int solve()
{
    int x, max = 0;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
        {
            x = sim(i, j);
            if ( x > max )
                max = x;
        }
    return max;
}

void write()
{
    freopen ( "sotron.out", "w", stdout );
    printf ( "%d\n", solve() );
    fclose(stdout);
}

int main()
{
    read();
    //dump();
    write();
    return 0;
}