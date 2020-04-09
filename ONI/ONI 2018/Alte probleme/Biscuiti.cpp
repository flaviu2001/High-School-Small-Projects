#include <bits/stdc++.h>

using namespace std;

struct node{
    int64_t val, pos;
    bool operator<(const node &obj)const{
        if(val != obj.val)
            return val < obj.val;
        return pos < obj.pos;
    }
};

const int64_t nmax = 100005, inf = 2000000000000000;
int64_t n, v[nmax], lazy[4*nmax], sol;
node arb[4*nmax];

node make_node(int64_t val, int64_t pos)
{
    node aux;
    aux.val = val;
    aux.pos = pos;
    return aux;
}

void build(int64_t nod, int64_t st, int64_t dr)
{
    if(st == dr)
        arb[nod] = make_node(v[st], st);
    else{
        int64_t m = (st+dr)/2;
        build(nod*2, st, m);
        build(nod*2+1, m+1, dr);
        arb[nod] = min(arb[nod*2], arb[nod*2+1]);
    }
}

void update(int64_t nod, int64_t st, int64_t dr, int64_t l, int64_t r, int64_t val)
{
    if(lazy[nod] != 0){
        arb[nod].val += lazy[nod];
        if(st != dr){
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(st > r || dr < l)
        return;
    if(st >= l && dr <= r){
        arb[nod].val += val;
        if(st != dr){
            lazy[nod*2] += val;
            lazy[nod*2+1] += val;
        }
    }else{
        int64_t m = (st+dr)/2;
        update(nod*2, st, m, l, r, val);
        update(nod*2+1, m+1, dr, l, r, val);
        arb[nod] = min(arb[nod*2], arb[nod*2+1]);
    }
}

node query(int64_t nod, int64_t st, int64_t dr, int64_t l, int64_t r)
{
    if(lazy[nod] != 0){
        arb[nod].val += lazy[nod];
        if(st != dr){
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(st >= l && dr <= r)
        return arb[nod];
    int64_t m = (st+dr)/2;
    node ans = make_node(inf, 0);
    if(m >= l)
        ans = query(nod*2, st, m, l, r);
    if(m < r)
        ans = min(ans, query(nod*2+1, m+1, dr, l, r));
    return ans;
}

int main()
{
    ifstream fin ("biscuiti.in");
    ofstream fout ("biscuiti.out");
    fin >> n;
    for (int64_t i = 1; i <= n; ++i)
        fin >> v[i];
    build(1, 1, n);
    for (int64_t t = 1; t <= n; ++t){
        node now = query(1, 1, n, 1, n);
        sol += now.val - v[now.pos];
        update(1, 1, n, now.pos, now.pos, inf);
        if(now.pos != 1)
            update(1, 1, n, 1, now.pos, t);
    }
    fout << sol;
    return 0;
}

