#include <fstream>
#define D (double)

using namespace std;

int main()
{
    freopen ( "ecuatii.in", "r", stdin );
    freopen ( "ecuatii.out", "w", stdout );
    int n, a, b, c, d, p, sign, x;
    bool what, side;
    double result;
    char q;
    scanf ( "%d%c", &n, &q );
    while (n--)
    {
        a = 0, b = 0, c = 0, d = 0, p = 0;
        sign = 1, what = 0, side = 1;
        do
        {
            scanf ( "%c", &q );

            if ( q >= '0' && q <= '9' )
                p = p * 10 + int(q-'0'), what = 0;

            else if ( q == 'x' )
            {
                x = p;
                if (!x)
                    x = 1;
                if (side)
                    a += x * sign;
                else c += x * sign;
                p = 0, what = 1;
            }

            else if ( q == '-' || q == '+' )
            {
                if (!what && side)
                    b += p * sign;
                else if (!what)
                    d += p * sign;
                if ( q == '-' )
                    sign = -1;
                else sign = 1;
                p = 0;
            }

            else if ( q == '=' )
            {
                side = 0;
                if (!what)
                    b += p * sign;
                sign = 1;
                p = 0;
            }
        }while ( q != 10 );
        if (!what)
            d += p * sign;
        if ( a == c && b == d )
            printf ( "infinit\n" );
        else if ( a == c )
            printf ( "imposibil\n" );
        else
        {
            result = D(d-b)/D(a-c);
            if ( result == int(result) )
            {
                printf ( "%d\n", int(result) );
                continue;
            }
            printf ( "%f\n", result );
        }
        //printf ( "%d %d %d %d\n", a, b, c, d );
    }
    return 0;
}
