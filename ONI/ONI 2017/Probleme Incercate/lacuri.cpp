#include <fstream>

#define MAX 150

using namespace std;

int n, v[MAX][MAX];
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

void read();
int solve_a();
void square(int i1, int j1);
void lee();
void road();
void write();

struct lee
{
    int x, y;
}c[MAX*MAX];

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "lacuri.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            scanf ( "%d", &v[i][j] ), v[i][j] = -v[i][j];
    fclose(stdin);
}

int solve_a()
{
    int p(0);
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            if ( v[i][j] == -1 )
                square(i, j), ++p;
    return p;
}

void square(int i1, int j1)
{
    int k(0);
    for ( int j = j1; v[i1][j] == -1; ++j )
        ++k;
    for ( int i = i1; i < i1 + k; ++i )
        for ( int j = j1; j < j1 + k; ++j )
            v[i][j] = -2;
}

void lee()
{
    int p(0), f(1);
    c[1].x = 1, c[1].y = 1;
    v[1][1] = 1;
    while ( !v[n][n] )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if( c[p].x + dx[i] > 0 && c[p].x + dx[i] <= n && c[p].y + dy[i] > 0 && c[p].y + dy[i] <= n && !v[c[p].x + dx[i]][c[p].y + dy[i]] )
                v[c[p].x + dx[i]][c[p].y + dy[i]] = v[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
    }
}

void road()
{
    int I = n, J = n, k = v[n][n], p(1);
    c[1].x = n, c[1].y = n;
    while ( k != 1 )
        for ( int i = 0; i <= 3; ++i )
            if ( v[I + dx[i]][J + dy[i]] == k - 1 )
            {
                --k;
                I = I + dx[i], J = J + dy[i];
                c[++p].x = I, c[p].y = J;
                break;
            }
    for ( int i = p; i >= 1; --i )
        printf ( "%d %d\n", c[i].x, c[i].y );
}

void write()
{
    freopen ( "lacuri.out", "w", stdout );
    printf ( "%d\n", solve_a() );
    lee();
    road();
    fclose(stdout);
}
