#include <fstream>
#define MAX 30
#define NMAX 2010

using namespace std;

int m, n, v[MAX], w, W, y, frq[MAX];
char c[NMAX][MAX];

void read_prepare();
void build_matrix();
void write();

int main()
{
    read_prepare();
    build_matrix();
    write();
    return 0;
}

void read_prepare()
{
    freopen ( "mesaj3.in", "r", stdin );
    char q[MAX];
    scanf ( "%d%c", &m, &q[0] );
    for ( int i = 1; i <= m; ++i )
        scanf ( "%c", &q[i] );
    scanf ( "%d%c", &n, &c[0][0] );

    w = n / m, W = n % m;
    int p;
    for ( int i = 1; i <= m; ++i )
    {
        p = 1;
        for ( int j = 1; j <= m; ++j )
            if ( q[i] > q[j] )
                ++p;
        v[i] = p;
    }
}

void build_matrix()
{
    int t;
    for ( int i = 1; i <= m; ++i )
    {
        for ( t = 1; ; ++t )
            if ( v[t] == i )
                break;
        y = w + (t <= W);
        for ( int j = 1; j <= y; ++j )
        {
            scanf ( "%c", &c[j][t] );
            if ( c[j][t] >= 'A' && c[j][t] <= 'Z' )
                ++frq[int(c[j][t]-'A'+1)];
        }
    }
    fclose(stdin);
}

void write()
{
    freopen ( "mesaj3.out", "w", stdout );
    int minn(2001), in;
    for ( int i = 1; i <= 29; ++i )
        if ( frq[i] && frq[i] < minn )
            minn = frq[i], in = i;
    printf ( "%c\n", in + 'A' - 1 );

    for ( int i = 1; i <= w; ++i )
        for ( int j = 1; j <= m; ++j )
            printf ( "%c", c[i][j] );
    for ( int j = 1; j <= W; ++j )
        printf ( "%c", c[w+1][j] );
    fclose(stdout);
}