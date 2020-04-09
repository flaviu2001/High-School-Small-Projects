#include <fstream>

using namespace std;

int n, p;
char c[22][22];

void read();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "criptmat.in", "r", stdin );
    scanf ( "%d%c", &n, &c[1][1] );
    bool way = 1;
    do
    {
        if ( way == 1 )
        {
            ++p;
            for ( int i = 1; i <= n; ++i )
                scanf ( "%c", &c[p][i] );
            way = 0;
        }
        else
        {
            ++p;
            for ( int i = n; i > 0; --i )
                scanf ( "%c", &c[p][i] );
            way = 1;
        }
    }while ( c[p][1] != 10 && c[p][n] != 10 );
}

void write()
{
    freopen ( "criptmat.out", "w", stdout );
    for ( int j = 1; j <= n; ++j )
        for ( int i = 1; i < p; ++i )
            printf ( "%c", c[i][j] );
    fclose(stdout);
}
