#include <cstdio>

#define MAX 101

using namespace std;

struct leeR
{
    int x, y;
}c[MAX*MAX], ir, ij;

int R[MAX][MAX], J[MAX][MAX];
int n, m, P, dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void read()
{
    freopen ( "rj.in", "r", stdin );
    scanf ( "%d%d%c", &n, &m, &R[1][1] );
    char w;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m + 1; ++j )
        {
            scanf ( "%c", &w );
            if ( w == 'R' )
                ir.x = i, ir.y = j;
            else if ( w == 'J' )
                ij.x = i, ij.y = j;
            else if ( w == 'X' )
                R[i][j] = -1;
            else ++P;
            J[i][j] = R[i][j];
        }
    fclose(stdin);
}

void leeR()
{
    int p(0), f(1);
    c[1] = ir;
    R[ir.x][ir.y] = 1;
    do
    {
        ++p;
        for ( int i = 0; i <= 7; ++i )
            if ( c[p].x + dx[i] <= n && c[p].y + dy[i] <= m && c[p].x + dx[i] > 0 && c[p].y + dy[i] > 0 && !R[c[p].x + dx[i]][c[p].y + dy[i]] )
                R[ c[p].x + dx[i] ][ c[p].y + dy[i] ] = R[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
        if ( p == f )
            break;
    }while ( f != P );
}

void leeJ()
{
    int p(0), f(1);
    c[1] = ij;
    J[ij.x][ij.y] = 1;
    do
    {
        ++p;
        for ( int i = 0; i <= 7; ++i )
            if ( c[p].x + dx[i] <= n && c[p].y + dy[i] <= m && c[p].x + dx[i] > 0 && c[p].y + dy[i] > 0 && !J[c[p].x + dx[i]][c[p].y + dy[i]] )
                J[ c[p].x + dx[i] ][ c[p].y + dy[i] ] = J[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
        if ( p == f )
            break;
    }while ( f != P );
}

void check()
{
    freopen ( "rj.out", "w", stdout );
    int X, Y, M(200000);
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( R[i][j] == J[i][j] && R[i][j] < M && R[i][j] > 0 )
                M = R[i][j], X = i, Y = j;
    printf ( "%d %d %d\n", M, X, Y );
    fclose(stdout);
}

int main()
{
    read();
    leeR();
    leeJ();
    check();
    return 0;
}
