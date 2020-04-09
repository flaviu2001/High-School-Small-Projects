#include <fstream>
#include <algorithm>

using namespace std;

int v[50002];

int main()
{
    ifstream fin ( "tabara.in" );
    ofstream fout ( "tabara.out" );
    int i, n, s, p, k;
    bool ok = 1;
    fin >> n >> k;
    for ( i = 1; i <= n; ++i )
        fin >> v[i];
    v[n+1] = k;
    sort ( v+1, v+n+2 );
    while ( ok )
    {
        ok = 0;
        s = 0;
        for ( i = 1; i <= n + 1; ++i )
            s += v[i];
        p = s/n;
        for ( i = 1; i <= n + 1; ++i )
            if ( v[i] > p )
                ok = 1, v[i] = p;
    }
    fout << p;
    return 0;
}
