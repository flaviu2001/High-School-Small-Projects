/*
6 4
932102
1234
*/

#include <cstdio>
#include <vector>

using namespace std;

int x[10001], y[10001], v[10001];
int n, m, k;

void read();
void sum();
void write();

int main(){
    read();
    sum();
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

void sum(){
    int t = 0, mn = n;
    if (m < mn)
        mn = m;
    for (int i = 1; i <= mn; ++i)
        v[i] = x[i] + y[i] + t,
        t = v[i] / 10,
        v[i] = v[i] % 10;
    for (int i = n + 1; i <= m; ++i)
        v[i] = x[i];
    for (int j = m + 1; j <= n; ++j)
        v[j] = y[j];
    k = m;
    if (n > k)
        k = n;
    if(t)
        v[++k] = t;
}

void write(){
    freopen ("data.out", "w", stdout);
    for (int i = k; i; --i)
        printf ("%d", v[i]);
    fclose(stdout);
}
