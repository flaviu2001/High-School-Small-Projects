#include <cstdio>

using namespace std;

bool v[101][101];
int k, n, w[101];

void read();
void solve();
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
    freopen ( "neuroni.in", "r", stdin );
    scanf ( "%d %d", &n, &k );
    fclose(stdin);
}

void solve()
{
    int x, y;
    while(k--)
    {
        x = 1, y = 1;
        for ( int i = 1; i < n; ++i )
        {
            v[x][y] = 1 - v[x][y];
            if ( ( i % 2 == 1 && v[x][y] ) || ( i % 2 == 0 && !v[x][y] ) )
                ++y;
            ++x;
        }
        ++w[y];
    }
}

void write()
{
    freopen ( "neuroni.out", "w", stdout );
    for ( int i = 1; i <= n; ++i )
        printf ( "%d ", w[i] );
    printf ( "\n" );
    fclose(stdout);
}
