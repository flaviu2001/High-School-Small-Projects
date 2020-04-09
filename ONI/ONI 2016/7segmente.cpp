#include <fstream>
#include <vector>

#define VI vector<int>
#define PB push_back

using namespace std;

unsigned long long n;
int p, pw[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
VI v, r;

void read()
{
    ifstream fin ( "7segmente.in" );
    fin >> n >> p;
    fin.close();
}

int many_on( unsigned long long int x )
{
    int s = 0;
    while (x)
        s += pw[x%10], x /= 10;
    return s;
}

void prepare()
{
    unsigned long long y = n, o = 0, i = 0;
    v.PB(0), r.PB(0);
    while (y)
        o = o * 10 + y % 10, y /= 10, ++i;
    v[0] = i;
    while (o)
        v.PB(o % 10), o /= 10;
    unsigned int f = i;
    if ( p / 2 < f )
        f = p / 2;
    p -= 2 * f;
    for ( int i = 1; i <= f; ++i )
        r.PB(1);
    r[0] = f;
}

void create()
{
    int c = 1, dm, dig, dM, i;
    int q;
    bool e = 1;
    while ( p > 0 && c <= r[0] )
    {
        dm = 10, dig = 1, dM = 0;
        for ( i = 2; i <= 9; ++i )
        {
            q = i - v[c];
            if ( q < 0 )
                q = -q;
            if ( r[0] == v[0] && e )
                if ( i <= v[c] && q <= dm && p - pw[i] + pw[1] >= 0 )
                    dig = i, dm = q;
            if ( r[0] < v[0] || !e )
                if ( i >= dM && p - pw[i] + pw[1] >= 0 )
                    dig = i, dM = i;
        }
        if ( v[c] - dig != 0 )
            e = 0;
        p += pw[1] - pw[dig], r[c++] = dig;
    }
}

void write()
{
    ofstream fout ( "7segmente.out" );
    fout << many_on(n) << " ";
    for ( int i = 1; i <= r[0]; ++i )
        fout << r[i];
    fout.close();
}

int main()
{
    read();
    prepare();
    create();
    write();
    return 0;
}
