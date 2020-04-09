#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "intervale";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, nmax = 200005;

int n, v[nmax], p[nmax];

bool run(int &st, int &dr, int &a, int &b, int &pa, int &pb, int lo, int hi)
{
    if(b-a > hi-lo)
        return false;
    int nst = st, ndr = dr;
    if(pa == -1){
        for (int i = a; i <= b; ++i){
            nst = min(nst, p[i]);
            ndr = max(ndr, p[i]);
            if(ndr-nst > hi-lo || nst < lo || ndr > hi)
                return false;
        }
    }else{
        for (int i = a; i < pa; ++i){
            nst = min(nst, p[i]);
            ndr = max(ndr, p[i]);
            if(ndr-nst > hi-lo || nst < lo || ndr > hi)
                return false;
        }
        for (int i = pb+1; i <= b; ++i){
            nst = min(nst, p[i]);
            ndr = max(ndr, p[i]);
            if(ndr-nst > hi-lo || nst < lo || ndr > hi)
                return false;
        }
    }
    pa = a;
    pb = b;
    for (int i = nst; i < st; ++i){
        a = min(a, v[i]);
        b = max(b, v[i]);
        if(b-a > hi-lo)
            return false;
    }
    for (int i = dr+1; i <= ndr; ++i){
        a = min(a, v[i]);
        b = max(b, v[i]);
        if(b-a > hi-lo)
            return false;
    }
    st = nst;
    dr = ndr;
    return true;
}

