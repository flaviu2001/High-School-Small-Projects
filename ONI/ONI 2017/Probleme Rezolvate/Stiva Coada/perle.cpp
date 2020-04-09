#include <cstdio>
#define MAX 10005

using namespace std;

int st[2][MAX];

int main()
{
    freopen ("perle.in", "r", stdin);
    freopen ("perle.out", "w", stdout);
    int tests, l, v, niv[2], val[2];
    scanf ("%d", &tests);
    while(tests--)
    {
        scanf ("%d", &l);
        if (l == 1)
        {
            scanf ("%d", &v);
            printf ("1\n");
            continue;
        }
        val[0] = val[1] = niv[0] = niv[1] = 1;
        st[0][0] = 5;
        st[1][0] = 6;
        while(l--)
        {
            scanf ("%d", &v);
            for (int i = 0; i <= 1; ++i)
            {
                if (val[i])
                {
                    if (st[i][niv[i]-1] < 4)
                    {
                        val[i] = (st[i][--niv[i]] == v);
                        continue;
                    }
                    if (st[i][niv[i]-1] == 4)
                    {
                        --niv[i];
                        continue;
                    }
                    if (st[i][niv[i]-1] == 5)
                    {
                        if (v == 3)
                            val[i] = 0;
                        else if (v == 1)
                            --niv[i],
                            st[i][niv[i]++] = 6,
                            st[i][niv[i]++] = 4,
                            st[i][niv[i]++] = 3,
                            st[i][niv[i]++] = 4;
                        continue;
                    }
                    if (v == 2)
                        --niv[i];
                    else if (v == 1)
                        --niv[i],
                        st[i][niv[i]++] = 4,
                        st[i][niv[i]++] = 2;
                    else if (v == 3)
                        --niv[i],
                        st[i][niv[i]++] = 6,
                        st[i][niv[i]++] = 5;
                }
                if (!niv[i] && l)
                    val[i] = 0;
            }
        }
        printf ("%d\n", ((!niv[0] && val[0]) || (!niv[1] && val[1])));
    }
    return 0;
}