#include <fstream>
#define M 5001

using namespace std;

int v[M], minst[M], maxst[M], mindr[M], maxdr[M];

int main()
{
    freopen ( "split.in", "r", stdin );
    freopen ( "split.out", "w", stdout );
    int n, i, j, k, min1 = 100000001, max1 = 0, ss, sd, di, x, sm = 0, d1 = 0, dk = 0, xi = 2, xj = 4, xk = 6;
    scanf ( "%d", &n );
    for ( i = 1; i <= n; ++i )
    {
        scanf ( "%d", &v[i] );
        if ( i == 1 )
            minst[1] = v[1], maxst[1] = v[1];
        else
        {
            if ( minst[i-1] > v[i] ) minst[i] = v[i];
            else minst[i] = minst [i-1];
            if ( maxst[i-1] < v[i] ) maxst[i] = v[i];
            else maxst[i] = maxst[i-1];
        }
    }
    mindr[n] = v[n], maxdr[n] = v[n];
    for ( i = n - 1; i > 0; --i )
    {
        if ( mindr[i+1] > v[i] ) mindr[i] = v[i];
        else mindr[i] = mindr[i+1];
        if ( maxdr[i+1] < v[i] ) maxdr[i] = v[i];
        else maxdr[i] = maxdr[i+1];
    }
    for ( j = 4; j <= n - 3; ++j )
    {
        if ( v[j] > v[j - 1] )
			max1 = v[j],
			min1 = v[j - 1];
		else
			max1 = v[j - 1],
			min1 = v[j];
		ss = max1 - min1 + maxst[j-2] - minst[j-2];
		di = j - 2;
		for (i = j - 2; i > 2; --i)
		{
			if ( v[i] > max1 ) max1 = v[i];
			if ( v[i] < min1 ) min1 = v[i];
			x = max1 - min1 + maxst[i-1] - minst[i-1];
			if (ss <= x) ss = x, di = i-1;
		}
		if ( v[j+1] > v[j+2] )
			max1 = v[j+1],
			min1 = v[j+2];
		else
			max1 = v[j+2],
			min1 = v[j+1];
		sd = max1 - min1 + maxdr[j+3] - mindr[j+3];
		dk = j + 2;
		for ( k = j + 3; k <= n - 2; ++k )
		{
			if ( v[k] > max1 ) max1 = v[k];
			if ( v[k] < min1 ) min1 = v[k];
			x = max1 - min1 + maxdr[k+1] - mindr[k+1];
			if (sd < x) sd = x, dk = k;
		}

		x = ss + sd;
		if (x > sm)
			sm = x, xi = di, xj = j, xk = dk;
    }
    printf ( "%d\n%d %d %d", sm, xi, xj, xk );
    return 0;
}