ll rec(int lo, int hi)
{
    if(lo == hi)
        return 1;
    int m = (lo+hi)/2;
    ll ans = rec(lo, m) + rec(m+1, hi);
    int st = m, dr = m+1, a = min(v[m], v[m+1]), b = max(v[m], v[m+1]), pa = -1, pb = -1;
    if(b == a+1)
        pa = a, pb = b;
    if(b-a+1 > hi-lo+1)
        return ans;
    while(b-a != dr-st)
        if(!run(st, dr, a, b, pa, pb, lo, hi))
            return ans;
    ++ans;
    while(st >= lo && dr <= hi){
        if(st == lo && dr == hi)
            return ans;
        if(st == lo){
            ++dr;
            a = min(a, v[dr]);
            b = max(b, v[dr]);
            while(b-a != dr-st)
                if(!run(st, dr, a, b, pa, pb, lo, hi))
                    return ans;
            ++ans;
        }else if (dr == hi){
            --st;
            a = min(a, v[st]);
            b = max(b, v[st]);
            while(b-a != dr-st)
                if(!run(st, dr, a, b, pa, pb, lo, hi))
                    return ans;
            ++ans;
        }else{
            if(v[st-1] > b && v[dr+1] > b){
                if(v[st-1] < v[dr+1]){
                    --st;
                    a = min(a, v[st]);
                    b = max(b, v[st]);
                }else{
                    ++dr;
                    a = min(a, v[dr]);
                    b = max(b, v[dr]);
                }
                while(b-a != dr-st)
                    if(!run(st, dr, a, b, pa, pb, lo, hi))
                        return ans;
                ++ans;
            }else if (v[st-1] < a && v[dr+1] < a){
                if(v[st-1] > v[dr+1]){
                    --st;
                    a = min(a, v[st]);
                    b = max(b, v[st]);
                }else{
                    ++dr;
                    a = min(a, v[dr]);
                    b = max(b, v[dr]);
                }
                while(b-a != dr-st)
                    if(!run(st, dr, a, b, pa, pb, lo, hi))
                        return ans;
                ++ans;
            }else{
                if(v[dr+1] > b){
                    int lowerleft = 0;
                    for (int i = dr+1; i <= hi; ++i)
                        if(v[i] < a)
                            lowerleft = max(lowerleft, v[i]);
                    int upperright = n+1;
                    for (int i = lo; i < st; ++i)
                        if(v[i] > b)
                            upperright = min(upperright, v[i]);
                    int nst = st, ndr = dr, lscore = 0, rscore = 0, nna = a, nnb = b;
                    if(v[st-1] > lowerleft && v[st-1] < a){
                        int in = st-2, na = v[st-1], nb = v[st-1];
                        nna = min(nna, v[st-1]);
                        nnb = max(nnb, v[st-1]);
                        if(nb == a-1)
                            ++lscore;
                        nst = st-1;
                        while(in >= lo && v[in] > lowerleft && v[in] < a){
                            nst = in;
                            na = min(na, v[in]);
                            nb = max(nb, v[in]);
                            nna = min(nna, v[in]);
                            nnb = max(nnb, v[in]);
                            if(nb-na == st-1-in && nb == a-1)
                                ++lscore;
                            --in;
                        }
                    }
                    if(v[dr+1] < upperright && v[dr+1] > b){
                        int in = dr+2, na = v[dr+1], nb = v[dr+1];
                        nna = min(nna, v[dr+1]);
                        nnb = max(nnb, v[dr+1]);
                        if(na == b+1)
                            ++rscore;
                        ndr = dr+1;
                        while(in <= hi && v[in] < upperright && v[in] > b){
                            ndr = in;
                            na = min(na, v[in]);
                            nb = max(nb, v[in]);
                            nna = min(nna, v[in]);
                            nnb = max(nnb, v[in]);
                            if(nb-na == in-dr-1 && na == b+1)
                                ++rscore;
                            ++in;
                        }
                    }
                    if(nst == st && ndr == dr){
                        pa = a;
                        pb = b;
                        --st;
                        ++dr;
                        a = min(a, v[st]);
                        b = max(b, v[st]);
                        a = min(a, v[dr]);
                        b = max(b, v[dr]);
                        while(b-a != dr-st)
                            if(!run(st, dr, a, b, pa, pb, lo, hi))
                                return ans;
                        ++ans;
                        continue;
                    }
                    ans += 1ll*(lscore+1)*(rscore+1)-1;
                    st = nst;
                    dr = ndr;
                    pa = a;
                    pb = b;
                    a = nna;
                    b = nnb;
                    while(b-a != dr-st)
                        if(!run(st, dr, a, b, pa, pb, lo, hi))
                            return ans;
                    if(ndr-nst!=nnb-nna)
                        ++ans;
                }else{
                    int upperleft = n+1;
                    for (int i = dr+1; i <= hi; ++i)
                        if(v[i] > b)
                            upperleft = min(upperleft, v[i]);
                    int lowerright = 0;
                    for (int i = lo; i < st; ++i)
                        if(v[i] < a)
                            lowerright = max(lowerright, v[i]);
                    int nst = st, ndr = dr, lscore = 0, rscore = 0, nna = a, nnb = b;
                    if(v[st-1] < upperleft && v[st-1] > b){
                        int in = st-2, na = v[st-1], nb = v[st-1];
                        nna = min(nna, v[st-1]);
                        nnb = max(nnb, v[st-1]);
                        if(na == b+1)
                            ++lscore;
                        nst = st-1;
                        while(in >= lo && v[in] < upperleft && v[in] > b){
                            nst = in;
                            na = min(na, v[in]);
                            nb = max(nb, v[in]);
                            nna = min(nna, v[in]);
                            nnb = max(nnb, v[in]);
                            if(nb-na == st-1-in && na == b+1)
                                ++lscore;
                            --in;
                        }
                    }
                    if(v[dr+1] > lowerright && v[dr+1] < a){
                        int in = dr+2, na = v[dr+1], nb = v[dr+1];
                        nna = min(nna, v[dr+1]);
                        nnb = max(nnb, v[dr+1]);
                        if(nb == a-1)
                            ++rscore;
                        ndr = dr+1;
                        while(in <= hi && v[in] > lowerright && v[in] < a){
                            ndr = in;
                            na = min(na, v[in]);
                            nb = max(nb, v[in]);
                            nna = min(nna, v[in]);
                            nnb = max(nnb, v[in]);
                            if(nb-na == in-dr-1 && nb == a-1)
                                ++rscore;
                            ++in;
                        }
                    }
                    if(nst == st && ndr == dr){
                        pa = a;
                        pb = b;
                        --st;
                        ++dr;
                        a = min(a, v[st]);
                        b = max(b, v[st]);
                        a = min(a, v[dr]);
                        b = max(b, v[dr]);
                        while(b-a != dr-st)
                            if(!run(st, dr, a, b, pa, pb, lo, hi))
                                return ans;
                        ++ans;
                        continue;
                    }
                    ans += 1ll*(lscore+1)*(rscore+1)-1;
                    st = nst;
                    dr = ndr;
                    pa = a;
                    pb = b;
                    a = nna;
                    b = nnb;
                    while(b-a != dr-st)
                        if(!run(st, dr, a, b, pa, pb, lo, hi))
                            return ans;
                    if(ndr-nst!=nnb-nna)
                        ++ans;
                }
            }
        }
    }
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        p[v[i]] = i;
    }
    fout << rec(1, n) << "\n";
    return 0;
}
