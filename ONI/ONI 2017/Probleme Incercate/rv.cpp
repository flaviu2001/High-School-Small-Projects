#include <fstream>
#include <vector> 

using namespace std;

vector<char> v, r;

void read();
void solve();
void elim();
void equal_ends(bool way);
void write();

int main()
{
    read();
    solve();
    write();
    return 0;
}

void read()
{
    freopen ( "rv.in", "r", stdin );
    char q;
    do
    {
        scanf ( "%c", &q );
        v.push_back(q);
    }while(q != 10);
    v.pop_back();
    fclose(stdin);
}

void solve()
{
    while (v.size())
    {
        if ( v[0] > v[v.size()-1] )
            r.push_back(v[0]), elim();
        else r.push_back(v[v.size()-1]), v.pop_back();

        if ( v.size() && v[0] > v[v.size()-1] )
            r.push_back(v[v.size()-1]), v.pop_back();
        else if ( v.size() )
            r.push_back(v[0]), elim();
    }
}

void elim()
{
    for ( unsigned i = 1; i < v.size(); ++i )
        v[i-1] = v[i];
    v.pop_back();
}

void write()
{
    freopen ( "rv.out", "w", stdout );
    for ( unsigned int i = 0; i < r.size(); ++i )
        printf ( "%c", r[i] );
    fclose(stdout);
}
