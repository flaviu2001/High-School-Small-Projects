#include <cstdio>

using namespace std;

int n, m, r[14001], w[7001], v[9001];
long long s;

void read();
void solve();
int max(int x, int y);
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
    freopen ( "medie.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d", &v[i] ),
        ++w[v[i]],
        m = max(m, v[i]);
    fclose(stdin);
}

int max(int x, int y)
{
    if ( x > y )
        return x;
    return y;
}

void solve()
{
    int d;
    for ( int i = 1; i <= n; ++i )
        for ( int j = i + 1; j <= n; ++j )
            ++r[v[i] + v[j]];
    for ( int i = 1; i <= m; ++i )
        if (r[2*i] && w[i])
            s += r[2*i]*w[i]-w[i]*(w[i]-1);
}

void write()
{
    freopen ( "medie.out", "w", stdout );
    printf ( "%lld\n", s );
    fclose(stdout);
}
