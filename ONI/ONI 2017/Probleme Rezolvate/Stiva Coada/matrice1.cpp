#include <cstdio>
#define MAX 1005

using namespace std;

int n, m, b, b1l, b1c, b2l, b2c, c;
int a[MAX][MAX], h[MAX], t[MAX], s[MAX], st[MAX], tp[MAX];

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
    freopen ( "matrice1.in", "r", stdin );
    scanf ( "%d%d", &n, &m );
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            scanf ( "%d", &a[i][j] );
    fclose(stdin);
}

void solve()
{
    int top;
    for ( int j = 0; j < m; ++j )
    {
        for ( int i = 0; i <= n; ++i )
        {
            if (i == n)
                h[i] = 0;
            else if (j == 0)
                h[i] = 1;
            else if (t[i] == 0)
                t[i] = (a[i][j] > a[i][j-1]) ? 1 : 2,
                ++h[i];
            else if (t[i] == 1)
            {
                if (a[i][j] < a[i][j-1])
                    h[i] = j - s[i] + 1,
                    s[i] = j - 1,
                    t[i] = 2;
                else ++h[i];
            }
            else if (t[i] == 2)
            {
                if (a[i][j] > a[i][j-1])
                    h[i] = j - s[i] + 1,
                    s[i] = j - 1,
                    t[i] = 1;
                else ++h[i];
            }

            top = i;
            while (c > 0 && h[i] <= st[c-1])
            {
                top = tp[c-1];
                if (st[c-1] * (i - top) > b)
                    b = st[c-1] * (i-top),
                    b1l = top,
                    b2l = i - 1,
                    b1c = j - st[c-1] + 1,
                    b2c = j;
                --c;
            }
            if (h[i] > 0)
                st[c] = h[i],
                tp[c++] = top;
        }
    }
}

void write()
{
    freopen ( "matrice1.out", "w", stdout );
    printf("%d %d %d %d\n", b1l + 1, b1c + 1, b2l + 1, b2c + 1);
    fclose(stdout);
}
