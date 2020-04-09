#include <fstream>
#include <algorithm>

using namespace std;

int w[7][4], v[7][4], s, r[] = {1, 2, 3, 4, 5, 6}, maxx;

void read();
void solve();
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
    freopen ( "prisme.in", "r", stdin );
    for ( int i = 1; i <= 6; ++i )
        for ( int j = 1; j <= 3; ++j )
            scanf ( "%d", &w[i][j] );
    fclose(stdin);
}

void solve()
{
    bool ok;
    int kk;
    do
    {
        for ( int i = 1; i <= 6; ++i )
            for ( int j = 1; j <= 3; ++j )
                v[i][j] = w[i][j];
        s = 0, kk = 0;
        for ( int i = 0; i <= 4; ++i )
        {
            ok = 1;
            for ( int j = 1; j <= 3 && ok; ++j )
                for ( int k = 1; k <= 3; ++k )
                    if ( v[r[i]][j] == v[r[i+1]][k] && v[r[i]][j] )
                    {
                        v[r[i]][j] = 0;
                        v[r[i+1]][k] = 0;
                        ok = 0;
                        break;
                    }
        }
        ok = 1;
        for ( int j = 1; j <= 3 && ok; ++j )
            for ( int k = 1; k <= 3; ++k )
                if ( v[r[5]][j] == v[r[0]][k] && v[r[5]][j] )
                {
                    v[r[5]][j] = 0;
                    v[r[0]][k] = 0;
                    ok = 0;
                    break;
                }
        for ( int i = 0; i <= 5; ++i )
            for ( int j = 1; j <= 3; ++j )
            {
                s += v[r[i]][j];
                if (!v[r[i]][j])
                    ++kk;
            }
        if ( kk == 12 && s > maxx )
            maxx = s;
    }while(next_permutation(r, r + 6));
}

void write()
{
    freopen ( "prisme.out", "w", stdout );
    printf ( "%d\n", maxx );
    fclose(stdout);
}
