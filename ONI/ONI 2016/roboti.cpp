#include <fstream>
#include <algorithm>
#include <deque>

#define PII pair<int, int>
#define I q1.front().first
#define J q1.front().second

using namespace std;

deque<PII> q, q1, q2, q3;
int n, m;

int how_many( int L )
{
    int lastJ, lastI, i1, i2, j1, c = 0;
    bool first(1);
    for ( q1 = q; !q1.empty(); q1.swap(q2) )
    {
        ++c, lastJ = J, lastI = I, first = 1;
        for ( ; !q1.empty(); )
        {
            if ( !q1.empty() && J <= lastJ && J > lastJ - L )
            {
                q1.pop_front();
                continue;
            }
            if ( first && !q1.empty() && J <= lastJ && I <= lastI + L - 1 )
            {
                q1.pop_front();
                continue;
            }
            if ( !q1.empty() && J <= lastJ - L )
            {
                q2.push_back(q1.front());
                q1.pop_front();
                continue;
            }
            if ( J > lastJ )
            {
                i1 = I; i2 = min(n, i1 + L - 1), j1 = max(J, L);
                while(!q1.empty() && I >= i1 && I <= i2 )
                {
                    if ( !q1.empty() && J <= j1 && J >= lastJ - L + 1 )
                    {
                        q1.pop_front();
                        continue;
                    }
                    if ( first && !q1.empty() && J <= lastJ && I <= lastI + L - 1 )
                    {
                        q1.pop_front();
                        continue;
                    }
                    if ( !q1.empty() && J <= lastJ - L )
                    {
                        q2.push_back(q1.front());
                        q1.pop_front();
                        continue;
                    }
                    if ( !q1.empty() && J > j1 )
                    {
                        q3.push_back(q1.front());
                        q1.pop_front();
                        continue;
                    }
                }
                for ( ; !q3.empty(); q3.pop_back() )
                    q1.push_front(q3.back());
                lastJ = j1,
                lastI = i1,
                first = 0;
            }
        }
    }
    return c;
}

int main()
{
    freopen ( "roboti.in", "r", stdin );
    freopen ( "roboti.out", "w", stdout );
    int x, y, p, T, L;
    scanf ( "%d%d%d%d", &p, &n, &m, &T );
    for ( int i = 1; i <= T; ++i )
        scanf ( "%d%d", &x, &y ),
        q.push_back({x, y});
    sort(q.begin(), q.end());
    if ( p == 1 )
    {
        scanf ( "%d", &L );
        printf ( "%d\n", how_many(L) );
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else
    {
        int Q, k, lo, hi, Lmin;
        scanf ( "%d", &Q );
        for ( ; Q; --Q )
        {
            scanf ( "%d", &k );
            lo = 1, hi = n / k + 1;
            while( lo <= hi )
            {
                L = (lo + hi) / 2;
                if ( how_many(L) <= k )
                    Lmin = L,
                    hi = L - 1;
                else lo = L + 1;
            }
            printf ( "%d\n", Lmin );
        }
        fclose(stdin);
        fclose(stdout);
    }
    return 0;
}
