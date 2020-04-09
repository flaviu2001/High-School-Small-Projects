#include <cstdio>

using namespace std;

int c[1030][15];
int n, k, m(1), p(2), q, a, t(1);

void read();
void recursive(int x, int y);
void write();

int main()
{
    read();
    for (int i = 1; i <= k; ++i)
        t *= 2;
    t = m/t;
    if (k)
        recursive(1, m);
    write();
    return 0;
}

void read()
{
    freopen ("tren.in", "r", stdin);
    scanf ("%d%d", &n, &k);
    --k;
    for (int i = 1; i <= n; ++i)
        m *= 2;
    a = m;
    for (int i = 1; i <= m; ++i)
        scanf ("%d", &c[i][1]);
    fclose(stdin);
}

void recursive(int x, int y) //x, y limits of vector to split
{
    for (int i = x; i <= y; ++i)
        if (i%2)
            c[++q][p] = c[i][p-1];

    for (int i = x; i <= y; ++i)
        if (!(i%2))
            c[++q][p] = c[i][p-1];

    if (q >= m && k)
    {
        ++p;
        q = 0;
        --k;
        a /= 2;

        if (k)
            recursive(1, a);
    }
    else if (k)
        recursive(y+1, y+(y-x)+1);
}

void write()
{
    freopen ("tren.out", "w", stdout);
    int s, mx(0);
    for (int i = 1; i <= m-t+1; ++i)
    {
        s = 0;
        for (int j = i; j <= i+t-1; ++j)
            s += c[j][p-1];
        if (s > mx)
            mx = s;
    }
    printf ("%d\n", mx);
}
