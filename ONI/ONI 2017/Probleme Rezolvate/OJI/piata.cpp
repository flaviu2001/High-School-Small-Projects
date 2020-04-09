#include <fstream>

using namespace std;

int n, pi_x, pi_y, pf_x, pf_y;

void read();
int solve();
int vij(int i1, int j1);
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "piata.in", "r", stdin );
    scanf ( "%d%d%d%d%d\n", &n, &pi_x, &pi_y, &pf_x, &pf_y );
    fclose(stdin);
}

int solve()
{
    int s(0), x, t;
    for ( int j = pi_y; j <= pf_y; ++j )
        x = vij(pi_x, j), s += x;
    t = s;
    for ( int i = pi_x + 1; i <= pf_x; ++i )
        s -= x, s += vij(i, pi_y), x = vij(i, pf_y), t += s;
    return t;
}

int vij(int i1, int j1)
{
    int x, s(0);
    if ( j1 >= i1 )
        x = j1 - i1 + 1;
    else // if ( j1 < i1 )
        x = n + j1 - i1 + 1;
    while (x)
        s += x % 10, x /= 10;
    return s;
}

void write()
{
    freopen ( "piata.out", "w", stdout );
    printf ( "%d\n", solve() );
    fclose(stdout);
}