#include <fstream>
#define MAX 175

using namespace std;

int v[MAX][MAX], r[MAX][MAX];

int main()
{
    freopen ( "origami.in", "r", stdin );
    freopen ( "origami.out", "w", stdout );
    int d, j, i, n, t, how, where, height, widht, depth = 0, help;
    scanf ( "%d%d", &n, &t ), height = n, widht = n;
    for ( i = 1; i <= n; ++i )
        for ( j = 1; j <= n; ++j )
            v[i][j] = 1;
    for ( ; t > 0; --t )
    {
        scanf ( "%d%d", &how, &where );
        if ( how == 1 )
        {
            if ( 2 * where <= widht )
            {
                for ( i = 1; i <= height; ++i )
                    for ( j = where + 1, d = 0; j <= 2 * where; ++j, ++d )
                        v[i][j] += v[i][where-d];
                for ( i = 1; i <= height; ++i )
                    for ( j = 1; j <= widht - where; ++j )
                        v[i][j] = v[i][j+where];
                widht -= where;
            }
            else
            {
                help = widht - where;
                for ( i = 1; i <= height; ++i )
                    for ( j = widht - 2 * help + 1, d = 0; j <= widht - help; ++j, ++d )
                        v[i][j] += v[i][widht - d];
                widht = where;
                for ( i = 1; i <= height; ++i )
                    for ( j = 1, d = widht; j <= widht; ++j, --d )
                        r[i][j] = v[i][d];
                for ( i = 1; i <= height; ++i )
                    for ( j = 1; j <= widht; ++j )
                        v[i][j] = r[i][j];
            }
        }
        else
        {
            if ( 2 * where <= height )
            {
                for ( i = where + 1, d = i - 1; d > 0; ++i, --d )
                    for ( j = 1; j <= widht; ++j )
                        v[i][j] += v[d][j];
                for ( i = 1; i <= height - where; ++i )
                    for ( j = 1; j <= widht; ++j )
                        r[i][j] = v[i + where][j];
                for ( i = 1; i <= height - where; ++i )
                    for ( j = 1; j <= widht; ++j )
                        v[i][j] = r[i][j];
                height -= where;
            }
            else
            {
                for ( i = where, d = where + 1; d <= height; --i, ++d )
                    for ( j = 1; j <= widht; ++j )
                        v[i][j] += v[d][j];
                for ( i = where, d = 1; d <= where; --i, ++d )
                    for ( j = 1; j <= widht; ++j )
                        r[d][j] = v[i][j];
                for ( i = 1; i <= where; ++i )
                    for ( j = 1; j <= widht; ++j )
                        v[i][j] = r[i][j];
                height = where;
            }
        }
    }
    for ( i = 1; i <= height; ++i )
        for ( j = 1; j <= widht; ++j )
            if ( v[i][j] > depth )
                depth = v[i][j];
    printf ( "%d %d %d", height, widht, depth );
    return 0;
}