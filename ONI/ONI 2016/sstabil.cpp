#include <fstream>
#define MAX 1000005

using namespace std;

int v[MAX], r[MAX], n, k;

void read()
{
    freopen ( "sstabil.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d", &v[i] );
}

void write()
{
    freopen ( "sstabil.out", "w", stdout );
    for ( int i = k; i >= 1; --i )
        printf ( "%d", r[i] );
}

void solve()
{
    int j, s, p, t;
    v[0] = 9, v[n+1] = 9, r[0] = 9;
    while ( n > 0 )
    {
        j = n, s = 0;
        do s += v[j--];
            while ( s < 10 );
        p = n, t = v[p];
        while ( s - t > 9 || t + r[k] < 10 )
            t += v[--p];
        r[++k] = t, n = p - 1;
    }
}

int main()
{
    read();
    solve();
    write();
    return 0;
}
