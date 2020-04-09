#include <fstream>
#include <algorithm>
#include <climits>
#define M 502

using namespace std;

int mat [M] [M], n, m, sum[M][M];
int mn = INT_MAX;

int calc(int i, int k1 )
{
    int mn = INT_MAX, s = 0, j, s1;
    if ( i > 1 && i < n )
    {
        s = sum[i][m];
        for ( j = 0; j <= k1; ++j )
        {
            s1  = sum[i-1][k1-j],
            s1 += sum[i+1][j],
            s1 += s;
            if ( s1 < mn ) mn = s1;
        }
    }
    else if ( i == 1 )
            mn = sum[1][m] + sum[2][k1];
    else mn = sum[n][m] + sum[n-1][k1];
    return mn;
}

int main()
{
    freopen( "lenes.in", "r", stdin );
    freopen ( "lenes.out", "w", stdout );
    int test, i, j, k1, k2, s, s1, s2, i1, i2, i3, gg;
    int mn = INT_MAX;
    scanf ( "%d%d%d%d%d", &test, &m, &n, &k1, &k2 );
    for ( i = 1; i <= m; ++i )
        for ( j = 1; j <= n; ++j )
            scanf ( "%d", &mat [j] [i] );
    for ( j = 1; j <= n; ++j )
    {
        sort  ( mat[j] + 1, mat[j] + m + 1 );
        sum[j][1] = mat[j][1];
        for ( i = 2; i <= m; ++i )
            sum[j][i] = sum[j][i-1] + mat[j][i];
    }
    if ( test == 1 )
    {
        for ( i = 1; i <= n; ++i )
        {
            s = calc(i, k1);
            if ( s < mn && s ) mn = s;
        }
        printf ( "%d\n", mn );
    }
    else
    {
        for ( i = 2; i < n - 1; ++i )
        {
            s = sum [i-1][k1] + sum[i][m] + sum[i+1][m] + sum[i+2][k2];
            if ( s < mn ) mn = s;
            s = sum [i-1][k2] + sum[i][m] + sum[i+1][m] + sum[i+2][k1];
            if ( s < mn ) mn = s;
        }
        for ( int tt = 1; tt < 3; ++tt )
        {
            for ( i = 2; i <= n - 3; ++i )
            {
                i1 = k1, i2 = 0, i3 = k2;
                s = sum[i][m] + sum[i+2][m];
                do
                {
                    gg = 0;
                    if( i1 >= 1 && i2 <= m && mat[i+1][i2+1] < mat[i-1][i1] && mat[i+3][i3] <= mat[i-1][i1] )
                        --i1, ++i2, gg = 1;
                    else if ( i3 >= 1 && i2 <= m && mat[i+1][i2+1] < mat[i+3][i3] && mat[i-1][i1] <= mat[i+3][i3] )
                        --i3, ++i2, gg = 1;
                }while(gg);
                s1 = s + sum[i-1][i1] + sum[i+1][i2] + sum[i+3][i3];
                if ( s1 < mn ) mn = s1;
            }
            s = sum[1][m] + sum[3][m];
            if ( n > 3 )
            {
                for ( j = 0; j <= k2; ++j )
                    if ( k1 + j <= m && k2 > j )
                    {
                        s1  = sum[2][k1+j],
                        s1 += sum[4][k2-j],
                        s1 += s;
                        if ( s1 < mn ) mn = s1;
                    }
            }
            else
            {
                s = s + sum[2][k1+k2];
                if ( s < mn ) mn = s;
            }
            if ( n > 3 )
            {
                s = sum[n-2][m] + sum[n][m];
                for ( j = 0; j <= k1; ++j )
                    if ( k2 + j <= m && k1 > j )
                    {
                        s1  = sum[n-3][k1-j],
                        s1 += sum[n-1][k2+j],
                        s1 += s;
                        if ( s1 < mn ) mn = s1;
                    }
            }
            i1 = k1, k1 = k2, k2 = i1;
        }
        for ( i = 1; i <= n - 3; ++i )
        {
            s1 = calc(i, k1);
            s2 = calc(i, k2);
            for ( i1 = i + 3; i1 <= n; ++i1 )
            {
                s = s1 + calc(i1, k2);
                if ( s < mn ) mn = s;
                s = s2 + calc(i1, k1);
                if ( s < mn ) mn = s;
            }
        }
        printf ( "%d\n", mn );
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
