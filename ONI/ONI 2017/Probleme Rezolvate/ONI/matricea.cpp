#include <cstdio>
#define MAX 30002

using namespace std;

int n, m, a, zmx, nsol;
int c[MAX], r[MAX];

void read();
void solve();
void update(int z1, int z2, int sol, int p, int q);
void write();

int main()
{
    read();
    solve();
    write();
    return 0;
}

void read()
{
    freopen ( "matricea.in", "r", stdin );
    scanf ( "%d%d%d", &n, &m, &a );
    for ( int i = 0; i < n; ++i )
        scanf ( "%d", &r[i] );
    for ( int j = 0; j < m; ++j )
        scanf ( "%d", &c[j] );
    fclose(stdin);
}

void solve()
{
    int mnz, mxz, nz, nmx, nmn;
    for ( int d = 1; d <= a && d <= n; ++d )
    {
        if ( a%d || a/d > m )
            continue;
        mnz = m + 1, mxz = 0, nz = 0, nmx = 0, nmn = 0;
        for ( int i = 0; i < m; ++i )
        {
            nz += !c[i];
            if ( i >= a/d )
                nz -= !c[i-a/d];
            else if ( i < a/d - 1 )
                continue;
            if ( mnz > nz )
                mnz = nz, nmn = 1;
            else if ( mnz == nz )
                ++nmn;
            if ( mxz < nz )
                mxz = nz, nmx = 1;
            else if ( mxz == nz )
                ++nmx;
        }
        nz = 0;
        for ( int i = 0; i < n; ++i )
        {
            nz += !r[i];
            if ( i >= d )
                nz -= !r[i-d];
            else if ( i < d - 1 )
                continue;
            if (nz * 2 == d)
                update(nz, mnz, m-a/d+1, d, a/d);
            else if (nz * 2 > d)
                update(nz, mxz, nmx, d, a/d);
            else update(nz, mnz, nmn, d, a/d);
        }
    }
}

void update(int z1, int z2, int sol, int p, int q)
{
    int z = z1*z2 + (p-z1)*(q-z2);
    if ( zmx < z )
        zmx = z, nsol = sol;
    else if ( zmx == z )
        nsol += sol;
}
 void write()
 {
     freopen ( "matricea.out", "w", stdout );
     printf ( "%d %d", zmx, nsol );
     fclose(stdout);
 }
