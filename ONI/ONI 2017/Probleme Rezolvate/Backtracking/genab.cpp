#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector <int> v;

int main()
{
    freopen ( "genab.in", "r", stdin );
    freopen ( "genab.out", "w", stdout );
    scanf ( "%d", &n );
    const int y = pow( 2, n ) - 1;
    int m;
    bool ok;
    for ( int i = 0; i <= y; ++i )
    {
        v.clear();
        m = i;
        while (m)
            v.push_back (m % 2), m /= 2;
        for ( int j = v.size(); j < n; ++j )
            v.push_back (0);
        ok = 0;
        for ( int j = 1; j < v.size(); ++j )
            if ( v[j] && v[j-1] )
            {
                ok = 1;
                break;
            }
        if (ok)
            continue;
        for ( int j = v.size() - 1; j >= 0; --j )
            printf ( v[j] ? "b" : "a" );
        printf ( "\n" );
    }
    return 0;
}
