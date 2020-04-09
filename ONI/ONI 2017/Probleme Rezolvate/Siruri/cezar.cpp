#include <fstream>

#define MAX 300

using namespace std;

char c[MAX];
int v[15], p;

void read();
void encrypt();
void write();

int main()
{
    read();
    encrypt();
    write();
    return 0;
}

void read()
{
    freopen ( "cezar.in", "r", stdin );
    do
        scanf ( "%c", &c[++p] );
    while(c[p] != 10);
    --p;
    for ( int i = 1; i <= 10; ++i )
        scanf ( "%d", &v[i] );
    fclose(stdin);
}

void encrypt()
{
    int f(0);
    for ( int i = 1; i <= p; ++i )
    {
        if ( c[i] == ' ' )
            continue;
        ++f;
        if ( f > 10 )
            f = 1;
        c[i] -= v[f];
        if ( c[i] < 'A' )
            c[i] += 26;
    }
}

void write()
{
    freopen ( "cezar.out", "w", stdout );
    for ( int i = 1; i <= p; ++i )
        printf ( "%c", c[i] );
    fclose(stdout);
}