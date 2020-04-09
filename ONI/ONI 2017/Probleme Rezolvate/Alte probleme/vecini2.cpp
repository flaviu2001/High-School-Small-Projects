#include <cstdio>
#include <algorithm>

using namespace std;

int v[30], v1[30], v2[30], v3[30], n, a[5005];
int b1[5005], b2[5005];
bool isB1, isB2;

void read();
void solve();

int main()
{
    read();
    solve();
    return 0;
}

void read()
{
    freopen("vecini2.in", "r", stdin);
    char q;
    scanf ("%d%c", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf ("%c", &q),
        a[i] = q-'a';
    scanf ("%c", &q); //read '\n'
    for (int i = 1; i <= n; ++i)
        scanf ("%c", &q),
        ++v[q-'a'],
        ++v1[q-'a'],
        ++v2[q-'a'],
        ++v3[q-'a'];
    fclose(stdin);
}

void solve()
{
    freopen ("vecini2.out", "w", stdout);
    int k(0), bf(0);
    for (int i = 1; i <= n; ++i)
    {
        while(!v1[k])
            ++k;
        if (k > a[i])
        {
            isB1 = 1;
            break;
        }
        else if (k < a[i])
            break;
        --v1[k];
    }
    k = 25;
    for (int i = 1; i <= n; ++i)
    {
        while(!v2[k])
            --k;
        if (k < a[i])
        {
            isB2 = 1;
            break;
        }
        else if (k > a[i])
            break;
        --v2[k];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (v[a[i]])
        {
            b1[++bf] = a[i];
            --v[a[i]];
        }
        else break;
    }
    if (bf != n)
    {
        k = a[bf+1]-1;
        while(!v[k])
            --k;
        b1[++bf] = k;
        --v[k];
        for (int i = 25; i >= 0; --i)
            while (v[i])
                b1[++bf] = i,
                --v[i];
    }
    if (!isB1 && !isB2)
    {
        for (int i = 1; i <= n; ++i)
            printf ("%c", b1[i]+'a');
        printf ("\n");

        next_permutation(b1+1, b1+n+1);
        for (int i = 1; i <= n; ++i)
            printf ("%c", b1[i]+'a');
        printf ("\n");
    }
    else if (isB1)
    {
        printf ("0\n");
        for (int i = 0; i < 26; ++i)
            while(v3[i])
                printf ("%c", 'a'+i),
                --v3[i];
    }
    else if (isB2)
    {
        printf ("0\n");
        for (int i = 26; i >= 0; --i)
            while(v3[i])
                printf ("%c", 'a'+i),
                --v3[i];
    }
    fclose(stdout);
}
