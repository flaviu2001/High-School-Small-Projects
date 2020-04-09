#include <fstream>
#include <string.h>

#define MAX 101
#define MOD     13007
#define pos(i, j)    ((i-1) * n + (j))
#define swp(x, y)    (aux = v[x], v[x] = v[y], v[y] = aux)

using namespace std;

int v[MAX * MAX], n, m, np, primes[MAX * MAX], B[MAX * MAX], E[MAX * MAX];

void intro()
{
    freopen ( "perspic.in", "r", stdin );
    scanf ( "%d%d", &n, &m );
    int i, j, x, y, x1, y1, aux;
    char c;
    for ( i = 1; i <= n * n; ++i )
        v[i] = i;
    for ( ; m; --m )
    {
        scanf ( "%c%c%d%d",&c, &c, &x, &y );
        switch (c)
        {
            case 'R':
                for ( j = 1; j <= n; ++j )
                    swp(pos(x, j), pos(y, j));
                break;
            case 'C':
                for ( i = 1; i <= n; ++i )
                    swp(pos(i, x), pos(i, y));
                break;
            case 'E':
                scanf ( "%d%d", &x1, &y1 );
                swp(pos(x, y), pos(x1, y1));
                break;
            default:
                printf ( "You fucked up son\n" );
                break;
        }
    }
}

void prime_Gen()
{
    int j, k, pr;
    primes[++np] = 2;
    for ( k = 3; k < n * n; k += 2 )
    {
        pr = 1;
        for ( j = 1; pr && ( primes[j] * primes[j] <= k ) && j <= np; ++j )
            pr = k % primes[j];
        if (pr)
            primes[++np] = k;
    }
}

void cycles()
{
    int i, len, j, d, pow, x;
    for (i = 1; i <= n * n; ++i)
    {
        for (len = 0, j = i; !B[j]; ++len)
            B[j] = 1, j = v[j];
        if (len)
        {
            for (x = len, d = 1; x > 1 && primes[d] * primes[d] <= x && d <= np; ++d)
            {
                for (pow = 0; x % primes[d] == 0; ++pow)
                    x /= primes[d];
                if (E[primes[d]] < pow) {
                    E[primes[d]] = pow;
                }
            }
            if (x > 1 && !E[x])
                E[x] = 1;
        }
    }
}

void GCM()
{
    freopen ( "perspic.out", "w", stdout );
    int i, res, j;
    for ( res = 1, i = 1; i < n * n; ++i )
        for ( j = 0; j < E[i]; ++j )
            res = (((long long)res * (i % MOD)) % MOD);
    printf ( "%d\n", res );
}

int main()
{
    intro();
    prime_Gen();
    cycles();
    GCM();
    return 0;
}
