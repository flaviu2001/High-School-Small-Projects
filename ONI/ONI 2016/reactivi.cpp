#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

struct reactivi
{
    int a, b;
}v[8001], r[8001];

bool cmp ( reactivi x, reactivi y )
{
    return ( x.b < y.b ) || ( x.b == y.b && x.a > y.a );
}

int main()
{
    ifstream fin ("reactivi.in");
    ofstream fout ("reactivi.out");
    int n, k = 0, i, m1, m2, j;
    bool ok;
    fin >> n;
    for( i = 1; i <= n; ++i )
        fin >> v[i].a >> v[i].b;
    sort ( v + 1, v + n + 1, cmp );
    for ( j = 1; j <= n; ++j )
    {
        ok = 0;
        for( i = 1; i <= k && !ok; ++i )
        {
            m1 = ( r[i].a + v[j].a + abs ( r[i].a - v[j].a ) ) / 2;
            m2 = ( r[i].b + v[j].b - abs ( r[i].b - v[j].b ) ) / 2;
            if ( m2 >= m1 ) ok = 1, r[i].a = m1, r[i].b = m2;
        }
        if ( !ok )
            r[++k].a = v[j].a, r[k].b = v[j].b;
    }
    fout << k;
    return 0;
}