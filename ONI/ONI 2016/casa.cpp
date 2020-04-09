#include <fstream>
#define MAX 100001

using namespace std;

int p[MAX][4], t[MAX];

int main()
{
    freopen ( "casa.in", "r", stdin );
    freopen ( "casa.out", "w", stdout );
    int a[MAX], m, n, i, j, k, v, nc, op;
    char c[MAX], pct[6] = "xENSV";
    scanf ( "%d", &op );
    if ( op == 1 )
    {
        scanf ( "%d", &nc );
        for ( i = 1; i < nc; ++i )
            scanf ( "%d%c%c", &a[i], &c[i], &c[i] );
        int max_e(0), max_v(0), max_n(0), max_s(0);
        for ( i = 1; i <= nc; ++i )
        {
            for ( j = 0; j < 4; ++j )
                p[i+1][j] = p[a[i]][j];
            switch(c[i])
            {
                case 'N':
                    --p[i+1][2], ++p[i+1][1];
                    if ( p[i+1][1] > max_n ) max_n = p[i+1][1];
                    break;
                case 'S':
                    --p[i+1][1], ++p[i+1][2];
                    if ( p[i+1][2] > max_s ) max_s = p[i+1][2];
                    break;
                case 'E':
                    --p[i+1][3], ++p[i+1][0];
                    if ( p[i+1][0] > max_e ) max_e = p[i+1][0];
                    break;
                case 'V':
                    --p[i+1][0], ++p[i+1][3];
                    if ( p[i+1][3] > max_v ) max_v = p[i+1][3];
                    break;
            }
        }
        m = max_n + max_s + 1, n = max_e + max_v + 1;
        printf ( "%d %d\n", m, n );
        p[1][1] = max_n + 1, p[1][2] = max_v + 1;
        for ( i = 1; i < nc; ++i )
            switch(c[i])
            {
                case 'N':
                    p[i+1][1] = p[a[i]][1] - 1, p[i+1][2] = p[a[i]][2];
                    break;
                case 'S':
                    p[i+1][1] = p[a[i]][1] + 1, p[i+1][2] = p[a[i]][2];
                    break;
                case 'E':
                    p[i+1][1] = p[a[i]][1], p[i+1][2] = p[a[i]][2] + 1;
                    break;
                case 'V':
                    p[i+1][1] = p[a[i]][1], p[i+1][2] = p[a[i]][2] - 1;
                    break;
            }
        for ( i = 1; i <= nc; ++i )
            t[(p[i][1]-1)*n + p[i][2]-1] = 1;
        for ( i = 1; i <= m; ++i )
        {
            for ( j = 1; j <= n; ++j )
                printf ( "%d ", t[(i-1)*n+j-1] );
            printf ( "\n" );
        }
        fclose (stdin);
        fclose(stdout);
        return 0;
    }
    scanf ( "%d%d", &m, &n );
    nc = 0, k = 0;
    for ( j = 1; j <= n; ++j )
    {
        scanf ( "%d", &t[j-1] );
        nc += t[j-1];
        if ( !k && t[j-1] == 1 )
            k = j;
    }
    for ( i = 2; i <= m; ++i )
        for ( j = 1; j <= n; ++j )
            scanf ( "%d", &t[(i-1)*n+j-1] ), nc += t[(i-1)*n+j-1];
    printf ( "%d %d\n", nc, k );
    p[1][0] = 1, p[1][1] = k, t[k-1] = 2, k = 1, v = 1;
    while( v < nc )
    {
        i = p[k][0], j = p[k][1];
        if ( j < n && t[(i-1)*n+j] == 1 )
            t[(i-1)*n+j] = ++v + 1, p[v][0] = i, p[v][1] = j + 1, p[v][2] = 1;
        if ( i > 1 && t[(i-2)*n+j-1] == 1 )
            t[(i-2)*n+j-1] = ++v + 1, p[v][0] = i - 1, p[v][1] = j, p[v][2] = 2;
        if ( i < m && t[i*n+j-1] == 1 )
            t[i*n+j-1] = ++v + 1, p[v][0] = i + 1, p[v][1] = j, p[v][2] = 3;
        if ( j > 1 && t[(i-1)*n+j-2] == 1 )
            t[(i-1)*n+j-2] = ++v + 1, p[v][0] = i, p[v][1] = j - 1, p[v][2] = 4;
        ++k;
    }
    for ( k = 2; k <= nc; ++k )
    {
        i = p[k][0], j = p[k][1];
        switch (p[k][2])
        {
            case 1: --j; break;
            case 2: ++i; break;
            case 3: --i; break;
            case 4: ++j; break;
        }
        printf ( "%d %c\n", t[(i-1)*n+j-1]-1, pct[p[k][2]] );
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
