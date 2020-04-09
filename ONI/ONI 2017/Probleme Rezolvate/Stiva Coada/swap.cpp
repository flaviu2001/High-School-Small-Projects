#include <cstdio>
#define MAX 90000

using namespace std;

int v[MAX], st[MAX];
int k, n, m, s;

void read();
void solve();
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
    freopen ( "swap.in", "r", stdin );
    char q;
    scanf ( "%d%c", &n, &q );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%c", &q ),
        v[i] = (q == '(');
    fclose(stdin);
}

void solve()
{
    k = m = 0;
    for ( int i = 1; i <= n; ++i)
    {
        if (v[i] == 1)
            st[++k] = i;
        else
        {
            if ( k > 1 && st[k] == i - 1 )
                ++m;
            s += i - st[k];
            --k;
        }
    }
}

void write()
{
    freopen ( "swap.out", "w", stdout );
    if (m)
        printf ( "%d\n%d\n%d\n", s, s-2, m );
    else printf ( "%d\n-1\n0\n", s );
    fclose(stdout);
}
