#include <fstream>

using namespace std;

int n, m, k1, l1, c1, k2, l2, c2, x, y, z, v[105][105][105], xc, yc ,zc;
struct room { short x, y, z; } c[1000005];
short dx[] = { -1, 0, 0, 0, 0, 1 }, dy[]={0,-1,0,0,1,0},dz[]={0,0,-1,1,0,0};
void read()
{
    freopen ( "traseu3.in", "r", stdin );
    scanf ( "%d%d%d%d%d%d%d%d", &n, &m, &k1, &l1, &c1, &k2, &l2, &c2 );
    for ( ; m > 0; --m )
        scanf ( "%d%d%d", &x, &y, &z ), v[x][y][z] = -1;
}

void enclosure()
{
    int i, j;
    for ( i = 0; i <= n + 1; ++i )
        for ( j = 0; j <= n + 1; ++j )
            v[0][i][j] = -1, v[n+1][i][j] = - 1,
            v[i][0][j] = -1, v[i][n+1][j] = - 1,
            v[i][j][0] = -1, v[i][j][n+1] = - 1;
}

void q()
{
    int p = 1, u = 1, i;
    c[1].x = k1, c[1].y = l1, c[1].z = c1;
    v[k1][l1][c1] = 1;
    while ( p <= u && !v[k2][l2][c2] )
    {
        x = c[p].x, y = c[p].y, z = c[p++].z;
        for ( i = 0; i < 6; ++i )
        {
            xc = x + dx[i], yc = y + dy[i], zc = z + dz[i];
            if ( !v[xc][yc][zc] )
                v[xc][yc][zc] = v[x][y][z] + 1, c[++u].x = xc, c[u].y = yc, c[u].z = zc ;
        }
    }
}

void where ( int value )
{
    while ( value > 0 )
    {
        if (  value == v[x-1][y][z] + 1 ) -- x;
        else if ( value == v[x][y-1][z] + 1 ) --y;
            else if ( value == v[x][y][z-1] + 1 ) --z;
                else if ( value == v[x][y][z+1] +1 ) ++z;
                    else if ( value == v[x][y+1][z] + 1 ) ++y;
                        else if ( value == v[x+1][y][z] + 1 ) ++ x;
        --value;
        c[value].x = x, c[value].y = y, c[value].z = z;
    }
}

int main()
{
    read(), enclosure(), q();
    freopen ( "traseu3.out", "w", stdout );
    int value = v[k2][l2][c2], i;
    printf ( "%d\n", value );
    c[value].x = k2, c[value].y = l2, c[value].z = c2;
    where( value );
    for ( i = 1; i <= value; ++i )
        printf ( "%d %d %d\n", c[i].x, c[i].y, c[i].z );
    return 0;
}
