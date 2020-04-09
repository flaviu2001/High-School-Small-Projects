#include <fstream>
#include <algorithm>
#include <cmath>

#define MAX 10005

using namespace std;

struct i_got_tourrete_syndrome
{
    int a, b;
}v[MAX], r[MAX];

int d[MAX], n, t[MAX], k, q[MAX];

void read()
{
    freopen ( "sant1.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d%d", &v[i].a, &v[i].b ), d[i] = i;
    fclose(stdin);
}

void sort_this_shit()
{
    int i, j, p, km, kM;
    for ( i = 1; i < n; ++i )
    {
        km = v[i].a, kM = v[i].b, p = i;
        for ( j = i + 1; j <= n; ++j )
            if ( v[j].a < km )
                kM = v[j].b, km = v[j].a, p = j;
            else if ( v[j].a == km && v[j].b > kM )
                kM = v[j].b, km = v[j].a, p = j;
        swap(d[p], d[i]); swap(v[i], v[p]);
    }
}

void write()
{
    freopen ( "sant1.out", "w", stdout );
    printf ( "%d\n", k );
    int p = 0, j, z;
    for ( int i = 1; i <= k; ++i )
    {
        printf ( "%d %d %d\n", i, r[i].a, r[i].b );
        for ( j = 1; j <= t[i]; ++j )
            q[j] = d[++p];
        z = t[i];
        sort ( q + 1, q + z );
        for ( j = 1; j <= t[i]; ++j )
            printf ( "%d ", q[j] );
        printf ( "\n" );
    }
    fclose(stdout);
}

int main()
{
    read();
    sort_this_shit();
    int i, m1, m2, j;
    bool ok;
    for ( j = 1; j <= n; ++j )
    {
        ok = 0;
        for( i = 1; i <= k && !ok; ++i )
        {
            m1 = ( r[i].a + v[j].a + abs ( r[i].a - v[j].a ) ) / 2;
            m2 = ( r[i].b + v[j].b - abs ( r[i].b - v[j].b ) ) / 2;
            if ( m2 >= m1 ) ok = 1, r[i].a = m1, r[i].b = m2, ++t[i];
        }
        if ( !ok )
            r[++k].a = v[j].a, r[k].b = v[j].b, t[i] = 1;
    }
    write();
    return 0;
}
