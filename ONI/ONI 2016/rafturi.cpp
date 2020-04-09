#include <fstream>
#define M 10002

using namespace std;

int carti[M], inaltimi[M];

int main()
{
    freopen ( "rafturi.in", "r", stdin );
    freopen ( "rafturi.out", "w", stdout );
    int n, c, i, j, h, k;
    scanf( "%d%d", &c, &n );
    for ( j = 1; j <= n; ++j )
    {
        scanf ( "%d%d", &i, &k );
        if ( carti[i] < k ) carti[i] = k;
    }
    carti[0] = 0;
    inaltimi[0] = 0;
    for ( i = 1; i <= c; ++i )
    {
        inaltimi[i] = 2000000001;
        h = carti[i];
        if ( inaltimi[i-1] + h < inaltimi[i] )
            inaltimi[i] = inaltimi[i-1] + h;
        for ( j = i - 1; j > i - 3 && j > 0; --j )
        {
            if ( h < carti[j] ) h = carti[j];
            if ( inaltimi[j-1] + h < inaltimi[i] )
                inaltimi[i] = inaltimi[j-1] + h;
        }
    }
    printf ( "%d\n", inaltimi[c] );
    return 0;
}
