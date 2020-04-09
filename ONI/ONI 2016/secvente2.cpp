#include <fstream>
#define NMAX 1000001
using namespace std;

int v, r[NMAX];

int main()
{
    freopen ( "secvente2.in", "r", stdin );
    freopen ( "secvente2.out", "w", stdout );
    int n, i, j, maxi = 1, s;
    scanf ( "%d", &n );
    for ( i = 1; i <= n; ++i )
    {
        scanf ( "%d", &v );
        if ( r[v+1] == 0 && r[v-1] == 0 )
            r[v] = 1;
        else if ( r[v+1] == 0 )
        {
            r[v] = r[v-1] + 1;
            if ( r[v] > maxi )
                maxi = r[v];
            ++r[v-r[v]+1];
        }
        else if ( r[v-1] == 0 )
        {
            r[v] = r[v+1] + 1;
            if ( r[v] > maxi )
                maxi = r[v];
            ++r[v+r[v]-1];
        }
        else
        {
            r[v] = r[v-1] + r[v+1] + 1;
            if ( r[v] > maxi )
                maxi = r[v];
            s = r[v-1];
            r[v-s] = r[v];
            s = r[v+1];
            r[v+s] = r[v];
        }
        printf ( "%d\n", maxi );
    }
    return 0;
}
