#include <bits/stdc++.h>

using namespace std;

struct thing{
    long long x, r;
    bool operator<(const thing &obj)const{
        return x < obj.x;
    }
};

long long n, t, I;
multiset<thing> s;
long long sol;
thing v[200005], mx;

thing make_thing(long long x, long long r)
{
    thing aux;
    aux.x = x;
    aux.r = r;
    return aux;
}

void ineficient(long long p)
{
    for (long long i = 1; i <= p; ++i){
        thing e = *(s.begin());
        s.erase(s.begin());
        sol += e.x;
        e.x += e.r;
        s.insert(e);
    }
}

long long useUntil(long long x)
{
    long long p = x;
    long long val = v[I].x + (x-1)*v[I].r;
    for (long long i = 1; i <= n; ++i)
        if(i != I)
            p += (val-v[i].x)/v[i].r+1;
    return p;
}

long long value(long long x, long long J)
{
    return x*v[J].x + v[J].r*(x*(x-1)/2);
}

int main()
{
    ifstream fin ("tarabe.in");
    ofstream fout ("tarabe.out");
    fin >> n >> t;
    mx = make_thing(2000000000, 2000000000);
    for (long long i = 1; i <= n; ++i){
        long long x, r;
        fin >> r >> x;
        v[i] = make_thing(x, r);
        if(v[i].r < mx.r){
            mx = v[i];
            I = i;
        }
        else if (v[i].r == mx.r && v[i].x < mx.r){
            mx = v[i];
            I = i;
        }
    }
    if(t <= 200000){
        for (long long i = 1; i <= n; ++i)
            s.insert(v[i]);
        ineficient(t);
    }
    else{
        long long lo = 1, hi = 1000000, m, ans;
        for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2){
            long long var = useUntil(m);
            if(var <= t){
                ans = m;
                lo = m+1;
            }else hi = m-1;
        }
        sol += value(ans, I);
        long long use = useUntil(ans);
        long long val = v[I].x + (ans-1)*v[I].r;
        for (long long i = 1; i <= n; ++i)
            if(i != I){
                sol += value((val-v[i].x)/v[i].r+1, i);
                v[i].x += v[i].r*((val-v[i].x)/v[i].r+1);
                s.insert(v[i]);
            }else{
                v[i].x += v[i].r*ans;
                s.insert(v[i]);
            }
        ineficient(t-use);
    }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

