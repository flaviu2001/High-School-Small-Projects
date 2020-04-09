#include <cstdio>
#include <vector>
#define MAX 2005

using namespace std;

int n, va(1), vb, vc;
int a[MAX], b[MAX], c[MAX];
bool valid(1);
vector<char> q;

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
    freopen ( "bile.in", "r", stdin );
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d", &a[i] );
    for ( int j = 1; j <= n; ++j )
        scanf ( "%d", &c[j] );
    fclose(stdin);
}

void solve()
{
    while (vc != n)
    {
        if (c[vc+1] == b[vb])
            q.push_back('O'),
            --vb,
            ++vc;
        else if (va <= n)
        {
            while(a[va] != c[vc+1])
            {
                if (va == n)
                {
                    valid = 0;
                    return;
                }
                q.push_back('I'),
                b[++vb] = a[va++];
            }
            ++va;
            q.push_back('I');
            q.push_back('O');
            ++vc;
        }
        else
        {
            valid = 0;
            return;
        }
    }
}

void write()
{
    freopen ( "bile.out", "w", stdout );
    if (valid)
        for ( unsigned int i = 0; i < q.size(); ++i )
            printf ( "%c", q[i] );
    else printf ( "imposibil\n" );
    fclose(stdout);
}
