#include <fstream>
#include <algorithm>

#define MAX 260

using namespace std;

struct lee
{
    int x, y;
}c[MAX*MAX], pt, pj, pf, pth[MAX*MAX], pth_upd[MAX*MAX];

int n, m, w(1), q, v[MAX][MAX], r[MAX][MAX], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void read();
void boarding();
void dump();
void lee_jarry();
void path_jarry();
void lee_tom();
void find_pos();
bool cmp ( lee a, lee b );
void write();

int main()
{
    read();
    boarding();
    lee_jarry();
    path_jarry();
    lee_tom();
    dump();
    find_pos();
    write();
    return 0;
}

void read()
{
    freopen ( "tom.in", "r", stdin );
    char c;
    scanf ( "%d%d%c", &n, &m, &c );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m + 1; ++j )
        {
            scanf ( "%c", &c );
            if ( c == 'P' )
                v[i][j] = -1, r[i][j] = -1;
            else if ( c == 'X' || c == 10 )
                continue;
            else if ( c == 'C' )
                v[i][j] = -2;
            else if ( c == 'T' )
                pt.x = i, pt.y = j;
            else //if ( c == 'J' )
                pj.x = i, pj.y = j;
        }
    fclose(stdin);
}

void boarding()
{
    for ( int i = 0; i <= n + 1; ++i )
        v[i][0] = -1, v[i][m+1] = -1;
    for ( int j = 0; j <= m + 1; ++j )
        v[0][j] = -1, v[n+1][j] = -1;
}

void lee_jarry()
{
    int p(0), f(1);
    bool ok(1);
    c[1].x = pj.x, c[1].y = pj.y;
    while (ok)
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( v[c[p].x + dx[i]][c[p].y + dy[i]] == -2 )
            {
                ok = 0;
                pf.x = c[p].x + dx[i];
                pf.y = c[p].y + dy[i];
                v[c[p].x + dx[i]][c[p].y + dy[i]] = v[c[p].x][c[p].y] + 1;
                break;
            }
            else if ( !v[c[p].x + dx[i]][c[p].y + dy[i]] )
                v[c[p].x + dx[i]][c[p].y + dy[i]] = v[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
    }
}

void path_jarry()
{
    int I = pf.x, J = pf.y, k = v[pf.x][pf.y];
    pth[1].x = I, pth[1].y = J;
    while ( k != 1 )
        for ( int i = 0; i <= 3; ++i )
            if ( v[I + dx[i]][J + dy[i]] == k - 1 )
            {
                --k;
                I = I + dx[i], J = J + dy[i];
                pth[++w].x = I, pth[w].y = J;
                //printf ( "%d %d\n", I, J );
                break;
            }
}

void lee_tom()
{
    int p(0), f(1);
    c[1].x = pt.x, c[1].y = pt.y;
    while ( !r[pf.x][pf.y] )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( !r[c[p].x + dx[i]][c[p].y + dy[i]] )
                r[c[p].x + dx[i]][c[p].y + dy[i]] = r[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
        if ( p == f )
            break;
    }
}

void find_pos()
{
    for ( int i = 2; i <= w; ++i )
        if ( r[pth[i].x][pth[i].y] <= 2 * v[pth[i].x][pth[i].y] )
            pth_upd[++q] = pth[i];
    sort( pth_upd + 1, pth_upd + q + 1, cmp );
}

bool cmp ( lee a, lee b )
{
    return ( a.x > b.x ) || ( a.x == b.x && a.y > b.y );
}

void write()
{
    freopen ( "tom.out", "w", stdout );
    printf ( "%d\n", q );
    for ( int i = 1; i <= q; ++i )
        printf ( "%d %d\n", pth_upd[i].x, pth_upd[i].y );
    fclose(stdout);
}

void dump()
{
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
            printf ( "%d ", r[i][j] );
        printf ( "\n" );
    }
}
