#include <fstream>
#define MAX 210

using namespace std;

int t, p;
char c[MAX];

void read();
void hit();
void write();

int main()
{
    read();
    hit();
    write();
    return 0;
}

void read()
{
    freopen ( "zuma.in", "r", stdin );
    scanf ( "%d%c", &t, &c[1] );
    do
        scanf ( "%c", &c[++p] );
    while ( c[p] != 10 );
    --p;
    fclose(stdin);
}

void hit()
{
    int d, s, t1 = t-1, t2 = t+1;
    bool ok = 1;
    char m = c[t];
    if ( c[t] != c[t+1] || c[t] != c[t-1] )
        return;
    do
    {
        d = 0, s = 0;
        for ( int i = t1 + 1; c[i] == m && i <= p && i > 0; ++i, ++d );
        for ( int i = t2 - 1; c[i] == m && i <= p && i > 0; --i, ++s );
        //printf ( "%d %d\n", s, d );
        if ( s + d > 2 + ok && s > 0 && d > 0 )
        {
            for ( int i = t1 + 1; c[i] == m && i <= p && i > 0; ++i )
                c[i] = ' ';
            for ( int i = t2 - 1 - ok; c[i] == m && i <= p && i > 0; --i )
                c[i] = ' ';
            c[t] = ' ';
        }
        else break;
        t1 = t1 + d;
        t2 = t2 - s;
        m = c[t1+1];
        ok = 0;
    }while ( c[t1] == c[t2] );
}

void write()
{
    freopen ( "zuma.out", "w", stdout );
    for ( int i = 1; i <= p; ++i )
        if ( c[i] >= 'A' && c[i] <= 'Z' )
            printf ( "%c", c[i] );
    printf ( "\n" );
    fclose(stdout);
}
