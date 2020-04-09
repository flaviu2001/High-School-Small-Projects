/*
6 4
932102
1234
*/

#include <cstdio>

using namespace std;

int x[10001], y[10001], v[10001];
int n, m, k;

void read();
void substr();
void write();

int main(){
    read();
    substr();
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

void substr(){
    int t = 0;
    k = n;
    if (m > k)
        k = m;
    for (int i = 1; i <= k; ++i){
        v[i] = x[i] - y[i] - t;
        if (v[i] < 0)
            t = 1,
            v[i] += 10;
	else t = 0;
    }
    while(k > 1 && !v[k])
        --k;
}

void write(){
    freopen ("data.out", "w", stdout);
    for (int i = k; i; --i)
        printf ("%d", v[i]);
    fclose(stdout);
}
