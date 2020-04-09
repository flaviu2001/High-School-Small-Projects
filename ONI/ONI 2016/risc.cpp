#include <fstream>
#include <algorithm>
#include <vector>

#define VI vector<int>

using namespace std;

int test, n, mx, p, cA, cD, k;
vector <int> a, b, c;
bool valid = 1;

void read()
{
    freopen ( "risc.in", "r", stdin );
    scanf ( "%d%d", &test, &n );
    a = VI(n);
    for ( int i = 0; i < n; ++i )
    {
        scanf ( "%d", &a[i] );
        if ( a[i] > mx )
            mx = a[i], p = i;
    }
    fclose(stdin);
}

void solve_a()
{
    int i;
    for ( i = 0; i < n; ++i )
    {
        if ( i && i <= p && a[i-1] > a[i] )
        {
            valid = 0;
            return;
        }
        if ( i > p && a[i-1] < a[i] )
        {
            valid = 0;
            return;
        }
    }
    if ( a[p-1] > a[n-1] && p )
        {
            valid = 0;
            return;
        }
}

void write_a ()
{
    freopen ( "risc.out", "w", stdout );
    if ( !valid )
        printf ( "-1\n" );
    else printf ( "%d\n", p+1 );
    fclose(stdout);
}

void solve_b()
{
    int i, j;
    b = VI(n), c = VI(mx+1);
    for ( i = 0; i < n; ++i )
        ++c[a[i]];
    for ( i = 1; i <= mx; ++i )
        c[i] += c[i-1];
    for ( i = 0; i < n; ++i )
        b[c[a[i]]-1] = a[i];
    for ( i = 0, j = 0; i < n; ++i )
    {
        if ( a[i] == b[j] )
            ++cA, ++j;
        if ( i == p )
            k = cA;
    }
    for ( i = p, j = n - 1; i < n; ++i )
        if( a[i] == b[j] )
            ++cD, --j;
}

void write_b()
{
    freopen ( "risc.out", "w", stdout );
    printf ( "%d\n", n - max(cA, cD+k) );
    fclose (stdout);
}

int main()
{
    read();
    if ( test == 1 )
        solve_a(), write_a();
    else
        solve_b(), write_b();
    return 0;
}
