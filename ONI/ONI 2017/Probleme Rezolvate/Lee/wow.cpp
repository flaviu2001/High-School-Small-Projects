#include <fstream>

#define MAX 105
#define NMAX 1505

using namespace std;

struct wow
{
    int x, y;
}c[MAX*MAX], pi[NMAX];

int n, m, t, f, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int v[MAX][MAX], mins(300000), X, Y;

void read();
void solve();
void lee(int i1, int j1);
bool check(int i1, int j1);
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
    freopen ( "wow.in", "r", stdin );
    scanf ( "%d%d%d", &n, &m, &t );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            scanf ( "%d", &v[i][j] );
    for ( int i = 1; i <= t; ++i )
        scanf ( "%d%d", &pi[i].x, &pi[i].y ), ++pi[i].x, ++pi[i].y;
    fclose(stdin);
}

void solve()
{
    bool ok;
    int s;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( v[i][j] == 1 )
                continue;
            ok = 1, s = 0;
            lee(i, j);
            for ( int I = 1; I <= t; ++I )
            {
                if ( !v[pi[I].x][pi[I].y] )
                {
                    ok = 0;
                    break;
                }
                s += v[pi[I].x][pi[I].y];
            }
            s -= t;
            if ( s < mins && ok )
                mins = s, X = i - 1, Y = j - 1;
            for ( int i1 = 1; i1 <= f; ++i1 ) // recover
                v[c[i1].x][c[i1].y] = 0;
        }
}

void lee(int i1, int j1)
{
    int p(0);
    f = 1;
    c[1].x = i1, c[1].y = j1;
    v[i1][j1] = 1;
    while( p != f )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( check(c[p].x + dx[i], c[p].y + dy[i]) )
                v[c[p].x + dx[i]][c[p].y + dy[i]] = v[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
    }
}

bool check(int i1, int j1)
{
    if ( i1 < 1 || i1 > n || j1 < 1 || j1 > m )
        return 0;
    if ( !v[i1][j1] )
        return 1;
    return 0;
}

void write()
{
    freopen ( "wow.out", "w", stdout );
    printf( "%d\n%d %d", mins, X, Y );
    fclose(stdout);
}
