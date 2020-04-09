#include <bits/stdc++.h>

using namespace std;

struct thing{
    int prmin, prmax, sum;
};

const int nmax = 200005;
int n, test, v[nmax], lazy[nmax*4];
thing arb[nmax*4];

thing make_thing(int prmin, int prmax, int sum)
{
    thing aux;
    aux.prmax = prmax;
    aux.prmin = prmin;
    aux.sum = sum;
    return aux;
}

void build(int nod, int st, int dr)
{
    if(st == dr)
        arb[nod].prmin = arb[nod].prmax = arb[nod].sum = v[st];
    else{
        int m = (st+dr)/2;
        build(nod*2, st, m);
        build(nod*2+1, m+1, dr);
        arb[nod].sum = arb[nod*2].sum + arb[nod*2+1].sum;
        arb[nod].prmin = min(arb[nod*2].prmin, arb[nod*2].sum+arb[nod*2+1].prmin);
        arb[nod].prmax = max(arb[nod*2].prmax, arb[nod*2].sum+arb[nod*2+1].prmax);
    }
}

void update(int nod, int st, int dr, int l, int r)
{
    if(lazy[nod]){
        int aux = arb[nod].prmin;
        arb[nod].prmin = arb[nod].prmax*(-1);
        arb[nod].prmax = aux*(-1);
        arb[nod].sum *= -1;
        if(st != dr){
            lazy[nod*2] = 1-lazy[nod*2];
            lazy[nod*2+1] = 1-lazy[nod*2+1];
        }
        lazy[nod] = 0;
    }
    if(st > r || dr < l)
        return;
    if(st >= l && dr <= r){
        int aux = arb[nod].prmin;
        arb[nod].prmin = arb[nod].prmax*(-1);
        arb[nod].prmax = aux*(-1);
        arb[nod].sum *= -1;
        if(st != dr){
            lazy[nod*2] = 1-lazy[nod*2];
            lazy[nod*2+1] = 1-lazy[nod*2+1];
        }
        return;
    }
    int m = (st+dr)/2;
    update(nod*2, st, m, l, r);
    update(nod*2+1, m+1, dr, l, r);
    arb[nod].sum = arb[nod*2].sum + arb[nod*2+1].sum;
    arb[nod].prmin = min(arb[nod*2].prmin, arb[nod*2].sum+arb[nod*2+1].prmin);
    arb[nod].prmax = max(arb[nod*2].prmax, arb[nod*2].sum+arb[nod*2+1].prmax);
}

thing query(int nod, int st, int dr, int l, int r)
{
    if(lazy[nod]){
        int aux = arb[nod].prmin;
        arb[nod].prmin = arb[nod].prmax*(-1);
        arb[nod].prmax = aux*(-1);
        arb[nod].sum *= -1;
        if(st != dr){
            lazy[nod*2] = 1-lazy[nod*2];
            lazy[nod*2+1] = 1-lazy[nod*2+1];
        }
        lazy[nod] = 0;
    }
    if(st > r || dr < l)
        return make_thing(2000000000, -2000000000, 0);
    if(st >= l && dr <= r)
        return arb[nod];
    int m = (st+dr)/2;
    thing q1 = query(nod*2, st, m, l, r), q2 = query(nod*2+1, m+1, dr, l, r), sol;
    sol.prmin = min(q1.prmin, q1.sum+q2.prmin);
    sol.prmax = max(q1.prmax, q1.sum+q2.prmax);
    sol.sum = q1.sum+q2.sum;
    return sol;
}

int main()
{
    ifstream fin ("luffpar.in");
    ofstream fout ("luffpar.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        char q;
        fin >> q;
        if(q == '(')
            v[i] = 1;
        else v[i] = -1;
    }
    build(1, 1, n);
    fin >> test;
    while(test--){
        int t, a, b;
        fin >> t >> a >> b;
        if(t == 1)
            update(1, 1, n, a, b);
        else{
            thing ans = query(1, 1, n, a, b);
            if(ans.prmin < 0){
                fout << "0\n";
                continue;
            }
            if(ans.sum != 0)
                fout << "0\n";
            else fout << "1\n";
        }
    }
    return 0;
}

