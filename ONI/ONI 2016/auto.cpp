#include <fstream>
#include <vector>

#define MAX 9001

#define PB push_back
#define RS resize
#define VI vector<int>
#define SZ size()

using namespace std;

VI v, sol, st(MAX), pos(MAX);
int n, steps;

bool check(int k)
{
    int i, t = 1, p = 0, val = 0;
    for ( i = 1; i <= n; ++i )
    {
        ++steps;
        while( t <= p && pos[t] <= i - k )
            val -= st[t++];
        if ( v[i] < val || ( i > n - k + 1 && v[i] != val ) )
            return 0;
        if ( v[i] > val )
            pos[++p] = i, st[p] = v[i] - val, val = v[i];
    }
    return 1;
}

int main()
{
    freopen ( "auto.in", "r", stdin );
    freopen ( "auto.out", "w", stdout );
    int t, i, k, j, d;
    scanf ( "%d", &t );
    while (t--)
    {
        d = 0;
        scanf ( "%d", &n );
        v.RS(n+1); sol.RS(0);
        for ( i = 1; i <= n; ++i )
            scanf ( "%d", &v[i] ), d += v[i];
        for ( i = 1; i <= n; ++i )
            if ( d % i == 0 && check(i) ) sol.PB(i);
        for ( i = 0; i < sol.SZ; ++i )
            for ( j = i + 1; j < sol.SZ; ++j )
                if( sol[i] > sol[j] )
                    k = sol[i], sol[i] = sol[j], sol[j] = k;
        for ( i = 0; i < sol.SZ; ++i )
            printf ( "%d ", sol[i] );
        printf ( "\n" );
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
