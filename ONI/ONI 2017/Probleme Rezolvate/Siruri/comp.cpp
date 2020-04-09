#include <fstream>
#include <vector>

using namespace std;

vector<int> solutions;

int main()
{
    freopen ( "comp.in", "r", stdin );
    freopen ( "comp.out", "w", stdout );
    int n, p, s, d, lower_sign(0);
    bool side;
    char q, comp;
    scanf ( "%d%c", &n, &q );
    while(n--)
    {
        p = 0, s = 0, d = 0;
        side = 1;
        do
        {
            scanf ( "%c", &q );
            if ( q >= '0' && q <= '9' )
                p = p * 10 + int(q-'0');
            else if ( q == 'u' )
            {
                if (side)
                    s += p;
                else d += p;
                p = 0;
            }
            else if ( q == 'z' )
            {
                if (side)
                    s += p * 10;
                else d += p * 10;
                p = 0;
            }
            else if ( q == 's' )
            {
                if (side)
                    s += p * 100;
                else d += p * 100;
                p = 0;
            }
            else if ( q == 'm' )
            {
                if (side)
                    s += p * 1000;
                else d += p * 1000;
                p = 0;
            }
            else if ( q == '<' )
                side = 0,
                comp = q,
                ++lower_sign;
            else if ( q == '>' )
                side = 0,
                comp = q;
        }while ( q != 10 );
        if ( ( s > d && comp == '>' ) || ( s < d && comp == '<' ) )
            solutions.push_back(1);
        else solutions.push_back(0);
        //printf ( "%d %d\n", s, d );
    }
    printf ( "%d\n", lower_sign );
    for ( unsigned int i = 0; i < solutions.size(); ++i )
        printf ( "%d\n", solutions[i] );
    return 0;
}
