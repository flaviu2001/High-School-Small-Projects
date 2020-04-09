#include <bits/stdc++.h>

using namespace std;

int n, t, v[1000005];

struct thing{
    int pos, sum;
}arb[4*1000005];

void update(int nod, int st, int dr, int pos, int val, int type = 1)
{
    if(st == dr){
        if(type == 1)
            arb[nod].pos = pos;
        else arb[nod].sum = val;
    }else{
        int m = (st+dr)>>1;
        if(m >= pos)
            update(nod<<1, st, m, pos, val, type);
        else update((nod<<1)+1, m+1, dr, pos, val, type);
        if(type == 1){
            if(v[arb[nod<<1].pos] > v[arb[(nod<<1)+1].pos])
                arb[nod].pos = arb[nod<<1].pos;
            else if (v[arb[nod<<1].pos] < v[arb[(nod<<1)+1].pos])
                arb[nod].pos = arb[(nod<<1)+1].pos;
            else arb[nod].pos = min(arb[nod<<1].pos, arb[(nod<<1)+1].pos);
        }
        else arb[nod].sum = arb[nod<<1].sum+arb[(nod<<1)+1].sum;
    }
}

int query1(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return arb[nod].pos;
    int m = (st+dr)>>1;
    int ans = 0;
    if(m >= l)
        ans = query1(nod<<1, st, m, l, r);
    if(m < r){
        int qr = query1((nod<<1)+1, m+1, dr, l, r);
        if(v[ans] < v[qr])
            ans = qr;
        if(v[ans] == v[qr])
            ans = min(ans, qr);
    }
    return ans;
}

int getx(int nod, int lo, int hi, int x, int sum, int lastm = 0)
{
    if(lo == hi)
        return lo;
    int m = (lo+hi)>>1;
    if(sum+(m-lastm)-arb[nod<<1].sum >= x)
        return getx(nod<<1, lo, m, x, sum, lastm);
    return getx((nod<<1)+1, m+1, hi, x, sum+(m-lastm)-arb[nod<<1].sum, m);
}

int main()
{
    ifstream fin ("eliminare.in");
    ofstream fout ("eliminare.out");
    fin >> n >> t;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        update(1, 1, n, i, v[i]);
    }
    while(t--){
        int x, y;
        fin >> x >> y;
        int pos = query1(1, 1, n, getx(1, 1, n, x, 0), getx(1, 1, n, y, 0));
        v[pos] = 0;
        update(1, 1, n, pos, 0);
        update(1, 1, n, pos, 1, 2);
    }
    for (int i = 1; i <= n; ++i)
        if(v[i] != 0)
            fout << v[i] << "\n";
    fout.close();
    return 0;
}

