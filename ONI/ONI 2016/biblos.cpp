#include <fstream>
#define MAX 30001

using namespace std;

int n, maxn, v[MAX];

void read_solve()
{
    freopen ( "biblos.in", "r", stdin );
    scanf ( "%d", &n );
    int x, r;
    for ( int i = 1; i <= n; ++i )
    {
        scanf ( "%d", &x );
        if ( i < 6 )
        {
            if ( i == 1 ) {v[i] = x; continue;}
            if ( i == 2 ) {v[i] = 0; continue;}
            if ( i == 3 ) {v[i] = v[1] + x; continue;}
            if ( i == 4 ) {v[i] = v[1] + x; continue;}
            v[i] = v[3] + x; continue;
        }
        r = max(v[i-2], v[i-3]);
        v[i] = r + x;
        if ( v[i] > maxn )
            maxn = v[i];
    }
    fclose(stdin);
}

void write()
{
    freopen ( "biblos.out", "w", stdout );
    printf ( "%d\n", maxn );
    fclose(stdout);
}

int main()
{
    read_solve();
    write();
    return 0;
}
