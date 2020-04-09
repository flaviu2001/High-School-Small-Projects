#include <iostream>
#include <fstream>

#define MAX 20005

using namespace std;

int n;
char c[MAX], r[MAX];

void read();
int solve();
bool is_perm(int k);
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "circular.in", "r", stdin );
    scanf ( "%d%c", &n, &c[1] );
    for ( int i = 1; i <= n + 1; ++i )
        scanf ( "%c", &c[i] );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%c", &r[i] );
    fclose(stdin);
}

int solve()
{
    int k(0);
    for ( ; k < n; ++k )
        if ( is_perm(k) )
            break;
    if ( k == n )
        k = -1;
    return k;
}

bool is_perm(int k)
{
    bool ok(1);
    int p;
    for ( int i = 1; i <= n; ++i )
    {
        p = i + k;
        if ( p > n )
            p -= n;
        if ( r[i] != c[p] )
            return 0;
    }
    return 1;
}

void write()
{
    freopen ( "circular.out", "w", stdout );
    printf ( "%d\n", solve() );
    fclose(stdout);
}
