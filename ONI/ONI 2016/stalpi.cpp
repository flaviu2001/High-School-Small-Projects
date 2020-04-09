#include <fstream>
#include <cmath>

#define MAX1 30001
#define MAX2 10001
#define MAX3 101

using namespace std;

int cb1[MAX1], cb2[MAX1];
int x1[MAX2], x2[MAX2], z1[MAX2], z2[MAX2], x[MAX3], y[MAX3];
int n1,n2,n,i,d,k,poz,cul,d1,d2,j,dif,dift,i1,i2,w1,w2,w,m1,m2;
double dmin;

void read()
{
    freopen ( "stalpi.in", "r", stdin );
    scanf ( "%d%d", &n, &d );
    for ( i = 1; i <= n; ++i )
    {
        scanf ( "%d%d", &poz, &cul );
        cb1[poz] = i * 100 + cul - 1;
        if ( cul > k ) k = cul;
        if ( poz > d1 ) d1 = poz;
    }
    for ( i = 1; i <= n; ++i )
    {
        scanf ( "%d%d", &poz, &cul );
        cb2[poz] = i * 100 + cul - 1;
        if ( poz > d2 ) d2 = poz;
    }
}

void solve()
{
    for ( cul = 1; cul <= k; ++cul )
    {
        n1 = 0, m1 = 0;
        for ( i = 0; i <= d1; ++i )
            if ( cb1[i] )
            {
                ++m1;
                if ( cb1[i] % 100 + 1 == cul )
                    x1[++n1] = i, z1[n1] = cb1[i] / 100;
            }
        n2 = 0, m2 = 0;
        for ( i = 0; i <= d2; ++i )
            if ( cb2[i] )
            {
                ++m2;
                if ( cb2[i] % 100 + 1 == cul )
                    x2[++n2] = i, z2[n2] = cb2[i] / 100;
            }
        i = 1, j = 1;
        dift = x1[i] - x2[j], i1 = z1[i], i2 = z2[j];
        if ( dift < 0 )
            dift = -dift;
        while ( i <= n1 && j <= n2 && dift )
        {
            dif = x1[i] - x2[j];
            if ( dif < 0 )
                dif = -dif;
            if ( dif < dift )
                dift = dif, i1 = z1[i], i2 = z2[j];
            if ( x1[i] < x2[j] ) ++i;
            else ++j;
        }
        x[cul] = i1; y[cul] = i2;
        dmin += sqrt( (double) dift * dift + d * d );
    }
    w1 = (int)floor(dmin);
    w2 = (int)floor( (dmin - w1) * 1000 );
}

void write()
{
    freopen ( "stalpi.out", "w", stdout );
    printf ( "%d.", w1 );
    if ( w2 < 10 )
        printf ( "00%d\n", w2 );
    else if ( w2 < 100 )
        printf ( "0%d\n", w2 );
    else printf ( "%d\n", w2 );
    for ( cul = 1; cul <= k; ++cul )
        printf ( "%d %d\n", x[cul], y[cul] );
}

int main()
{
    read(), solve(), write();
    return 0;
}
