#include <fstream>

using namespace std;

long long aq = 0, n, x, p;

void read ()
{
    freopen ( "pesti.in", "r", stdin );
    scanf ( "%lld%lld", &n, &x );
}

void cer_a()
{
    long long int d = 2;
    while ( d < n )
        d *= 2, ++p;
}

void cer_bc()
{
    long long int a = 1, b = n, k, aux = x, e = 0;
    for ( long long int i = 1; i <= p && b - a > 1; ++i )
    {
        if ( ( x - a + 1 ) % 2 == 0 )
            x = ( a + b ) / 2 + ( x - a + 1 ) / 2, a = ( a + b ) / 2 + 1;
        else
            x = a + ( x - a ) / 2, b = ( a + b ) / 2;
        if ( x != aux )
            aq += e + 1, e = 0;
        else ++e;
        aux = x;
    }
}

void scrie()
{
    freopen ( "pesti.out", "w", stdout );
    cer_a(), cer_bc();
    if ( !aq ) aq = 1;
    printf ( "%lld %lld %lld", p, x, aq );
}

int main()
{
    read(), scrie();
    return 0;
}
