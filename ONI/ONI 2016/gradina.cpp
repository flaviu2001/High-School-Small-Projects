#include <fstream>
#define M 1001
using namespace std;

int mat[M][M], s[M][M];

int main()
{
    freopen ( "gradina.in", "r", stdin );
    freopen ( "gradina.out", "w", stdout );
    int i, j, n, p, k, q, w, s1, maxs = 0, a = 1;
    scanf ( "%d%d%d", &n, &p, &k );
    for ( i = 1; i <= p; ++i )
        scanf ( "%d%d", &q, &w ),
        mat[q][w] = 1;
    for ( i = 1; i <= n; ++i )
        for ( j = 1; j <= n; ++j )
        {
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            if ( mat[i][j] )
                ++s[i][j];
            if ( i >= k && j >= k )
            {
                s1 = s[i][j] - s[i-k][j] - s[i][j-k] + s[i-k][j-k];
                if ( s1 > maxs )
                    maxs = s1, a = 1;
                else if ( s1 == maxs )
                    ++a;
            }
        }
    printf ( "%d\n%d", maxs, a );
    return 0;
}
