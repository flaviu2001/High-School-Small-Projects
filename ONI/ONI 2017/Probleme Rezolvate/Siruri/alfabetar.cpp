#include <fstream>
#define MAX 210
#define NMAX 110

using namespace std;

char c[MAX][NMAX];
int v[NMAX], n, m;

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
    freopen ( "alfabetar.in", "r", stdin );
    int p;
    scanf ( "%d%c", &n, &c[1][1] );
    for ( int i = 1; i <= n; ++i )
    {
        p = 0;
        do
        {
            scanf ( "%c", &c[++p][i] );
        }while ( c[p][i] != 10 );
        v[i] = --p;
        if ( p > m )
            m = p;
    }
    for ( int i = 1; i <= n; ++i )
        for ( int j = v[i] + 1; j <= m; ++j )
            c[j][i] = ' ';
    fclose(stdin);
}

void write()
{
    freopen ( "alfabetar.out", "w", stdout );
    for ( int i = m; i >= 1; --i )
    {
        for ( int j = 1; j <= n; ++j )
            printf ( "%c", c[i][j] );
        printf ( "\n" );
    }
    fclose(stdout);
}
