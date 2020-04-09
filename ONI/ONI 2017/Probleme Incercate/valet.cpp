#include <cstdio>
#define MAX 52

using namespace std;

struct lee
{
    int hx, hy, cx, cy, p;
}c[MAX*MAX*8];

int n, m, v[MAX][MAX], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int result;

void read();
void lee();
void write();

int main()
{
    read();
    lee();
    write();
    /*for ( int i = 0; i <= n+1; ++i )
    {
        for ( int j = 0; j <= m+1; ++j )
            printf ( "%d", v[i][j] );
        printf ( "\n" );
    }*/
    return 0;
}

void read()
{
    freopen ( "valet.in", "r", stdin );
    char q;
    scanf ( "%d%d%c", &n, &m, &q );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m + 1; ++j )
        {
            scanf ( "%c", &q );
            if ( q == '#' )
                v[i][j] = -1;
            else if ( q == 'X' )
                /*v[i][j] = -2,*/c[1].cx = i, c[1].cy = j;
        }

    for ( int i = 0; i <= n + 1; ++i )
        v[i][0] = -1, v[i][m+1] = -1;
    for ( int i = 0; i <= m + 1; ++i )
        v[0][i] = -1, v[n+1][i] = -1;
    fclose(stdin);
}

void lee()
{
    bool ok(1);
    int p(0), f(1);
    c[1].hx = 1, c[1].hy = 1;
    while (ok)
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( v[c[p].hx + dx[i]][c[p].hy + dy[i]] != -1 )// && c[p].hx + dx[i] > 0 && c[p].hx + dx[i] <= n && c[p].hy + dy[i] > 0 && c[p].hy + dy[i] <= m )
            {
                if ( c[p].hx + dx[i] != c[p].cx || c[p].hy + dy[i] != c[p].cy )
                    c[++f].p = c[p].p + 1,
                    c[f].hx = c[p].hx + dx[i],
                    c[f].hy = c[p].hy + dy[i],
                    c[f].cx = c[p].cx,
                    c[f].cy = c[p].cy;
                else
                {
                    c[++f].p = c[p].p + 1,
                    c[f].hx = c[p].cx,
                    c[f].hy = c[p].cy,
                    c[f].cx = c[p].hx,
                    c[f].cy = c[p].hy;
                }
                if ( c[f].cx == 1 && c[f].cy == 1 )
                    {
                        ok = 0;
                        result = c[f].p;
                        break;
                    }
                printf ( "%d\n", f );
            }
        if (p == f)
            break;
    }
}

void write()
{
    freopen ( "valet.out", "w", stdout );
    if (result)
        printf ( "%d\n", result );
    else
        printf ( "imposibil\n" );
    fclose(stdout);
}
