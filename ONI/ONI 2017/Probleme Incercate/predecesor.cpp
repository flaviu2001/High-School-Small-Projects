#include <cstdio>
#define MAX 500001

using namespace std;

int n, v[MAX], st[MAX], vf, stv[MAX];
bool vis[MAX];

void read();
int solve();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "predecesor.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d", &v[i] );
    fclose(stdin);
}

int solve()
{
    int s(0);
    st[1] = v[1];
    vf = 1;
    for ( int i = 2; i <= n; ++i )
        if ( v[i] > st[vf] )
            st[++vf] = v[i],
            stv[vf] = i;
        else
        {
            while ( vf && st[vf--] > v[i] )
                if (!vis[vf])
                    ++s;
            if (!vf)
                st[++vf] = v[i],
                stv[vf] = i;
            else
                vis[vf] = 1,
                st[++vf] = v[i],
                stv[vf] = i;
        }
    for ( int i = 1; i <= vf; ++i )
        if (!vis[stv[i]])
            ++s;
    return s;
}

void write()
{
    freopen ( "predecesor.out", "w", stdout );
    printf ( "%d\n", solve() );
    fclose(stdout);
}
