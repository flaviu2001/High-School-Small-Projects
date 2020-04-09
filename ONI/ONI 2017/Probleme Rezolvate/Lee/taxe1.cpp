#include <fstream>

#define MAX 105

using namespace std;

struct lee
{
    int x, y;
}c[MAX*MAX*8];

int S, n, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, v[MAX][MAX], s[MAX][MAX];

void read();
int lee();
bool check(int i1, int j1);
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "taxe1.in", "r", stdin );
    scanf ( "%d%d", &S, &n );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            scanf ( "%d", &v[i][j] );
    fclose(stdin);
}

int lee()
{
    int p(0), f(1);
    c[1].x = 1, c[1].y = 1;
    s[1][1] = v[1][1];
    while ( p != f )
    {
        ++p;
        for ( int i = 0; i <= 3; ++i )
            if ( check(c[p].x + dx[i], c[p].y + dy[i]) )
                if ((s[c[p].x + dx[i]][c[p].y + dy[i]] && s[c[p].x][c[p].y] + v[c[p].x + dx[i]][c[p].y + dy[i]] < s[c[p].x + dx[i]][c[p].y + dy[i]]) || !s[c[p].x + dx[i]][c[p].y + dy[i]])
                    s[c[p].x + dx[i]][c[p].y + dy[i]] = s[c[p].x][c[p].y] + v[c[p].x + dx[i]][c[p].y + dy[i]],
                    c[++f].x = c[p].x + dx[i],
                    c[f].y = c[p].y + dy[i];
    }
    return s[n][n];
}

bool check(int i1, int j1)
{
    if ( i1 < 1 || j1 < 1 || i1 > n || j1 > n )
        return 0;
    return 1;
}

void write()
{
    freopen ( "taxe1.out", "w", stdout );
    int k = lee();
    if ( S >= k )
        printf ( "%d", S - k );
    else printf ( "-1" );
    fclose(stdout);
}
