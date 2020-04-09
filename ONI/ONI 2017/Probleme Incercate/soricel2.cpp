#include <fstream>
#include <algorithm>
#define MAX 105

using namespace std;

struct lee
{
    int x, y;
}c[MAX*MAX], pj, pt, sfh[MAX*5], sfh_upd[MAX*5];

int n, m, t, v[MAX][MAX], r[MAX][MAX], dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void read();
void lee_mouse();
bool check(int i1, int j1);
void lee_cat();
bool cmp(lee a, lee b);
void write();

int main()
{
    read();
    lee_mouse();
    lee_cat();
    write();
    return 0;
}

void read()
{
    freopen ( "soricel2.in", "r", stdin );
    int I, J, T;
    scanf ( "%d%d%d%d%d%d%d", &n, &m, &pj.x, &pj.y, &pt.x, &pt.y, &t );
    v[pj.x][pj.y] = 1;
    r[pt.x][pt.y] = 1;
    for ( int i = 1; i <= t; ++i )
        scanf ( "%d%d", &I, &J ), v[I][J] = -2, r[I][J] = -2, sfh[i].x = I, sfh[i].y = J;
    scanf ( "%d", &T );
    for ( int i = 1; i <= T; ++i )
        scanf ( "%d%d", &I, &J ), v[I][J] = -1, r[I][J] = -1;
    fclose(stdin);
}

void lee_mouse()
{
    int p(0), f(1);
    c[1] = pj;
    while ( p != f )
    {
        ++p;
        for ( int i = 0; i <= 7; ++i )
            if ( check(c[p].x + dx[i], c[p].y + dy[i]) && v[c[p].x + dx[i]][c[p].y + dy[i]] == -2 )
                v[c[p].x + dx[i]][c[p].y + dy[i]] = v[c[p].x][c[p].y] + 1;
            else if ( check(c[p].x + dx[i], c[p].y + dy[i]) && v[c[p].x + dx[i]][c[p].y + dy[i]] == 0 )
                v[c[p].x + dx[i]][c[p].y + dy[i]] = v[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
    }
}

bool check(int i1, int j1)
{
    if ( i1 > n || i1 < 1 || j1 > m || j1 < 1 )
        return 0;
    return 1;
}

void lee_cat()
{
    int p(0), f(1);
    c[1] = pt;
    while ( p != f )
    {
        ++p;
        for ( int i = 0; i <= 7; ++i )
            if ( check(c[p].x + dx[i], c[p].y + dy[i]) && r[c[p].x + dx[i]][c[p].y + dy[i]] == -2 )
                r[c[p].x + dx[i]][c[p].y + dy[i]] = r[c[p].x][c[p].y] + 1;
            else if ( check(c[p].x + dx[i], c[p].y + dy[i]) && r[c[p].x + dx[i]][c[p].y + dy[i]] == 0 )
                r[c[p].x + dx[i]][c[p].y + dy[i]] = r[c[p].x][c[p].y] + 1,
                c[++f].x = c[p].x + dx[i],
                c[f].y = c[p].y + dy[i];
    }
}

bool cmp(lee a, lee b)
{
    return ( a.x < b.x ) || ( a.x == b.x && a.y < b.y );
}

void write()
{
    freopen ( "soricel2.out", "w", stdout );
    int p(0);
    for ( int i = 1; i <= t; ++i )
        if ( 2 * ( v[sfh[i].x][sfh[i].y] ) <= r[sfh[i].x][sfh[i].y] )
            sfh_upd[++p] = sfh[i];
    sort ( sfh_upd + 1, sfh_upd + p + 1, cmp );
    printf ( "%d\n", p );
    for ( int i = 1; i <= p; ++i )
        printf ( "%d %d\n", sfh_upd[i].x, sfh_upd[i].y );
    fclose(stdout);
}
