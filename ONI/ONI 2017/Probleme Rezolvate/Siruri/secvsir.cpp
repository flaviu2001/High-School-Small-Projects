#include <fstream>
#include <vector>

using namespace std;

vector<char> v;

bool ok(int y);

int main()
{
    freopen ( "secvsir.in", "r", stdin );
    freopen ( "secvsir.out", "w", stdout );
    int n;
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i )
    {
        if (!ok(i))
            continue;
        if ( i < 10 )
            v.push_back(char('0'+i));
        else if ( i < 100 )
            v.push_back(char('0'+(i/10))),
            v.push_back(char('0'+(i%10)));
        else
            v.push_back(char('0'+(i/100))),
            v.push_back(char('0'+((i/10)%10))),
            v.push_back(char('0'+(i%10)));
    }
    for ( unsigned int i = 0; i < v.size(); ++i )
        printf ( "%c", v[i] );
    fclose(stdin);
    fclose(stdout);
    return 0;
}

bool ok(int y)
{
    int x, n;
    if ( y < 10 )
        x = 1;
    else if ( y < 100 )
        x = 2;
    else x = 3;
    for ( unsigned int i = 0; i < v.size()-x+1; ++i )
    {
        n = 0;
        for ( unsigned int j = i; j < i + x; ++j )
            n = n * 10 + int(v[j]-'0');
        if ( n == y )
            return 0;
    }
    return 1;
}
