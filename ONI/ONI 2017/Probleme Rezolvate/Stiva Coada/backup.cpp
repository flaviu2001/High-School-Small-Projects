#include <cstdio>
#define MAX 1005

using namespace std;

struct quu
{
    int x, y;
} q[MAX*MAX];

int n, m, h, vf, s;
int v[MAX][MAX], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool is[MAX][MAX];

void read();
void add_queue();
bool check(int, int);
void do_queue();
void write();

int main()
{
    read();
    add_queue();
    do_queue();
    write();
    return 0;
}

void read()
{
    freopen ( "tsunami.in", "r", stdin );
    scanf ( "%d%d%d", &n, &m, &h );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            scanf ( "%d", &v[i][j] );
    fclose(stdin);
}

void add_queue()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( v[i][j] && check(i, j) && v[i][j] < h )
                ++s,
                q[++vf].x = i,
                q[vf].y = j,
                is[i][j] = 1;
}

bool check(int x, int y)
{
    for ( int i = 0; i <= 3; ++i )
        if (x+dx[i] > 0 && y+dy[i] > 0 && x+dx[i] <= n && y+dy[i] <= m && !v[x+dx[i]][y+dy[i]])
            return 1;
    return 0;
}

void do_queue()
{
    for ( int i = 1; i <= vf; ++i )
        for ( int j = 0; j < 4; ++j )
            if (q[i].x + dx[j] <= n && q[i].x + dx[j] > 0 && q[i].y + dy[j] <= m && q[i].y + dy[j] > 0)
                if (v[q[i].x+dx[j]][q[i].y+dy[j]] && !is[q[i].x+dx[j]][q[i].y+dy[j]] && v[q[i].x+dx[j]][q[i].y+dy[j]] < h)
                    ++s,
                    is[q[i].x+dx[j]][q[i].y+dy[j]] = 1,
                    q[++vf].x = q[i].x+dx[j],
                    q[vf].y = q[i].y+dy[j];
}

void write()
{
    freopen ( "tsunami.out", "w", stdout );
    printf ( "%d\n", s );
    fclose(stdout);
}
