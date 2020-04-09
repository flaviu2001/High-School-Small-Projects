#include <cstdio>
#include <utility>
#define MAX 110

using namespace std;

char c[MAX][MAX], tmp[MAX];
int p(1), w[MAX];

void read();
void sort_parts();
bool compare(int y);
void copy_word(int y);
void write();

int main()
{
    read();
    sort_parts();
    write();
    return 0;
}

void read()
{
    freopen ( "astre.in", "r", stdin );
    int k(0);
    while(!feof(stdin))
    {
        scanf ( "%c", &c[p][++k] );
        if ( c[p][k] == 10 )
            w[p++] = k-1,
            k = 0;
    }
    fclose(stdin);
}

void sort_parts()
{
    bool ok(1);
    while(ok)
    {
        ok = 0;
        for ( int i = 1; i < p; ++i )
            if (compare(i))
                copy_word(i),
                swap(w[i], w[i+1]),
                ok = 1;
    }
}

bool compare(int y)
{
    char w1[MAX*2], w2[MAX*2];
    int k = w[y] + w[y+1];
    for ( int i = 1; i <= w[y]; ++i )
        w1[i] = c[y][i];
    for ( int i = w[y] + 1; i <= w[y] + w[y+1]; ++i )
        w1[i] = c[y+1][i-w[y]];
    for ( int i = 1; i <= w[y+1]; ++i )
        w2[i] = c[y+1][i];
    for ( int i = w[y+1] + 1; i <= w[y] + w[y+1]; ++i )
        w2[i] = c[y][i-w[y+1]];
    for ( int i = 1; i <= k; ++i )
        if ( w1[i] < w2[i] )
            return 1;
        else if ( w1[i] > w2[i] )
            return 0;
    return 0;
}

void copy_word(int y)
{
    for ( int i = 1; i <= w[y]; ++i )
        tmp[i] = c[y][i];
    for ( int i = 1; i <= w[y+1]; ++i )
        c[y][i] = c[y+1][i];
    for ( int i = 1; i <= w[y]; ++i )
        c[y+1][i] = tmp[i];
}

void write()
{
    freopen ( "astre.out", "w", stdout );
    for ( int i = 1; i <= p; ++i )
        for ( int j = 1; j <= w[i]; ++j )
            printf ( "%c", c[i][j] );
    fclose(stdout);
}
