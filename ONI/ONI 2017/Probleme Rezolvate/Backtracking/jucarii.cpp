#include <cstdio>
#include <algorithm>

using namespace std;

int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int n, k, p;
int l[11], u[11];

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
    freopen ( "jucarii.in", "r", stdin );
    scanf ( "%d%d%d", &n, &k, &p );
}

void solve()
{
    int maxj, in, g(0);
    do
    {
        for ( int i = 1; i <= 10; ++i )
            l[i] = u[i] = 0;
        l[n] = 1;
        for ( int i = n - 1; i; --i )
        {
            maxj = 0, in = 0;
            for ( int j = n; j > i; --j )
                if ( v[i] < v[j] && l[j] >= maxj )
                    maxj = l[j], in = j;
            l[i] = maxj + 1;
            u[i] = in;
        }
        maxj = 0;
        for ( int i = 1; i <= n; ++i )
            if ( l[i] > maxj )
                maxj = l[i];
        if ( maxj >= k )
            ++g;
        if ( g == p )
            break;
    }while(next_permutation(v + 1, v + n + 1));
}

void write()
{
    freopen ( "jucarii.out", "w", stdout );
    for ( int i = 1; i <= n; ++i )
        printf ( "%d ", v[i] );
    printf ( "\n" );
    fclose(stdout);
}
