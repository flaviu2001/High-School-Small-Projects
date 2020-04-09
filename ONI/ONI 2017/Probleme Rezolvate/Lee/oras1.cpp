#include <fstream>

#define MAX 205

using namespace std;

int n, m;
int v[MAX][MAX], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int fx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }, fy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct lee
{
    int I, J;
} c[MAX*MAX];

void read();
int solve_a();
bool check_a(int i1, int j1);
int solve_b();
void clear_b(int i1, int j1);
int solve_c();
int queue_c (int i1, int j1);
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "oras1.in", "r", stdin );
    char x;
    scanf ( "%d%d%c", &n, &m, &x );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m + 1; ++j )
        {
            scanf ( "%c", &x );
            if ( x == 'P' )
                v[i][j] = 1;
            else if ( x == 'C' )
                v[i][j] = 2;
            else if ( x == 'S' )
                v[i][j] = 3;
        }
    fclose(stdin);
}

int solve_a()
{
    int p(0);
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( check_a (i, j) )
                ++p;
    return p;
}

bool check_a(int i1, int j1)
{
    if ( !v[i1][j1] )
        return 0;
    for ( int i = 0; i <= 7; ++i )
        if ( !v[i1 + fx[i]][j1 + fy[i]] )
            return 1;
    return 0;
}

int solve_b()
{
    int k(0);
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( v[i][j] == 2 )
                ++k, clear_b(i, j);
    return k;
}

void clear_b(int i1, int j1)
{
    int p(0), f(1);
    c[1].I = i1, c[1].J = j1;
    v[i1][j1] = 0;
    while ( p != f )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( v[c[p].I + dx[i]][c[p].J + dy[i]] == 2 )
                v[c[p].I + dx[i]][c[p].J + dy[i]] = 0,
                c[++f].I = c[p].I + dx[i],
                c[f].J = c[p].J + dy[i];
    }
}

int solve_c()
{
    int k(0), p;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( v[i][j] == 1 )
            {
                p = queue_c(i, j);
                if ( p > k )
                    k = p;
            }
    return k;
}

int queue_c(int i1, int j1)
{
    int p(0), f(1);
    c[1].I = i1, c[1].J = j1;
    v[i1][j1] = 0;
    while ( p != f )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( v[c[p].I + dx[i]][c[p].J + dy[i]] == 1 )
                v[c[p].I + dx[i]][c[p].J + dy[i]] = 0,
                c[++f].I = c[p].I + dx[i],
                c[f].J = c[p].J + dy[i];
    }
    return f;
}

void write()
{
    freopen ( "oras1.out", "w", stdout );
    printf ( "%d ", solve_a() );
    printf ( "%d %d\n", solve_b(), solve_c() );
    fclose(stdout);
}
