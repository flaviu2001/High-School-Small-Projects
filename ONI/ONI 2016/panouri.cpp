#include <fstream>

#define MAX 1005
#define NMAX 15005

using namespace std;

struct fuck_this_naming_struct_thing
{
    bool x;
    int y;
}v[MAX];

int n, t, r[NMAX];

void read()
{
    int q;
    freopen ( "panouri.in", "r", stdin );
    scanf ( "%d%d", &n, &t );
    for ( int i = 1; i <= n; ++i )
        scanf ( "%d", &q ), r[i] = q;
    for ( int i = 1; i <= t; ++i )
        scanf ( "%d", &q ), v[q].x = 1;
    fclose(stdin);
}

int seek()
{
    int i, j, s(1), f(1), best(15001), nr(0);
    if ( v[r[1]].x )
        v[r[1]].y = 1, nr = 1;
    while ( f < n && nr < t )
        if ( v[r[++f]].x )
        {
            if ( !v[r[f]].y )
                ++nr;
            ++v[r[f]].y;
        }
    while ( !v[r[s]].x || ( v[r[s]].x && v[r[s]].y > 1 ) )
        --v[r[s++]].y;
    if ( best > f - s )
        best = f - s;
    for ( ++f; f <= n; ++f )
    {
        if ( v[r[f]].x )
            ++v[r[f]].y;
        while ( !v[r[s]].x || ( v[r[s]].x && v[r[s]].y > 1 ) )
            --v[r[s++]].y;
        if ( best > f - s )
            best = f - s;
    }
    return best;
}

void write()
{
    int m = seek();
    freopen ( "panouri.out", "w", stdout );
    printf ( "%d\n", m );
    fclose(stdout);
}

int main()
{
    read();
    write();
    return 0;
}
