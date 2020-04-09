#include <fstream>

#define MAX 77

using namespace std;

struct stuff
{
    int x, y;
}c[MAX*MAX], pi[25], pf[25];

int n, m, v[MAX][MAX], many, dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

void read()
{
    freopen ( "inginer.in", "r", stdin );
    scanf ( "%d%d", &n, &m );
    char x;
    scanf ( "%c", &x );
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
        {
            scanf ( "%c", &x );
            if ( x == 'X' )
                v[i][j] = -1;
        }
        scanf ( "%c", &x );
    }
    while (1)
    {
        ++many;
        scanf ( "%d%d%d%d", &pi[many].x, &pi[many].y, &pf[many].x, &pf[many].y );
        if ( !pi[many].x )
            break;
    }
    --many;
    fclose(stdin);
}

int lee( int I )
{
    int p(0), f(1);
    c[1] = pi[I];
    v[pi[I].x][pi[I].y] = 1;
    v[pf[I].x][pf[I].y] = 0;
    while ( !v[pf[I].x][pf[I].y] )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( c[p].x + dx[i] <= n + 1 && c[p].y + dy[i] <= m + 1 && c[p].x + dx[i] >= 0 && c[p].y + dy[i] >= 0 && !v[ c[p].x + dx[i] ][ c[p].y + dy[i] ] )
                v[ c[p].x + dx[i] ][ c[p].y + dy[i] ] = v[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
        if ( p == f )
            break;
    }
    return f;
}

void dump()
{
    for ( int i = 0; i <= n + 1; ++i )
    {
        for ( int j = 0; j <= m + 1; ++j )
            printf ( "%d ", v[i][j] );
        printf ( "\n" );
    }
    printf ( "\n\n" );
}

void solve()
{
    freopen ( "inginer.out", "w", stdout );
    int f;
    for ( int i = 1; i <= many; ++i )
    {
        f = lee(i);
        //dump();
        if ( v[pf[i].x][pf[i].y] > 0 )
            --v[pf[i].x][pf[i].y];
        printf( "%d\n", v[pf[i].x][pf[i].y] );
        v[pi[i].x][pi[i].y] = -1;
        for ( int j = 2; j <= f; ++j )
            v[c[j].x][c[j].y] = 0;
        v[pf[i].x][pf[i].y] = -1;
    }
    fclose(stdout);
}

int main()
{
    read();
    solve();
    return 0;
}
