#include <bits/stdc++.h>

using namespace std;

struct node{
    int64_t mn, mx;
    void operator=(const int64_t vec[]){
        mn = vec[0];
        mx = vec[1];
    }
};

const int64_t nmax = 1000005;
int64_t n, k, t, v[nmax], a[5000], b[5000], posret;
node arb[nmax*4], q;

void build(int64_t nod = 1, int64_t st = 1, int64_t dr = n)
{
    if(st == dr)
        arb[nod] = {v[st], v[st]};
    else{
        int64_t m = (st+dr)/2;
        build(nod*2, st, m);
        build(nod*2+1, m+1, dr);
        arb[nod] = {min(arb[nod*2].mn, arb[nod*2+1].mn), max(arb[nod*2].mx, arb[nod*2+1].mx)};
    }
}

int64_t smecherie(node x)
{
    return (x.mx-x.mn+1)/2;
}

node join (node a, node b)
{
    node aux;
    aux.mn = min(a.mn, b.mn);
    aux.mx = max(a.mx, b.mx);
    return aux;
}

void query(int64_t valmax, int64_t pos, int64_t nod = 1, int64_t st = 1, int64_t dr = n)
{
    int64_t m = (st+dr)/2;
    if(st < pos){
        if(pos > m)
            query(valmax, pos, nod*2+1, m+1, dr);
        else{
            query(valmax, pos, nod*2, st, m);
            if(posret == m)
                query(valmax, pos, nod*2+1, m+1, dr);
        }
    }else{
        if(posret != st-1)
            return;
        node both = join(q, arb[nod]);
        if(smecherie(both) > valmax){
            if(st == dr)
                return;
            node one = {v[st], v[st]};
            if(smecherie(join(q, one)) > valmax)
                return;
            if(smecherie(join(q, arb[nod*2])) > valmax)
                query(valmax, pos, nod*2, st, m);
            else{
                posret = m;
                q = join(q, arb[nod*2]);
                query(valmax, pos, nod*2+1, m+1, dr);
            }
        }else{
            q = both;
            posret = dr;
        }
    }
}

bool solve(int64_t valmax)
{
    int64_t cnt = 0, p = 1;
    while(p <= n){
        ++cnt;
        if(cnt > k)
            return false;
        if(p == n)
            return true;
        q = {v[p], v[p]};
        posret = p;
        query(valmax, p+1);
        p = posret+1;
    }
    return true;
}

int main()
{
    ifstream fin ("ksecv4.in");
    ofstream fout ("ksecv4.out");
    fin >> n >> k >> t;
    for (int64_t i = 0; i < t; ++i)
        fin >> a[i];
    for (int64_t i = 0; i < t; ++i)
        fin >> b[i];
    for (int64_t i = 0; i < n; ++i)
        v[i+1] = (a[i%t]^b[i/t]);
    build();
    int64_t st = 0, dr = (1LL<<61), m, ans = -1;
    for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
        if(solve(m)){
            ans = m;
            dr = m-1;
        }else st = m+1;
    fout << ans << "\n";
    return 0;
}

