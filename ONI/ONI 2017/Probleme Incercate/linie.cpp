#include <cstdio>

using namespace std;

int v[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int r[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int w[13][13], n, s, mx, y;

void read();
void solve();
int abs (int x1);
bool straight();
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
    freopen ( "linie.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            scanf ( "%d", &w[i][j] ), s += w[i][j];
    mx = s;
    fclose(stdin);
}

void solve()
{
    int k, x;
    while ( !straight() )
        {
            ++v[n];
            k = n;
            while ( v[k] == n )
                if ( k != 1 )
                    v[k--] = 1, ++v[k];
                else return;
        }
    while (1)
    {
        x = 0;
        for ( int i = 1; i <= n; ++i )
            for ( int j = 1; j <= v[i]; ++j )
                x += w[i][j];
        if ( abs (x - (s - x)) < mx )
        {
            mx = abs (x - (s - x));
            for ( int i = 1; i <= n; ++i )
                r[i] = v[i];
            y = x;
        }
        ++v[n];
        k = n;
        while ( v[k] == n )
            if ( k != 1 )
                v[k--] = 1, ++v[k];
            else return;
        while ( !straight() )
        {
            ++v[n];
            k = n;
            while ( v[k] == n )
                if ( k != 1 )
                    v[k--] = 1, ++v[k];
                else return;
        }
    }
}

bool straight()
{
    for ( int i = 1; i < n; ++i )
        if ( v[i] == v[i+1] )
            return 0;
    return 1;
}

int abs (int x1)
{
    if ( x1 >= 0 )
        return x1;
    else return -x1;
}

void write()
{
    freopen ( "linie.out", "w", stdout );
    printf ( "%d\n%d\n", y, s - y );
    for ( int i = 1; i <= n; ++i )
        printf ( "%d ", r[i] );
    fclose(stdout);
}
