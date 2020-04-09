#include <fstream>
#include <vector>

using namespace std;

vector<char> c;
char lst[1005][25], tmp[25];
int p, w[1005], v[1005];

void read();
int is_equal(int y);
void sort_list();
int compare(int y);
void copy_word(int i1, int y);
void write();

int main()
{
    read();
    sort_list();
    write();
    return 0;
}

void read()
{
    freopen ( "bacan.in", "r", stdin );
    int n, k;
    bool ok;
    char q;
    scanf ( "%d%c", &n, &q );
    while(n--)
    {
        c.clear();
        do
        {
            scanf ( "%c", &q );
            c.push_back(q);
        }while(q != '*');
        scanf ( "%d%c", &k, &q );
        ok = 0;
        for ( int i = 1; i <= p; ++i )
            if (is_equal(i))
            {
                ok = 1;
                v[i] += k;
                break;
            }
        if (!ok)
        {
            ++p;
            for ( unsigned int i = 1; i <= c.size(); ++i )
                lst[p][i] = c[i-1];
            w[p] = c.size();
            v[p] = k;
        }
    }
}

int is_equal(int y)
{
    if ( c.size() != unsigned(w[y]) )
        return 0;
    for ( int i = 1; i <= w[y]; ++i )
        if ( c[i-1] != lst[y][i] )
            return 0;
    return 1;
}

void sort_list()
{
    bool ok(1);
    while(ok)
    {
        ok = 0;
        for ( int i = 1; i < p; ++i )
            if ( compare(i) < 0 )
                copy_word(1, i),
                copy_word(2, i),
                copy_word(3, i),
                swap(w[i], w[i+1]),
                swap(v[i], v[i+1]),
                ok = 1;
    }
}

int compare(int y)
{
    int mn = min( w[y], w[y+1] );
    for ( int i = 1; i <= mn; ++i )
        if ( lst[y][i] < lst[y+1][i] )
            return 1;
        else if ( lst[y][i] > lst[y+1][i] )
            return -1;
    if ( w[y] < w[y+1] )
        return 1;
    if ( w[y] > w[y+1] )
        return -1;
    return 0;
}

void copy_word(int i1, int y)
{
    if ( i1 == 1 )
        for ( int i = 1; i <= w[y]; ++i )
            tmp[i] = lst[y][i];
    else if ( i1 == 2 )
        for ( int i = 1; i <= w[y+1]; ++i )
            lst[y][i] = lst[y+1][i];
    else if ( i1 == 3 )
        for ( int i = 1; i <= w[y]; ++i )
            lst[y+1][i] = tmp[i];
}

void write()
{
    freopen ( "bacan.out", "w", stdout );
    printf ( "%d\n", p );
    for ( int i = 1; i <= p; ++i )
    {
        for ( int j = 1; j <= w[i]; ++j )
            printf ( "%c", lst[i][j] );
        printf ( " %d\n", v[i] );
    }
    fclose(stdout);
}
