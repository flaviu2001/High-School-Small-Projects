#include <fstream>
#include <string>

using namespace std;

int n;
string A, B, V;

void read();
void solve();
void make_next();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "sirul.in", "r", stdin );
    scanf ( "%d", &n );
    A = "a";
    B = "b";
    fclose (stdin);
}

void solve()
{
    int k(2);
    while ( k < n )
        make_next(), ++k;
}

void make_next()
{
    V = B;
    B = B + A;
    A = V;
}

void write()
{
    freopen ( "sirul.out", "w", stdout );
    if ( n == 1 )
    {
        printf ( "a\n" );
        fclose(stdout);
        return;
    }
    else if ( n == 2 )
    {
        printf ( "b\n" );
        fclose(stdout);
        return;
    }
    solve();
    printf ( "%s\n", B.c_str() );
    fclose(stdout);
}
