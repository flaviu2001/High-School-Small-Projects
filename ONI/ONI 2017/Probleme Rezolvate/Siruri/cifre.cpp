#include <fstream>
#include <vector>

using namespace std;

int k;
vector<int> v, r;

void read();
void build_next();
int digits(int x);
void write();

int main()
{
    read();
    for ( int i = 1; i <= k; ++i )
        build_next();
    write();
    return 0;
}

void read()
{
    freopen ( "cifre.in", "r", stdin );
    char c;
    do
    {
        scanf ( "%c", &c );
        if ( c != 10 )
            v.push_back(int(c-'0'));
    }while(c != 10);
    scanf ( "%d", &k );
    fclose(stdin);
}

void build_next()
{
    int m = v[0], p(0), x, in(-1);
    r.clear();
    for ( size_t i = 0; i < v.size(); ++i )
        if ( m == v[i] )
            ++p;
        else
        {
            x = digits(p);
            if ( x == 3 )
                r.push_back (p/100),
                r.push_back ((p/10)%10),
                r.push_back (p%10);
            else if ( x == 2 )
                r.push_back(p/10),
                r.push_back(p%10);
            else r.push_back(p);
            r.push_back(m);
            m = v[i], p = 1;
        }
    x = digits(p);
    if ( x == 3 )
        r.push_back (p/100),
        r.push_back ((p/10)%10),
        r.push_back (p%10);
    else if ( x == 2 )
        r.push_back(p/10),
        r.push_back(p%10);
    else r.push_back(p);
    r.push_back(m);
    v.clear();
    for ( size_t i = 0; i < r.size(); ++i )
        v.push_back (r[i]);
}

int digits(int x)
{
    int o = 0;
    while (x)
        ++o, x /= 10;
    return o;
}

void write()
{
    freopen ( "cifre.out", "w", stdout );
    for ( size_t i = 0; i < v.size(); ++i )
        printf ( "%d", v[i] );
    fclose(stdout);
}
