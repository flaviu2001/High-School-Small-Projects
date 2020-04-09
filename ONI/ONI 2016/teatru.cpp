#include <fstream>
#include <algorithm>
#define MAX 55001

using namespace std;

int n, c, r[93], in, minn(0);
char v[MAX];

void read()
{
    freopen ( "teatru.in", "r", stdin );
    scanf ( "%d%d%c", &n, &c, &v[0] );
    for ( int i = 0; i < n; ++i )
        scanf ( "%c", &v[i] );
    fclose(stdin);
}

void find_n()
{
    int i(0), j(0), nr(0);
    ++r[v[0]], ++nr;
    do
    {
        while ( nr <= c && j < n )
        {
            if ( ++j >= n )
                break;
            if ( !r[v[j]] )
                ++r[v[j]], ++nr;
            else ++r[v[j]];
        }
        if ( j - i > minn )
            minn = j - i, in = i;
        while ( nr > c )
        {
            --r[v[i]];
            if ( !r[v[i]] )
                --nr;
            ++i;
        }
    }while ( i < n && j < n );
}

void write()
{
    freopen ( "teatru.out", "w", stdout );
    printf ( "%d\n", minn );
    for ( int i = in; i < in + minn; ++i )
        printf ( "%c", v[i] );
    fclose(stdout);
}

int main()
{
    read();
    find_n();
    write();
    return 0;
}
