#include <fstream>
#define MAX 30005

using namespace std;

int n, a, b, v[MAX];

void read()
{
    freopen ( "ab2.in", "r", stdin );
    scanf ( "%d%d%d", &n, &a, &b );
    fclose(stdin);
}

void solve()
{
    freopen ( "ab2.out", "w", stdout );
    int x = n, i, j;
    for ( i = a - 1; i >= 0; --i )
        v[i] = min( n - i, b ),
        n -= v[i];
    for ( i = 0; i < a; ++i )
    {
        for ( j = n + v[i]; j > n; --j )
            printf ( "%d ", j );
        n += v[i];
    }
    fclose(stdout);
}

int main()
{
    read();
    solve();
    return 0;
}
