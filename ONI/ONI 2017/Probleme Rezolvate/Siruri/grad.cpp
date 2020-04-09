#include <fstream>

#define MAX 50000

using namespace std;

bool b[MAX];
int words, groups;

void read_solve();
void write();

int main()
{
    read_solve();
    write();
    return 0;
}

void read_solve()
{
    freopen ( "grad.in", "r", stdin );
    int n, p(0);
    char q, c;
    scanf ( "%d%c", &n, &q );
    for ( int i = 1; i <= n; ++i )
    {
        c = q;
        scanf ( "%c", &q );
        if ( q <= 'z' && q >= 'a' )
        {
            p += q - 96;
        }
        else if ( c <= 'z' && c >= 'a' )
        {
            ++words;
            if ( !b[p] && p )
                ++groups;
            b[p] = 1;
            p = 0;
        }
        if (i == n)
        {
            ++words;
            if ( !b[p] && p )
                ++groups;
            b[p] = 1;
            p = 0;

        }
    }
    fclose(stdin);
}

void write()
{
    freopen ( "grad.out", "w", stdout );
    printf ( "%d\n%d", words, groups );
    fclose(stdout);
}
