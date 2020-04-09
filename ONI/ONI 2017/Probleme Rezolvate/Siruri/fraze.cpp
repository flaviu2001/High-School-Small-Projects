#include <fstream>
#include <vector>

using namespace std;

vector<char> v;
int f[30], r, r_perf, w[101];
char rez[101][260], tmp[260];

void solve();
void sort_phrases();
void copy_phrase(int i1, int y);
int compare(int y);
void write();

int main()
{
    solve();
    sort_phrases();
    write();
    return 0;
}

void solve()
{
    freopen ( "fraze.in", "r", stdin );
    char q;
    int p;
    bool not_perfect;
    while (!feof(stdin))
    {
        for ( int i = 1; i <= 27; ++i )
        f[i] = 0;
        v.clear();
        p = 0;
        not_perfect = 0;
        do
        {
            scanf ( "%c", &q );
            if ( q >= 'A' && q <= 'Z' && !f[int(q-'A'+1)] )
                ++p, ++f[int(q-'A'+1)];
            else if ( q >= 'A' && q <= 'Z' )
                not_perfect = 1;
            else if ( q >= 'a' && q <= 'z' && !f[int(q-'a'+1)] )
                ++p, ++f[int(q-'a'+1)];
            else if ( q >= 'a' && q <= 'z' )
                not_perfect = 1;
            v.push_back(q);
        }while ( q != 10 );
        v.pop_back();
        if ( p == 26 )
        {
            ++r;
            if (!not_perfect)
                ++r_perf;
            for ( unsigned int i = 0; i < v.size(); ++i )
                rez[r][i+1] = v[i];
            w[r] = v.size();
        }
    }
    fclose(stdin);
}

void sort_phrases()
{
    bool ok(1);
    int aux;
    while(ok)
    {
        ok = 0;
        for ( int i = 1; i < r; ++i )
            if ( compare(i) < 0 )
                copy_phrase(1, i),
                copy_phrase(2, i),
                copy_phrase(3, i),
                aux = w[i],
                w[i] = w[i+1],
                w[i+1] = aux,
                ok = 1;
    }
}

void copy_phrase(int i1, int y)
{
    if ( i1 == 1 )
        for ( int i = 1; i <= w[y]; ++i )
            tmp[i] = rez[y][i];
    else if ( i1 == 2 )
        for ( int i = 1; i <= w[y+1]; ++i )
            rez[y][i] = rez[y+1][i];
    else if ( i1 == 3 )
        for ( int i = 1; i <= w[y]; ++i )
            rez[y+1][i] = tmp[i];
}

int compare(int y)
{
    int mn = min( w[y], w[y+1] );
    for ( int i = 1; i <= mn; ++i )
        if ( rez[y][i] < rez[y+1][i] )
            return 1;
        else if ( rez[y][i] > rez[y+1][i] )
            return -1;
    if ( w[y] < w[y+1] )
        return 1;
    if ( w[y] > w[y+1] )
        return -1;
    return 0;
}

void write()
{
    freopen ( "fraze.out", "w", stdout );
    printf ( "%d %d\n", r, r_perf );
    for ( int i = 1; i <= r; ++i )
    {
        for ( int j = 1; j <= w[i]; ++j )
            printf ( "%c", rez[i][j] );
        printf ( "\n" );
    }
    fclose(stdout);
}
