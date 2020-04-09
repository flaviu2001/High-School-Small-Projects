#include <fstream>
#include <vector>

using namespace std;

vector<char> v;
int c[30];
bool w[30];
int p(1), k;

void read_prepare();
int next_char();
void write();

int main()
{
    read_prepare();
    write();
    return 0;
}

void read_prepare()
{
    freopen (  "mesaj.in", "r", stdin );
    char q;
    do
    {
        scanf ( "%c", &q );
        if ( q != 10 )
            w[int(q-'A'+1)] = 1;
        v.push_back(q);
    }while(q != 10);
    v.pop_back();
    scanf ( "%d%c", &k, &q );
    for ( unsigned int i = 0; i < v.size(); ++i )
        c[int(v[i]-'A'+1)] = k + i;
    for ( int i = k + v.size(); i <= 26; ++i )
        c[next_char()] = i, ++p;
    for ( int i = 1; i < k; ++i )
        c[next_char()] = i, ++p;
}

int next_char()
{
    for ( ; w[p] ; ++p );
    return p;
}

void write()
{
    freopen ( "mesaj.out", "w", stdout );
    char q;
    while ( !feof(stdin) )
    {
        scanf ( "%c", &q );
        if ( q == ' ' )
            printf ( " " );
        else if ( q != 10 && !feof(stdin) )
            printf ( "%c", char(c[int(q-'A'+1)]+'A'-1));
        else if ( !feof(stdin) ) printf ( "\n" );
    }
    fclose(stdin);
    fclose(stdout);
}