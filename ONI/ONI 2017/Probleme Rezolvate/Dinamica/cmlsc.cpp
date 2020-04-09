#include <fstream>
#define MAX 1025

using namespace std;

int n, m, bst;
int a[MAX], b[MAX], v[MAX][MAX], r[MAX];

void read();
void solve();
void write();

int main()
{
    read();
    solve();
    write();
    return 0;
}

void read()
{
    freopen ( "cmlsc.in", "r", stdin );
    scanf ( "%d%d", &n, &m );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d", &a[i] );
    for ( int j = 1; j <= m; ++j )
        scanf ( "%d", &b[j] );
    fclose(stdout);
}

void solve()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i] == b[j] )
                v[i][j] = 1 + v[i-1][j-1];
            else v[i][j] = max( v[i-1][j], v[i][j-1] );
    for ( int i = n, j = m; i; )
        if ( a[i] == b[j] )
            r[++bst] = a[i], --i, --j;
        else if ( v[i-1][j] < v[i][j-1] )
            --j;
        else --i;
}

void write()
{
    freopen ( "cmlsc.out", "w", stdout );
    printf ( "%d\n", bst );
    for ( int i = bst; i >= 1; --i )
        printf ( "%d ", r[i] );
    fclose(stdout);
}
