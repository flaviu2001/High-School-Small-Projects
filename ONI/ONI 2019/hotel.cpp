#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int n, test, lazy_add[nmax*4], lazy_rem[nmax*4], aintl[nmax*4], aintr[nmax*4], aint[nmax*4];

void prop_a(int nod, int st, int dr)
{
    if(lazy_add[nod]){
        aintl[nod] = 0;
        aintr[nod] = 0;
        aint[nod] = 0;
        lazy_add[nod] = 0;
        lazy_rem[nod] = 0;
        if(st != dr){
            lazy_add[nod*2] = 1;
            lazy_add[nod*2+1] = 1;
            lazy_rem[nod*2] = 0;
            lazy_rem[nod*2+1] = 0;
        }
    }
}

void prop_r(int nod, int st, int dr)
{
    if(lazy_rem[nod]){
        aintl[nod] = dr-st+1;
        aintr[nod] = dr-st+1;
        aint[nod] = dr-st+1;
        lazy_rem[nod] = 0;
        lazy_add[nod] = 0;
        if(st != dr){
            lazy_rem[nod*2] = 1;
            lazy_rem[nod*2+1] = 1;
            lazy_add[nod*2] = 0;
            lazy_add[nod*2+1] = 0;
        }
    }
}

void propagate(int nod, int st, int dr, bool order=false)
{
    if(order){
        prop_r(nod, st, dr);
        prop_a(nod, st, dr);
    }else{
        prop_a(nod, st, dr);
        prop_r(nod, st, dr);
    }
}

void update_add(int nod, int st, int dr, int l, int r)
{
    propagate(nod, st, dr, true);
    if(st >= l && dr <= r){
        aintl[nod] = 0;
        aintr[nod] = 0;
        aint[nod] = 0;
        if(st != dr){
            lazy_add[nod*2] = 1;
            lazy_add[nod*2+1] = 1;
            lazy_rem[nod*2] = 0;
            lazy_rem[nod*2+1] = 0;
        }
        return;
    }
    if(st > r || dr < l)
        return;
    int m = (st+dr)/2;
    update_add(nod*2, st, m, l, r);
    update_add(nod*2+1, m+1, dr, l, r);
    aintr[nod] = aintr[nod*2+1];
    if(aintr[nod*2+1] == dr-m)
        aintr[nod] += aintr[nod*2];
    aintl[nod] = aintl[nod*2];
    if(aintl[nod*2] == m-st+1)
        aintl[nod] += aintl[nod*2+1];
    aint[nod] = max(aint[nod*2], aint[nod*2+1]);
    aint[nod] = max(aint[nod], aintr[nod*2]+aintl[nod*2+1]);
}

void update_rem(int nod, int st, int dr, int l, int r)
{
    propagate(nod, st, dr);
    if(st >= l && dr <= r){
        aintl[nod] = dr-st+1;
        aintr[nod] = dr-st+1;
        aint[nod] = dr-st+1;
        if(st != dr){
            lazy_rem[nod*2] = 1;
            lazy_rem[nod*2+1] = 1;
            lazy_add[nod*2] = 0;
            lazy_add[nod*2+1] = 0;
        }
        return;
    }
    if(st > r || dr < l)
        return;
    int m = (st+dr)/2;
    update_rem(nod*2, st, m, l, r);
    update_rem(nod*2+1, m+1, dr, l, r);
    aintr[nod] = aintr[nod*2+1];
    if(aintr[nod*2+1] == dr-m)
        aintr[nod] += aintr[nod*2];
    aintl[nod] = aintl[nod*2];
    if(aintl[nod*2] == m-st+1)
        aintl[nod] += aintl[nod*2+1];
    aint[nod] = max(aint[nod*2], aint[nod*2+1]);
    aint[nod] = max(aint[nod], aintr[nod*2]+aintl[nod*2+1]);
}

int query()
{
    propagate(1, 1, n);
    propagate(2, 1, (n+1)/2);
    propagate(3, (n+1)/2+1, n);
    return max(aint[1], aintr[2]+aintl[3]);
}

void init(int nod, int st, int dr)
{
    aintl[nod] = dr-st+1;
    aintr[nod] = dr-st+1;
    aint[nod] = dr-st+1;
    if(st != dr){
        int m = (st+dr)/2;
        init(nod*2, st, m);
        init(nod*2+1, m+1, dr);
    }
}

int main()
{
    ifstream fin ("hotel.in");
    ofstream fout ("hotel.out");
    fin >> n >> test;
    init(1, 1, n);
    for (int tst = 1; tst <= test; ++tst){
        int t;
        fin >> t;
        if(t == 1){
            int x, y;
            fin >> x >> y;
            y = x+y-1;
            update_add(1, 1, n, x, y);
        }else if (t == 2){
            int x, y;
            fin >> x >> y;
            y = x+y-1;
            update_rem(1, 1, n, x, y);
        }else
            fout << query() << "\n";
    }
    return 0;
}
