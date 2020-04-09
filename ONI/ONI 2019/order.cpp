#include <bits/stdc++.h>

using namespace std;

int n, aint[120005], v[30005], p = 1, over, y;

void update(int pos, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr){
        ++aint[nod];
    }else{
        int m = (st+dr)/2;
        if(pos <= m)
            update(pos, nod*2, st, m);
        else update(pos, nod*2+1, m+1, dr);
        aint[nod] = aint[nod*2] + aint[nod*2+1];
    }
}

int query(int lo, int hi, int nod = 1, int st = 1, int dr = n)
{
    if(lo > hi)
        return 0;
    if(st >= lo && dr <= hi)
        return aint[nod];
    int m = (st+dr)/2, ans = 0;
    if(m >= lo)
        ans = query(lo, hi, nod*2, st, m);
    if(m+1 <= hi)
        ans += query(lo, hi, nod*2+1, m+1, dr);
    return ans;
}

void src(int x, int lo, int hi, int nod = 1, int st = 1, int dr = n)
{
    if(over)
        return;
    if(st == dr){
        y += aint[nod];
        if(st-y-(lo-1) == x){
            p = st;
            over = true;
        }
        return;
    }
    int m = (st+dr)/2;
    if(st >= lo && dr <= hi){
        if(dr-y-aint[nod]-(lo-1) < x){
            y += aint[nod];
            return;
        }
        if(m-y-aint[nod*2]-(lo-1) >= x){
            src(x, lo, hi, nod*2, st, m);
            over = true;
            return;
        }
        y += aint[nod*2];
        src(x, lo, hi, nod*2+1, m+1, dr);
        over = true;
    }else{
        if(m >= lo)
            src(x, lo, hi, nod*2, st, m);
        if(over)
            return;
        if(m+1 <= hi)
            src(x, lo, hi, nod*2+1, m+1, dr);
    }
}

int main()
{
    ifstream fin ("order.in");
    ofstream fout ("order.out");
    fin >> n;
    for (int i = 1; i < n; ++i){
        int tg = i%(n-i+1), qr = query(p+1, n);
        if(tg == 0)
            tg = n-i+1;
        if(!(p == n || (n-p-qr) < tg)){
            over = false; y = 0;
            src(tg, p+1, n);
            update(p);
            v[p] = 1;
            fout << p << " ";
        }else{
            tg -= (n-p-qr);
            over = false; y = 0;
            src(tg, 1, p-1);
            update(p);
            v[p] = 1;
            fout << p << " ";
        }
    }
    for (int i = 1; i <= n; ++i)
        if(v[i] == 0)
            fout << i << "\n";
    return 0;
}

