#include <fstream>
#define nMax 100001
#define INF ( 1 << 30 )

using namespace std;

int food[nMax], position[nMax], n;

int check (int k)
{
    long long carry=0, x;
    int i;
    for ( i = 1; i < n; ++i )
    {
        x = food[i] + carry;
        if ( x < k )
            carry = x - k - ( position[i+1] - position[i] );
        else
        {
           carry = x - k - ( position[i+1] - position[i] );
           if ( carry < 0 ) carry = 0;
        }
    }
    return ( food[n] + carry ) >= k;
}

int main()
{
    FILE * fin = fopen ( "ants.in", "r" );
    FILE * fout = fopen ( "ants.out", "w" );
    int i, s = 0, d = INF, m;
    fscanf ( fin, "%d", &n );
    for ( i = 1; i <= n; ++i )
        fscanf ( fin, "%d%d", &position[i], &food[i] );
    for ( m = ( s + d ) >> 1; s <= d; m = ( s + d ) >> 1 )
    {
        if ( check ( m ) && check ( m + 1 ) )
            s = m + 1;
        else if ( !check ( m ) )
            d = m - 1;
            else
            {
                fprintf ( fout, "%d", m );
                return 0;
            }
    }
    return 0;
}
