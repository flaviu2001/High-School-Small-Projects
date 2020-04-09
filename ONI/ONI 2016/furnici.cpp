#include <fstream>

using namespace std;

int main()
{
    freopen ( "furnici1.in", "r", stdin );
    freopen ( "furnici1.out", "w", stdout );
    int n, m, x, max = 0;
    char c;
    scanf ( "%d%d", &n, &m );
    for ( ; m; --m )
    {
        scanf( "%d%c%c", &x, &c, &c );
        if ( c == 'S' && x > max )
            max = x;
        else if ( c == 'D' && (n - x) > max )
            max = n - x;
    }
    printf ( "%d\n", max );
    fclose(stdin);
    fclose(stdout);
    return 0;
}
