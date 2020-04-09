#include <fstream>

#define MAX 102

using namespace std;

int n, m, R, G, B;
int v[MAX][MAX], r[MAX][MAX], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

struct lee
{
    int X, Y;
}c[MAX * MAX];

void read();
void RGB();
void do_queue(int x, int I, int J);
int bridge();
int lee(int i1, int j1);
bool check_lee(int i1, int j1);
void recover(int f);
void closure();
void write();

int main()
{
    read();
    closure();
    RGB();
    write();
    return 0;
}

void read()
{
    freopen ( "insule.in", "r", stdin );
    char c;
    scanf ( "%d%d%c", &n, &m, &c );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m + 1; ++j )
            scanf ( "%c", &c ), v[i][j] = c - '0', r[i][j] = v[i][j];
    fclose(stdin);
}

void RGB()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( v[i][j] != 0 )
                do_queue(v[i][j], i, j);
}

void do_queue(int x, int I, int J)
{
    int p(0), f(1);
    c[1].X = I, c[1].Y = J;
    v[I][J] = 0;
    while ( p != f )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( v[c[p].X + dx[i]][c[p].Y + dy[i]] == x )
                v[c[p].X + dx[i]][c[p].Y + dy[i]] = 0,
                c[++f].X = c[p].X + dx[i],
                c[f].Y = c[p].Y + dy[i];
    }
    switch(x)
    {
        case 1: ++R; break;
        case 2: ++G; break;
        case 3: ++B; break;
        default: printf ( "ERROR DO_QUEUE\n" );
    }
}

void write()
{
    freopen ( "insule.out", "w", stdout );
    printf ( "%d %d %d %d", R, G, B, bridge() );
    fclose(stdout);
}

int bridge()
{
    int min(MAX * MAX), q;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( check_lee(i, j) )
            {
                q = lee(i, j);
                if ( q < min && q )
                    min = q;
            }
    return min;
}

int lee(int i1, int j1)
{
    int p(0), f(1), t;
    c[1].X = i1, c[1].Y = j1;
    r[i1][j1] = 10;
    while (p != f)
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( r[c[p].X + dx[i]][c[p].Y + dy[i]] == 0 )
                r[c[p].X + dx[i]][c[p].Y + dy[i]] = r[c[p].X][c[p].Y] + 1,
                c[++f].X = c[p].X + dx[i],
                c[f].Y = c[p].Y + dy[i];
            else if ( r[c[p].X + dx[i]][c[p].Y + dy[i]] == 2 )
                {
                    t = r[c[p].X][c[p].Y];
                    recover(f);
                    return t-9;
                }
    }
    return MAX * MAX;
}

bool check_lee(int i1, int j1)
{
    if ( r[i1][j1] )
        return 0;
    for ( int i = 0; i <= 3; ++i )
        if ( r[i1 + dx[i]][j1 + dy[i]] == 1 )
            return 1;
    return 0;
}

void recover(int f)
{
    for ( int i = 1; i <= f; ++i )
        r[c[i].X][c[i].Y] = 0;
}

void closure()
{
    for ( int i = 0; i <= n + 1; ++i )
        v[i][0] = -1, v[i][m+1] = -1, r[i][0] = -1, r[i][m+1] = -1;
    for ( int j = 0; j <= m + 1; ++j )
        v[0][j] = -1, v[n+1][j] = -1, r[0][j] = -1, r[n+1][j] = -1;
}
