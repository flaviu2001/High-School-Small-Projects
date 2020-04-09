#include <cstdio>
#include <vector>

#define ea a.size()-1
#define eb b.size()-1
#define ec c.size()-1

#define sa a.size()
#define sb b.size()
#define sc c.size()

struct black_digger_nick
{
    int x1, x2 ,x3;
}x, x0;

using namespace std;

vector<int> a, b, c;

int main()
{
    freopen ( "ecp.in", "r", stdin );
    freopen ( "ecp.out", "w", stdout );
    char q;
    int p(0), p1(0), p2(0), p3(0);
    do
    {
        ++p;
        scanf ( "%c", &q );
        if (q == '(')
            a.push_back(p);
        else if (q == '[')
            b.push_back(p);
        else if (q == '{')
            c.push_back(p);
        else if (q == ')')
        {
            if (p - a[ea] == 1)
            {
                ++p1;
                a.pop_back();
                if (sa || sb || sc)
                    ++x.x1;
                else x = x0;

            }
            else
            {
                p1 += 2;
                a.pop_back();
                if (!(sa || sb || sc))
                    x = x0;
            }
        }
        else if (q == ']')
        {
            if (p - b[eb] == 1)
            {
                ++p2;
                b.pop_back();
                if (sa || sb || sc)
                    ++x.x2;
                else x = x0;

            }
            else
            {
                p2 += 3;
                b.pop_back();
                if (!(sa || sb || sc))
                    x = x0;
            }
        }
        else if (q == '}')
        {
            if (p - c[ec] == 1)
            {
                ++p3;
                c.pop_back();
                if (sa || sb || sc)
                    ++x.x3;
                else x = x0;

            }
            else
            {
                p3 += 5;
                c.pop_back();
                if (!(sa || sb || sc))
                    x = x0;
            }
        }
    }while(q != 10);
    printf ( "%d %d %d\n", p1, p2, p3 );
    fclose(stdin);
    fclose(stdout);
    return 0;
}
