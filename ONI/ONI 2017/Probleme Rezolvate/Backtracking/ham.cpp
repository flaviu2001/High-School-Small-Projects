#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> v;
int n, k, m, nb[19];
long long x, y;

void read();
void solve();
int ham(int i1);
void write();

int main()
{
    read();
    solve();
    write();
    return 0;
}

void read()
{
    freopen ( "ham.in", "r", stdin );
    char q;
    scanf ( "%d%d%c", &n, &k, &q );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%c", &q ),
        x += (q == '1') * pow(10, n-i);
    fclose(stdin);
}

void solve()
{
    m = pow(2, n);
    for ( int i = 0; i < m; ++i )
        if ( ham(i) == k )
            v.push_back(i);
}

int ham(int i1)
{
    int p(0);
    long long q = x;
    for ( int i = 1; i <= n; ++i )
    {
        if ( i1 % 2 != q % 10 )
            ++p;
        i1 /= 2, q /= 10;
    }
    return p;
}

void write()
{
    freopen ( "ham.out", "w", stdout );
    for ( unsigned int i = 0; i < v.size(); ++i )
    {
        for ( int j = 1; j <= n; ++j )
            nb[j] = v[i] % 2,
            v[i] /= 2;
        for ( int j = n; j >= 1; --j )
            printf ( "%d", nb[j] );
        printf ( "\n" );
    }
    fclose(stdout);
}
