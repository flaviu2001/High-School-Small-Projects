#include <fstream>
#define Nmax 1010
#define INF ( 1 << 30 )

using namespace std;

int v[Nmax][Nmax];
int r[Nmax];
int mj,st,dr,i,j,n,m,p,val,poz,k,ok,sol,ok1;

int bsearch( int x, int i ) {

	int ret = 0 ;
	int m,s = 1 , d = v[i][0], y ;

	for( m = (s+d)>>1 ; s <= d ; m = (s+d)>>1 )
    {
		y = v[i][m] ;

		if( x == y )
        {
			ok = 1 ;
			return m ;
		}
		if( x > y )
            ret = m, s = m + 1 ;
		else d = m - 1 ;
	}

	return ret ;
}

int main()
{
    FILE * fin = fopen ( "vectori1.in", "r" );
    FILE * fout = fopen ( "vectori1.out", "w" );
    fscanf( fin, "%d %d", &n, &m );
    for( i = 1 ; i <= n ; i++ )
    {
		fscanf ( fin, "%d", &v[i][0] );
		for( j = 1 ; j <= v[i][0] ; j++ )
			fscanf( fin, "%d", &v[i][j] );
	}
	for( i = 1 ; i <= m ; i++ ) {

		fscanf ( fin, "%d %d", &k, &p );
		for( j = 1; j <= p; j++ )
			fscanf ( fin, "%d", &r[j] );
		st = -INF, dr = INF ;
		for( mj = (st+dr)>>1; st <= dr; mj = (st+dr)>>1 )
        {
			poz = 0, ok = 0, ok1 = 0 ;
			for( j = 1; j <= p; j++ )
            {
				val = bsearch( mj, r[j] ) ;
				poz += val ;
				if( ok )
					ok = 0, ok1 = 1, sol = v[ r[j] ] [val];
			}
			if( poz < k ) st = mj + 1 ;
			else if( poz > k ) dr = mj - 1 ;
			else
			{
				if( ok1 != 1 )
					dr = mj - 1;
				else
					break ;
			}
		}

		fprintf ( fout, "%d\n", sol );
	}
    return 0;
}
