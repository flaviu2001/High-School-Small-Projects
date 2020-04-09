#include <fstream>
#define MAX  210

using namespace std;

char c[MAX];
int p;

void read();
void rid_of();
bool check(int i);
int words();
void write();

int main()
{
    read();
    rid_of();
    write();
    return 0;
}

void read()
{
    freopen ( "nrcuv.in", "r", stdin );
    do
    {
        scanf ( "%c", &c[++p] );
    }while ( c[p] != 10 );
    --p;
    fclose(stdin);
}

void rid_of()
{
    for ( int i = 1; i <= p; ++i )
        if ( c[i] == '-' && check(i-1) && check(i+1) )
            c[i] = 'a';
        else if ( c[i] == '-' )
            c[i] = ' ';
}

bool check(int i)
{
    if ( ( c[i] >= 'a' && c[i] <= 'z' ) || ( c[i] >= 'A' && c[i] <= 'Z' ) )
        return 1;
    return 0;
}

int words()
{
    int wordz(0);
    for ( int i = 2; i <= p+1; ++i )
        if ( ( c[i] == ' ' || c[i] == '.' || c[i] == ',' || c[i] == '!' || c[i] == '?' || c[i] == 10 ) && check(i-1) )
            ++wordz;
    return wordz;
}

void write()
{
    freopen ( "nrcuv.out", "w", stdout );
    printf ( "%d\n", words() );
    fclose(stdout);
}
