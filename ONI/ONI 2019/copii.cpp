#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch() {
        ++sp;
        if (sp == 4096) {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }

    InParser& operator >> (char &c){
        c = read_ch();
        return *this;
    }
};

const ll nmax = 320005;
ll _0r[nmax], _1r[nmax], _0l[nmax], _1l[nmax];
int n, test, pr[nmax], pr2[nmax], p1[nmax], p2[nmax], p0l[nmax], p0r[nmax];
char v[nmax];

ll calc(ll x, ll y, ll m1)
{
    ll f1 = 0, l = pr[x-1], mv = y-x+1-(pr[y]-pr[x-1]);
    ll ones = x-1-l, ones2 = n-y-(pr[n]-pr[y]);
    f1 += _1r[p1[ones+m1]] - _1r[x-1] - m1*(x-1); //moving 1s on the left margin
    f1 += _0l[p0l[m1+(n-x+1-pr2[x])]]-_0l[x]-m1*(n-x); //moving 0s on the left margin
    f1 += _1l[p2[ones2+mv-m1]] - _1l[y+1] - (mv-m1)*(n-y); //moving 1s on the right margin
    f1 += _0r[p0r[pr[y]+mv-m1]]-_0r[y]-(mv-m1)*(y-1); //moving 0s on the right margin
    return f1;
}

int main()
{
    InParser fin ("copii3.in");
    ofstream fout ("copii3.out");
    fin >> n >> test;
    for (ll i = 1; i <= n; ++i){
        fin >> v[i];
        v[i] -= '0';
        pr[i] = pr[i-1] + 1-v[i];
        if(p1[i-pr[i]] == 0)
            p1[i-pr[i]] = i;
        if(p0r[pr[i]] == 0)
            p0r[pr[i]] = i;
        _0r[i] = _0r[i-1];
        _1r[i] = _1r[i-1];
        if(v[i] == 0)
            _0r[i] += (i-1);
        else _1r[i] += (i-1);
    }
    for (ll i = n; i >= 1; --i){
        pr2[i] = pr2[i+1] + v[i];
        if(p0l[n-i+1-pr2[i]] == 0)
            p0l[n-i+1-pr2[i]] = i;
        if(p2[pr2[i]] == 0)
            p2[pr2[i]] = i;
        _0l[i] = _0l[i+1];
        _1l[i] = _1l[i+1];
        if(v[i] == 0)
            _0l[i] += (n-i);
        else _1l[i] += (n-i);
    }
    while(test--){
        int x, y;
        fin >> x >> y;
        ll l = 0, r = 0, mv;
        l = pr[x-1];
        r = pr[n]-pr[y];
        mv = y-x+1-(pr[y]-pr[x-1]);
        ll lo = max(0ll, mv-r), hi = min(mv, l), m1, m2;
        if(hi < lo){
            fout << "-1\n";
            continue;
        }
        ll ans = calc(x, y, lo);
        while(lo < hi){
            m1 = lo+(hi-lo)/3;
            m2 = hi-(hi-lo)/3;
            ll f1 = calc(x, y, m1), f2 = calc(x, y, m2);
            if(m1 == lo && m2 == hi){
                for (int t = lo; t <= hi; ++t)
                    ans = min(ans, calc(x, y, t));
                break;
            }
            ans = min(f1, f2);
            if(f1 == f2){
                lo = m1;
                hi = m2;
            }else if (f1 < f2)
                hi = m2;
            else lo = m1;
        }
        fout << ans << "\n";
    }
    return 0;
}
