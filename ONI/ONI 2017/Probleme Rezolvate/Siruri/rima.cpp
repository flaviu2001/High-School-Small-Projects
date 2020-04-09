#include <fstream>
#include <vector>

using namespace std;

vector<char> v, w, a, b, c, d;

bool not_vowel(char x)
{
    if ( x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' )
        return 0;
    return 1;
}

bool compare(int a1, int a2)
{
    if ( a1 == 1 )
        for ( size_t i = 0; i <= a.size() - 1; ++i )
            v.push_back(a[i]);
    else if ( a1 == 2 )
        for ( size_t i = 0; i <= b.size() - 1; ++i )
            v.push_back(b[i]);
    else if ( a1 == 3 )
        for ( size_t i = 0; i <= c.size() - 1; ++i )
            v.push_back(c[i]);
    else //if ( a1 == 4 )
        for ( size_t i = 0; i <= d.size() - 1; ++i )
            v.push_back(d[i]);

    if ( a2 == 1 )
        for ( size_t i = 0; i <= a.size() - 1; ++i )
            w.push_back(a[i]);
    else if ( a2 == 2 )
        for ( size_t i = 0; i <= b.size() - 1; ++i )
            w.push_back(b[i]);
    else if ( a2 == 3 )
        for ( size_t i = 0; i <= c.size() - 1; ++i )
            w.push_back(c[i]);
    else //if ( a2 == 4 )
        for ( size_t i = 0; i <= d.size() - 1; ++i )
            w.push_back(d[i]);

    if ( v.size() != w.size() )
    {
        v.clear();
        w.clear();
        return 0;
    }

    for ( int i = 0; i <= v.size() - 1; ++i )
        if ( v[i] != w[i] )
        {
            v.clear();
            w.clear();
            return 0;
        }

    v.clear();
    w.clear();
    return 1;
}

int main()
{
    freopen ( "rima.in", "r", stdin );
    freopen ( "rima.out", "w", stdout );
    int n;
    char q;
    scanf ( "%d%c", &n, &q );
    while(n--)
    {
        for ( int j = 1; j <= 4; ++j )
        {
            do
            {
                scanf ( "%c", &q );
                if ( q >= 'A' && q <= 'Z' )
                    q += 32;
                v.push_back(q);
            }while(q != 10);
            v.pop_back();
            for ( int i = v.size()-1; not_vowel(v[i+1]) && v[i] != ' ' && i >= 0; --i )
                w.push_back(v[i]);
            if ( j == 1 )
                for ( int i = w.size() - 1; i >= 0; --i )
                    a.push_back(w[i]);
            else if ( j == 2 )
                for ( int i = w.size() - 1; i >= 0; --i )
                    b.push_back(w[i]);
            else if ( j == 3 )
                for ( int i = w.size() - 1; i >= 0; --i )
                    c.push_back(w[i]);
            else //if( j == 4 )
                for ( int i = w.size() - 1; i >= 0; --i )
                    d.push_back(w[i]);
            v.clear();
            w.clear();
        }

        if ( compare(1, 2) && compare(2, 3) && compare(3, 4) )
            printf ( "perfecta\n" );
        else if ( compare(1, 3) && compare(2, 4) )
            printf ( "incrucisata\n" );
        else if ( compare(1, 4) && compare(2, 3) )
            printf ( "imbricata\n" );
        else if ( compare(1, 2) && compare(3, 4) )
            printf ( "uniforma\n" );
        else
            printf ( "alba\n" );

        a.clear();
        b.clear();
        c.clear();
        d.clear();
    }
    return 0;
}
