#include <fstream>

using namespace std;

int main()
{
    freopen ( "sir7.in", "r", stdin );
    freopen ( "sir7.out", "w", stdout );
    int n, d, k = 0, r;
    scanf ( "%d", &n );
    for ( d = 1; d <= n / 2; ++d )
    {
        r = n - 2 * d;
        while ( r > 0 )
            k += r, r -= d;
    }
    printf ( "%d", k );
    return 0;
}
