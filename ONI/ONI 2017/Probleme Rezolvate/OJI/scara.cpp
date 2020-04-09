#include <cstdio>
#define MAX 101

using namespace std;

int h, n, M, p, v[MAX], vmin[MAX], u[MAX], htot;
double f[MAX], fmin;

void read();
void gen(int k);
void write();
double effort();

int main()
{
    read();
    gen(1);
    write();
    return 0;
}

void read()
{
    freopen ( "scara.in", "r", stdin );
    scanf ( "%d%d%d%d", &h, &n, &M, &p );
    fmin = (double) h * n + 1;
    fclose(stdin);
}

void gen(int k)
{
    double x;
    if ( k == n + 1 )
    {
        if ( htot == h )
        {
            x = effort();
            if ( x < fmin && fmin-x > 0.001 )
            {
                fmin = x;
                for ( int i = 1; i <= n; ++i )
                    vmin[i] = v[i];
            }
        }
    }
    else for ( int i = 1; i <= h && htot + i <= h && i <= M; ++i )
            if(!u[i])
            {
                v[k] = i;
                htot += i;
                u[i] = 1;
                gen(k+1);
                u[i] = 0;
                htot -= i;
            }
}

double effort()
{
    double x, sum;
    for ( int k = 1; k <= n; ++k )
    {
        x = v[k] + f[k-1];
        sum = v[k];
        for ( int j = 2; k - j >= 0; ++j )
        {
            sum += v[k-j+1];
            if ( sum > M )
                break;
            if ( sum / j + p + f[k-j] < x )
                x = sum / j + f[k-j] + p;
        }
        f[k] = x;
    }
    return f[n];
}

void write()
{
    freopen ( "scara.out", "w", stdout );
    if ( fmin == (int) fmin )
        printf ( "%d\n", (int)fmin );
    else
        printf ( "%f\n", fmin );
    for ( int i = 1; i <= n; ++i )
        printf ( "%d ", vmin[i] );
    printf ( "\n" );
    fclose(stdout);
}
