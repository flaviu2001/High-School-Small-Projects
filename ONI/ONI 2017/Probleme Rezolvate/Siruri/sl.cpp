#include <fstream>
#include <vector>

#define MAX 1010

using namespace std;

int instruction[MAX], var[MAX], n, registr;
vector <int> v;

void read();
void sim();
void write();

int main()
{
    read();
    sim();
    write();
    return 0;
}

void read()
{
    freopen ( "sl.in", "r", stdin );
    char c, q;
    scanf ( "%d%c", &n, &c );
    for ( int u = 0; u < n; ++u )
    {
        scanf ( "%c%c", &c, &q );
        if ( c == 'P' && q == 'U' )
            instruction[u] = 1;
        else if ( c == 'S' )
            instruction[u] = 2;
        else if ( c == 'L' )
            instruction[u] = 3;
        else if ( c == 'P' ) // && q == 'L' )
            instruction[u] = 4;
        else if ( c == 'T' )
            instruction[u] = 5;
        else if ( c == 'I' )
            instruction[u] = 6;
        else // if ( c == 'D' )
            instruction[u] = 7;
        do
        {
            scanf ( "%c", &c );
        }while( c >= 'A' && c <= 'Z' );
        if ( instruction[u] == 1 || instruction[u] == 6 )
            scanf ( "%d%c", &var[u], &c );
    }
    fclose(stdin);
}

void sim()
{
    for ( int i = 0; i < n; ++i )
    {
        if ( instruction[i] == 1 )
            v.push_back(var[i]);
        else if ( instruction[i] == 2 )
            registr = v.back(), v.pop_back();
        else if ( instruction[i] == 3 )
            v.push_back(registr);
        else if ( instruction[i] == 4 )
            v[v.size()-2] += v.back(), v.pop_back();
        else if ( instruction[i] == 5 )
            v[v.size()-2] *= v.back(), v.pop_back();
        else if ( instruction[i] == 6 && !v.back() )
            i = var[i]-1;
        else if ( instruction[i] == 7 )
            break;
    }
}

void write()
{
    freopen ( "sl.out", "w", stdout );
    printf ( "%d\n", v.back() );
    fclose(stdout);
}
