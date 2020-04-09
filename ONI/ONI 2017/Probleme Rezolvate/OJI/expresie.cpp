#include <fstream>
#include <cstring>
#include <algorithm>
#define MAX 100002

using namespace std;

ifstream fin ("expresie.in");
ofstream fout ("expresie.out");

char ex[MAX];
int st[MAX], r[MAX], d[MAX];
int k, kr, kd;
int x, i, l, j, y, nr, s, sol, sm, mx;

int median(int *a, int st, int dr, int k);

int main()
{
    fin.getline(ex, MAX);
    l = strlen(ex);
    while(i < l)
    {
        if ( ( ex[i] >= '0' && ex[i] <= '9' ) || ex[i] == '-' )
        {
            if ( ex[i] == '-' )
                sm = -1, ++i;
            else sm = 1;
            x = 0;
            while ( ex[i] >= '0' && ex[i] <= '9' && i < l )
                x = x * 10 + ex[i] - '0', ++i;
            st[++k] = sm * x;
            if ( ex[i] == ',' )
                ++nr, ++i;
        }
        if ( ex[i] == '(' )
            ++i, r[++kr] = k + 1;
        if ( ex[i] == '[' )
            ++i, d[++kd] = k + 1;
        if ( ex[i] == ')' )
        {
            x = r[kr];
            s = st[x]; mx = s;
            for ( j = x + 1; j <= k; ++j )
            {
                if ( s + st[j] < st[j] )
                    s = st[j];
                else s += st[j];
                if ( s > mx )
                    mx = s;
            }
            k = x; --kr; st[k] = mx;
            ++i;
        }
        if ( ex[i] == ']' )
        {
            x = d[kd];
            y = median(st, x, k, (k + x) / 2);
            k = x; --kd; st[k] = y;
            ++i;
        }
        if ( ex[i] == ',' )
            ++i, ++nr;
    }
    for ( i = 1, sol = 0; i <= k; ++i )
        sol += st[i];
    fout << nr + 1 << '\n' << sol << '\n';
    return 0;
}

int median(int *a, int st, int dr, int k)
{
    int i, ir, j, l, mid, p;
    l=st; ir=dr;
    while(1)
    {
        if (ir <= l+1)
        {
            if (ir == l+1 && a[ir] < a[l])
                swap(a[l],a[ir]);
            return a[k];
        }
        else
        {
            mid=(l+ir) >> 1;
            swap(a[mid],a[l+1]);
            if (a[l] > a[ir])
                swap(a[l],a[ir]);
            if (a[l+1] > a[ir])
                swap(a[l+1],a[ir]);
            if (a[l] > a[l+1])
                swap(a[l],a[l+1]);
            i = l + 1; j = ir;
            p = a[l+1];
            while(1)
            {
                do i++; while (a[i] < p);
                do j--; while (a[j] > p);
                if (j < i) break;
                    swap(a[i],a[j]);
            }
            a[l+1]=a[j]; a[j]=p;
            if (j >= k) ir=j-1;
            if (j <= k) l=i;
        }
    }
}
