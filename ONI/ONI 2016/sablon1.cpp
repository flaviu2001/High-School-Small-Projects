#include <fstream>

using namespace std;

char code[52][52], mes[1001], part1[251], part2[251], part3[251], part4[251], sablon[51][51];

int main()
{
    freopen ( "sablon1.in", "r", stdin );
    freopen ( "sablon1.out", "w", stdout );
    int n = 0, p, d, i, j, t = 1;
    char c;
    do
        scanf ( "%c", &mes[++n] );
    while ( mes[n] != 10 );
    --n;
    for ( p = 1; p <= n / 4; ++p )
    {
        part1[p] = mes[p];
        part2[p] = mes[ p + n / 4 ];
        part3[p] = mes[ p + n / 2 ];
        part4[p] = mes[ p + 3 * n / 4 ];
    }
    scanf ( "%d%c", &d, &c );
    for ( i = 1; i <= d; ++i )
        for ( j = 1; j <= d + 1; ++j )
            scanf ( "%c", &code[i][j] );
    for ( i = 1; i <= d; ++i )
        for ( j = 1; j <= d; ++j )
            if ( code[i][j] == part1[t] && code[j][d - i + 1] == part2[t] && code[d - i + 1][d - j + 1] == part3[t] && code[d - j + 1][i] == part4[t] )
                ++t, sablon[i][j] = 'O';
            else sablon[i][j] = 'X';
    for ( i = 1; i <= d; ++i )
    {
        for ( j = 1; j <= d; ++j )
            printf ( "%c", sablon[i][j] );
        printf ( "\n" );
    }
    return 0;
}
