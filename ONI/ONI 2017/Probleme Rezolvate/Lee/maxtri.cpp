#include <fstream>
#define MAX 505

using namespace std;

int n, a[MAX][MAX], b[3][MAX][MAX];

void read();
void solve();
void write();

int main()
{
    read();
    solve();
    write();
}

void read()
{
    freopen ( "maxtri.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            scanf ( "%d", &a[i][j] );
    fclose(stdin);
}

void solve()
{
    int i, j, k;
    i = a[1][1];
    b[i%3][1][1] = i;
    for (i = 2; i <= n; ++i)
    {
        j = max( b[0][1][i-1], b[1][1][i-1] );
        j = max( b[2][1][i-1], j );
        k = j + a[1][i];
        b[k%3][1][i] = k;
    }
    for (i = 2; i <= n; ++i)
    {
        j = max( b[0][i-1][1], b[1][i-1][1] );
        j = max( b[2][i-1][1], j );
        k = j + a[i][1];
        b[k%3][i][1] = k;
    }
    for (i = 2; i <= n; ++i)
        for (j = 2; j <= n; ++j)
        {
            if (b[0][i - 1][j] > 0)
			{
				k = b[0][i - 1][j] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[1][i - 1][j] > 0)
			{
				k = b[1][i - 1][j] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[2][i - 1][j] > 0)
			{
				k = b[2][i - 1][j] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[0][i - 1][j - 1] > 0)
			{
				k = b[0][i - 1][j - 1] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[1][i - 1][j - 1] > 0)
			{
				k = b[1][i - 1][j - 1] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[2][i - 1][j - 1] > 0)
			{
				k = b[2][i - 1][j - 1] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[0][i][j - 1] > 0)
			{
				k = b[0][i][j - 1] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[1][i][j - 1] > 0)
			{
				k = b[1][i][j - 1] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
			if (b[2][i][j - 1] > 0)
			{
				k = b[2][i][j - 1] + a[i][j];
				b[k % 3][i][j] = max(k, b[k % 3][i][j]);
			}
        }
}

void write()
{
    freopen ( "maxtri.out", "w", stdout );
    printf ( "%d\n", b[0][n][n] );
    fclose(stdout);
}
