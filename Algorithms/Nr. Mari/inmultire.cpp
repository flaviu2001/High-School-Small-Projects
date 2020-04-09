/*
6 4
932102
1234
*/

#include <cstdio>

using namespace std;

int x[1001], y[1001], v[2005];
int n, m, k;

void read();
void prod();
void write();

int main(){
    read();
    prod();
    write();
    return 0;
}

void read(){
    freopen ("data.in", "r", stdin);
    char q;
    scanf ("%d%d%c", &n, &m, &q);
    for (int i = n; i; --i)
        scanf ("%c", &q),
        x[i] = q - '0';
    scanf ("%c", &q);
    for (int i = m; i; --i)
        scanf ("%c", &q),
        y[i] = q - '0';
    fclose(stdin);
}

void prod(){
    int t = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i+j-1] += x[i] * y[j];
    for (int i = 1; i < n + m; ++i)
        v[i] += t,
        t = v[i] / 10,
        v[i] = v[i] % 10;
    k = n + m - 1;
    if (t)
        v[++k] = t;
}

void write(){
    freopen ("data.out", "w", stdout);
    for (int i = k; i; --i)
        printf ("%d", v[i]);
    fclose(stdout);
}
