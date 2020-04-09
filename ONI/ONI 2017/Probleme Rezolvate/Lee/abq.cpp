#include <fstream>

#define MAX 205

using namespace std;

struct lee
{
    int x, y;
}c[MAX*MAX], pi, pf;

int n, m, s[MAX][MAX], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char v[MAX][MAX];

int lee();
void reset();
void dump();

int main()
{
    freopen ( "abq.in", "r", stdin );
    freopen ( "abq.out", "w", stdout );
    scanf ( "%d%d%c", &n, &m, &v[1][1] );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m + 1; ++j )
        //{
            scanf ( "%c", &v[i][j] );
            /*if ( j != m+1 && v[i][j] == '\n' )
            {
                v[i][j] = 'a';
                break;
            }*/ // testul 6 e gresit si are nevoie de aceste linii de cod
        //}
    int q;
    scanf ( "%d", &q );
    while (q--)
        scanf ( "%d%d%d%d", &pi.x, &pi.y, &pf.x, &pf.y ),
        printf ( "%d\n", lee() ),
        reset();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

int lee()
{
    int p(0), f(1);
    c[1].x = pi.x, c[1].y = pi.y;
    s[pi.x][pi.y] = 1;
    if ( v[pi.x][pi.y] == 'b' )
        return -1;
    while ( !s[pf.x][pf.y] )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( v[c[p].x + dx[i]][c[p].y + dy[i]] == 'a' && !s[c[p].x + dx[i]][c[p].y + dy[i]] )
                s[c[p].x + dx[i]][c[p].y + dy[i]] = s[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
        if ( p == f )
            return -1;
    }
    return s[pf.x][pf.y];
}

void reset()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            s[i][j] = 0;
}
