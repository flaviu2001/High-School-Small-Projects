#include <cstdio>
#include <vector>
#define l int(c.size())
#define vf int(qu.size())-1

using namespace std;

vector<char> c, qu;
int test;

void read();
int solve_1();
int solve_2();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen ( "charlie.in", "r", stdin );
    char q;
    scanf ( "%d%c", &test, &q );
    while (!feof(stdin))
    {
        scanf ( "%c", &q );
        if (q != 10)
            c.push_back(q);
    }
    fclose(stdin);
}

int solve_1()
{
    int i(0), j, mx(0);
    while(i < l)
    {
        j = i;
        while (j + 2 < l && c[j] > c[j+1] && c[j+1] < c[j+2])
            j += 2;
        if (j - i >= 2)
        {
            if (j - i + 1 > mx)
                mx = j - i + 1;
            i = j;
        }
        ++i;
    }
    return mx;
}

int solve_2()
{
    int s(0);
    qu.push_back(c[0]);
    qu.push_back(c[1]);
    for ( int i = 2; i < l; ++i )
    {
        while (vf && c[i] > qu[vf] && qu[vf] < qu[vf-1])
            qu.pop_back(),
            s += max(c[i]-'a'+1, qu[vf]-'a'+1);
        qu.push_back(c[i]);
    }
    return s;
}

void write()
{
    freopen ( "charlie.out", "w", stdout );
    if (test == 1)
        printf ( "%d\n", solve_1() );
    else
    {
        int s = solve_2();
        for ( int i = 0; i <= vf; ++i )
            printf ( "%c", qu[i] );
        printf ( "\n%d\n", s );
    }
    fclose(stdout);
}
