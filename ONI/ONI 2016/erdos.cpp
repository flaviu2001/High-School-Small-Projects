#include <fstream>

using namespace std;

long long int v[51][51], r[51];

int main()
{
    FILE*fin=fopen("erdos.in","r");
    FILE*fout=fopen("erdos.out","w");
    long long int p, q, x, i, j, u, t, z;
    bool ok, go;
    fscanf( fin, "%lld%lld%lld", &p, &q, &x );
    v[1][1] = x;
    for ( u = 1; u <= p * q; ++u )
    {
        fscanf( fin, "%lld", &x );
        //printf ( "%d ", x );
        for ( i = p; i > 0; --i )
        {
            ok = 0;
            for ( j = 1; j <= q; ++j )
                if ( v[i][j] != 0 && x % v[i][j] == 0 )
                    ok = 1;
            if ( ok )
            {
                for ( t = 1; ; ++t )
                    if( v[i + 1][t] == 0 )
                    {
                        v[i + 1][t] = x;
                        z = t;
                        break;
                    }
                break;
            }
        }
        go = 1;
        if ( !ok )
            for ( j = 1; j <= q + 1 && go; ++j )
                if ( v[1][j] == 0 )
                    v[1][j] = x, go = 0, z = j, i = 0;
        if ( z > q )
        {
            fprintf ( fout, "%lld\n", q );
            for ( j = 1; j <= q + 1; ++j )
                fprintf ( fout, "%lld ", v[i+1][j] );
            return 0;
        }
        if ( i == p )
        {
            fprintf ( fout, "%lld\n", p);
            r[p+1] = x;
            for ( ; i > 0; --i )
                for ( j = 1; j <= q; ++j )
                    if ( v[i][j] != 0 && x % v[i][j] == 0 )
                        r[i] = v[i][j], x = v[i][j];
            for ( i = 1; i <= p + 1; ++i )
                fprintf( fout, "%lld ", r[i] );
            return 0;
        }
    }
    return 0;
}