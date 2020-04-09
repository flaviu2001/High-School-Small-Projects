#include <cstdio>
#define MAX 1005

using namespace std;

struct lee
{
    int x, y;
}c[1001 * 1001], pi;

char r[MAX][MAX];
int n, v[MAX][MAX];
int dx[] = {2, 1, -1, -2}, dy[] = {1, 2, 2, 1};

void read();
bool check(int, int);

int main()
{
    freopen ( "mine.in", "r", stdin );
    freopen ( "mine.out", "w", stdout );
    int tests, mx, p, f;
    scanf ( "%d", &tests );
    while(tests--)
    {
        read();
        mx = 0; p = 0; f = 1; c[1] = pi;
        while (p != f)
        {
            ++p;
            for ( int i = 0; i <= 3; ++i )
            {
                if (check ( c[p].x + dx[i], c[p].y + dy[i] ))
                    v[c[p].x + dx[i]][c[p].y + dy[i]] = v[c[p].x][c[p].y] + 1,
                    c[++f].x = c[p].x + dx[i],
                    c[f].y = c[p].y + dy[i];
                if ( v[c[p].x + dx[i]][c[p].y + dy[i]] > mx )
                    mx = v[c[p].x + dx[i]][c[p].y + dy[i]];
            }
        }
        /*for ( int i = 1; i <= n; ++i )
        {
            for ( int j = 1; j <= n; ++j )
                printf ( "%d", v[i][j] );
            printf ( "\n" );
        }*/
        printf ( "%d\n", mx );
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void read()
{
    scanf ( "%d%c", &n, &r[1][1] );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n+1; ++j )
        {
            scanf ( "%c", &r[i][j] ), v[i][j] = 0;
            if ( r[i][j] == 'G' )
                pi.x = i, pi.y = j;
        }
}

bool check(int i1, int j1)
{
    if ( i1 < 1 || j1 < 1 || i1 > n || j1 > n || r[i1][j1] != 'M' )
        return 0;
    return 1;
}
