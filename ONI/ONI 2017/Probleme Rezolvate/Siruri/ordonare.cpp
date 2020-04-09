#include <fstream>
#include <string.h>

using namespace std;

int v[32], p(1), w[1001];
char wrd[1001][31], tmp[31];

void read();
void sort_words();
int compare(int y);
void copy_word(int i1, int y);
void write();

int main()
{
    read();
    sort_words();
    write();
    return 0;
}

void read()
{
    freopen ( "ordonare.in", "r", stdin );
    char q;
    for ( int i = 1; i <= 26; ++i )
        scanf ( "%c", &q ), v[int(q-'a'+1)] = i;
    scanf ( "%c", &q ); // read '\n'
    int n(0);
    bool ok(0);
    do
    {
        scanf ( "%c", &q );
        if ( q >= 'a' && q <= 'z' )
            wrd[p][++n] = q, ok = 1;
        else
        {
            if (ok)
                w[p++] = n;
            n = 0;
            ok = 0;
        }
    }while(q != 10);
    fclose(stdin);
}

void sort_words()
{
    bool ok(1);
    int aux;
    while(ok)
    {
        ok = 0;
        for ( int i = 1; i < p; ++i )
            if ( compare(i) < 0 )
                copy_word(1, i),
                copy_word(2, i),
                copy_word(3, i),
                aux = w[i],
                w[i] = w[i+1],
                w[i+1] = aux,
                ok = 1;
    }
}

int compare(int y)
{
    int mn = min( w[y], w[y+1] );
    for ( int i = 1; i <= mn; ++i )
        if ( v[int(wrd[y][i]-'a'+1)] < v[int(wrd[y+1][i]-'a'+1)] )
            return 1;
        else if ( v[int(wrd[y][i]-'a'+1)] > v[int(wrd[y+1][i]-'a'+1)] )
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
            tmp[i] = wrd[y][i];
    else if ( i1 == 2 )
        for ( int i = 1; i <= w[y+1]; ++i )
            wrd[y][i] = wrd[y+1][i];
    else if ( i1 == 3 )
        for ( int i = 1; i <= w[y]; ++i )
            wrd[y+1][i] = tmp[i];
}

void write()
{
    freopen ( "ordonare.out", "w", stdout );
    for ( int i = 2; i <= p; ++i )
    {
        for ( int j = 1; j <= w[i]; ++j )
            printf ( "%c", wrd[i][j] );
        printf ( " " );
    }
    fclose(stdout);
}
