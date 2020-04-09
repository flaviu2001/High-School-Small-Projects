#include <cstdio>

using namespace std;

int n, v[15005*4], sol;

void update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr){
        v[nod] += val;
        return;
    }
    int m = (st+dr)/2;
    if(m >= poz)
        update(2*nod, st, m, poz, val);
    else
        update(2*nod+1, m+1, dr, poz, val);
    v[nod] = v[nod*2] + v[nod*2+1];
}

void ask(int nod, int st, int dr, int f, int l)
{
    if(st >= f && dr <= l){
        sol += v[nod];
        return;
    }
    int m = (st+dr)/2;
    if(m >= f)
        ask(2*nod, st, m, f, l);
    if(m < l)
        ask(2*nod + 1, m+1, dr, f, l);
}

int main()
{
    FILE*f=freopen("datorii.in","r",stdin);
    FILE*g=freopen("datorii.out","w",stdout);
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &x);
        update(1, 1, n, i, x);
    }
    while(m--){
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if(t == 0)
            update(1, 1, n, a, -b);
        else{
            sol = 0;
            ask(1, 1, n, a, b);
            printf("%d\n", sol);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

