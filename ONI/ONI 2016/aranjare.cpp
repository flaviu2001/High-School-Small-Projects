#include <fstream>
#define INF 100001

using namespace std;

int p[2 * INF], v[2 * INF];

int main()
{
    freopen ( "aranjare2.in", "r", stdin );
    freopen ( "aranjare2.out", "w", stdout );
    int n, i;
    scanf ( "%d", &n );
    for ( i = 1; i <= 2 * n; ++i )
        p[i] = i, v[i] = i;
    for( i = 1; i < n; ++i )
	{
		if ( v [2 * i] != n + i )
			v[ p [n + i] ] = v[ 2 * i ],
			p[ v [ 2 * i ] ] = p [ n + i ],
			printf ( "%d %d\n", 2 * i, p [n + i] );
		if ( v [ 2 * i + 1 ] != i + 1 )
			v [ p [ i + 1 ] ] = v [ 2 * i + 1 ],
			p [ v [ 2 * i + 1 ] ] = p [ i + 1 ],
			printf ( "%d %d\n", 2 * i + 1, p [i + 1] );
	}
    return 0;
}
