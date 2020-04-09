#include <fstream>

using namespace std;

int main()
{
    freopen ( "coduri.in", "r", stdin );
    freopen ( "coduri.out", "w", stdout );
    long long int n, i, s;
    scanf ( "%lld", &n );
    s = n * ( n + 1 ) * ( 2 * n + 1 ) / 6;
    s = s * s * s * s;
    for ( i = 1; i <=n; ++i )
        printf ( "%lld\n", s * i );
    return 0;
}
