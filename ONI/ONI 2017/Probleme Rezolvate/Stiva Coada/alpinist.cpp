#include <cstdio>
#include <vector>
#define MAX 105

#define va v[c[p].x][c[p].y]
#define vu v[c[p].x+dx[i]][c[p].y+dy[i]]
#define ra r[c[p].x][c[p].y]
#define ru r[c[p].x+dx[i]][c[p].y+dy[i]]

using namespace std;

struct lee
{
    int x, y;
}c[MAX*MAX], pi, pf;

vector<char> ans;
int n, m, v[MAX][MAX], r[MAX][MAX], wf;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int h, d;

void read();
void solve();
bool check(int x, int y);
void route();
char next(int o);
void write();

int main()
{
    read();
    solve();
    route();
    write();
    return 0;
}

void read()
{
    freopen ( "alpinist.in", "r", stdin );
    scanf ( "%d%d", &n, &m );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            scanf ( "%d", &v[i][j] );
    fclose(stdin);
}

void solve()
{
    int mxx(1001), x, y, mx, p, f;
    bool ok(0);
    while(1)
    {
        for ( int i = 1; i <= n; ++i )
            for ( int j = 1; j <= m; ++j )
                r[i][j] = 0;
        mx = -1;
        for ( int i = 1; i <= n; ++i )
            for ( int j = 1; j <= m; ++j )
                if (v[i][j] > mx && v[i][j] < mxx)
                {
                    if (!ok)
                        mx = v[i][j],
                        x = i,
                        y = j,
                        c[1].x = i,
                        c[1].y = j;
                    else if (i >= x && j >= y && (i != x || j != y))
                        mx = v[i][j],
                        x = i,
                        y = j,
                        c[1].x = i,
                        c[1].y = j,
                        ok = 0;
                }
                else if (v[i][j] == mx && v[i][j] < mxx)
                    ok = 1;
        if (!ok)
            mxx = mx;
        r[c[1].x][c[1].y] = 1;
        p = 0, f = 1;
        while(p != f)
        {
            ++p;
            for ( int i = 0; i < 4; ++i )
                if ( check(c[p].x + dx[i], c[p].y + dy[i]) && va - vu <= 100 && !ru )
                {
                    ru = ra + 1;
                    c[++f].x = c[p].x + dx[i],
                    c[f].y = c[p].y + dy[i];
                    if (!vu)
                    {
                        h = mx;
                        d = ru;
                        pi.x = c[p].x + dx[i];
                        pi.y = c[p].y + dy[i];
                        pf.x = c[1].x;
                        pf.y = c[1].y;
                        return;
                    }
                }
        }
    }
}

bool check(int x, int y)
{
    if (x > 0 && x <= n && y > 0 && y <= m)
        return 1;
    return 0;
}

void route()
{
    int I = pi.x, J = pi.y, k = d;
    while(k > 1)
        for ( int i = 0; i < 4; ++i )
            if (check(I+dx[i], J+dy[i]) && r[I+dx[i]][J+dy[i]]+1 == k)
            {
                I = I + dx[i],
                J = J + dy[i],
                --k,
                ans.push_back(next(i));
                break;
            }
}

char next(int o)
{
    if (o == 0)
        return 'S';
    if (o == 1)
        return 'E';
    if (o == 2)
        return 'N';
    return 'W';
}

void write()
{
    freopen ( "alpinist.out", "w", stdout );
    printf ( "%d\n%d %d %d %d\n%d\n", h, pi.x, pi.y, pf.x, pf.y, d-1 );
    for ( unsigned int i = 0; i < ans.size(); ++i )
        printf ( "%c ", ans[i] );
    fclose(stdout);
}
