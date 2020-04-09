#include <fstream>

using namespace std;

int n, g, w[5001], p[5001], v[10001], r[10001];

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
    freopen ( "rucsac.in", "r", stdin );
    scanf ( "%d%d", &n, &g );
    int x, y;
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d%d", &x, &y ),
        w[i] = x, p[i] = y;
    fclose(stdin);
}

void solve()
{
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= g; ++j )
            r[j] = v[j];
        for ( int j = 1; j <= g; ++j )
        {
            v[j] = r[j];
            if ( j >= w[i] )
                v[j] = max ( r[j], r[j-w[i]] + p[i] );
        }
    }
}

void write()
{
    freopen ( "rucsac.out", "w", stdout );
    printf ( "%d\n", v[g] );
    fclose(stdout);
}
