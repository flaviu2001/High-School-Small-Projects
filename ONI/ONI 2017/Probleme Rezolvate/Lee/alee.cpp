#include <fstream>
#define MAX 177

using namespace std;

int n, v[MAX][MAX], dl[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };

struct pozitii {int x, y;}ps, pf, c[MAX*MAX], l, p;

void read()
{
    freopen ( "alee.in", "r", stdin );
    int m, i, j;
    scanf ( "%d%d", &n, &m );
    for ( ; m; --m )
        scanf ( "%d%d", &i, &j ), v[i][j] = -1;
    scanf( "%d%d%d%d", &ps.x, &ps.y, &pf.x, &pf.y );
    fclose(stdin);
}

void closure()
{
    int i, j;
    for ( i = 0; i <= n + 1; ++i )
        v[i][0] = -1, v[i][n+1] = -1;
    for ( j = 0; j <= n + 1; ++j )
        v[0][j] = -1, v[n+1][j] = -1;
}

void dump_Map()
{
    freopen ( "alee.out", "w", stdout );
    int i, j;
    for ( i = 0; i <= n + 1; ++i )
    {
        for ( j = 0; j <= n + 1; ++j )
            printf ( "%d ", v[i][j] );
        printf ( "\n" );
    }
    fclose(stdin);
}

void actual_Lee()
{
    c[0] = ps, v[ps.x][ps.y] = 1;
    int st = 0, lt = 0;
    while ( st <= lt && !v[pf.x][pf.y] )
    {
        p = c[st++];
        for ( int k = 0; k < 4; ++k )
        {
            l.x = p.x + dl[k], l.y = p.y + dc[k];
            if ( !v[l.x][l.y] )
                v[l.x][l.y] = v[p.x][p.y] + 1,
                c[++lt] = l;
        }
    }
}

void write()
{
    freopen ( "alee.out", "w", stdout );
    printf ( "%d\n", v[pf.x][pf.y] );
    fclose(stdout);
}

int main()
{
    read();
    closure();
    actual_Lee();
    //dump_Map();
    write();
    return 0;
}
