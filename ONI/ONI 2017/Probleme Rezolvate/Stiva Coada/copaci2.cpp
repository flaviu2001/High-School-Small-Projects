#include <cstdio>
#define MAX 200005

using namespace std;

int st[MAX], dr[MAX], v[MAX], vl[205], n;

void read();
void left();
void right();
int solve();
void write();

int main()
{
    read();
    left();
    right();
    write();
    return 0;
}

void read()
{
    freopen ( "copaci2.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d", &v[i] );
    fclose(stdin);
}

void left()
{
    int p;
    for ( int i = 1; i <= n; ++i )
    {
        p = 0;
        for ( int j = v[i]; j < 201; ++j )
            if (vl[j] > p)
                p = vl[j];
        st[i] = p;
        vl[v[i]] = i;
    }
}

void right()
{
    int p;
    for ( int i = 0; i <= 204; ++i )
        vl[i] = 0;
    for ( int i = n; i; --i )
    {
        p = n+1;
        for ( int j = v[i]; j < 201; ++j )
            if (vl[j] && vl[j] < p)
                p = vl[j];
        dr[i] = p;
        vl[v[i]] = i;
    }
}

int solve()
{
    int s(0), p, q;
    for (int i = 2; i < n; ++i)
    {
        p = st[i]; q = dr[i];
        if (p == 0 || q == n+1)
            continue;
        if (dr[p] >= q && st[q] <= p)
            ++s;
    }
    return s;
}

void write()
{
    freopen ( "copaci2.out", "w", stdout );
    printf ( "%d\n", solve() );
    fclose(stdout);
}
