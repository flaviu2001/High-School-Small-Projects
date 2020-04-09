#include <bits/stdc++.h>

using namespace std;

struct whatever{
    long long x, y, i;
};

long long n, t, v[200005], ok[200005], w[200005], r[2000005];
vector<whatever> queries[200005];
long long q[200005];

whatever make_whatever(long long x, long long y, long long i)
{
    whatever watevah;
    watevah.x = x;
    watevah.y = y;
    watevah.i = i;
    return watevah;
}

void update(long long nod, long long st, long long dr, long long pos, long long val)
{
    if(st == dr)
        r[nod] = val;
    else{
        long long m = (st+dr)/2;
        if(m >= pos)
            update(nod*2, st, m, pos, val);
        else update(nod*2+1, m+1, dr, pos, val);
        r[nod] = r[nod*2]+r[nod*2+1];
    }
}

long long query(long long nod, long long st, long long dr, long long lo, long long hi)
{
    if(st >= lo && dr <= hi)
        return r[nod];
    long long m = (st+dr)/2, sol = 0;
    if(m >= lo)
        sol += query(nod*2, st, m, lo, hi);
    if(m < hi)
        sol += query(nod*2+1, m+1, dr, lo, hi);
    return sol;
}

int main()
{
    ifstream fin ("calafat.in");
    ofstream fout ("calafat.out");
    fin >> n >> t;
    for (long long i = 1; i <= n; ++i)
        fin >> w[i];
    for (long long i = 1; i <= t; ++i){
        long long x, y;
        fin >> x >> y;
        queries[y].push_back(make_whatever(x, y, i));
    }
    for (long long i = 1; i <= n; ++i){
        v[ok[w[i]]] = i-ok[w[i]];
        if(ok[w[i]] > 0)
            update(1, 1, n, ok[w[i]], v[ok[w[i]]]);
        ok[w[i]] = i;
        for (vector<whatever>::iterator it = queries[i].begin(); it != queries[i].end(); ++it){
            long long sol = query(1, 1, n, it->x, it->y);
            q[it->i] = sol;
        }
    }
    for (long long i = 1; i <= t; ++i)
        fout << q[i] << "\n";
    fin.close();
    fout.close();
    return 0;
}

