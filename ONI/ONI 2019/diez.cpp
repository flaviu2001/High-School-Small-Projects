#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "diez";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 500005, B = 26, M1 = 1000000007, M2 = 1000000097;

struct query{
    int t, p, q1, q2, lg;
    char x;
} e[nmax];

int n, test, aib[nmax], ans[nmax], pw1[nmax], pw2[nmax], aintsz[nmax*4];
pi ainth[nmax*4];
char v[nmax];
string s;

void update(int idx, int val)
{
    while(idx <= n){
        aib[idx] += val;
        idx += (idx & (-idx));
    }
}

int read(int idx)
{
    int sum = 0;
    while(idx){
        sum += aib[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

void build(int nod, int st, int dr)
{
    if(st == dr){
        aintsz[nod] = 1;
        ainth[nod] = {v[st]-'a', v[st]-'a'};
        return;
    }
    int m = (st+dr)/2;
    build(nod*2, st, m);
    build(nod*2+1, m+1, dr);
    int h1 = ainth[nod*2].ff;
    h1 = (1ll*h1*pw1[aintsz[nod*2+1]])%M1;
    ainth[nod].ff = (h1+ainth[nod*2+1].ff)%M1;
    int h2 = ainth[nod*2].ss;
    h2 = (1ll*h2*pw2[aintsz[nod*2+1]])%M2;
    ainth[nod].ss = (h2+ainth[nod*2+1].ss)%M2;
    aintsz[nod] = aintsz[nod*2]+aintsz[nod*2+1];
}

void updateaint(int nod, int st, int dr, int pos)
{
    if(st == dr){
        aintsz[nod] = 0;
        ainth[nod] = {0, 0};
        return;
    }
    int m = (st+dr)/2;
    if(m >= pos)
        updateaint(nod*2, st, m, pos);
    else updateaint(nod*2+1, m+1, dr, pos);
    int h1 = ainth[nod*2].ff;
    h1 = (1ll*h1*pw1[aintsz[nod*2+1]])%M1;
    ainth[nod].ff = (h1+ainth[nod*2+1].ff)%M1;
    int h2 = ainth[nod*2].ss;
    h2 = (1ll*h2*pw2[aintsz[nod*2+1]])%M2;
    ainth[nod].ss = (h2+ainth[nod*2+1].ss)%M2;
    aintsz[nod] = aintsz[nod*2]+aintsz[nod*2+1];
}

pi query1(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return {aintsz[nod], ainth[nod].ff};
    int m = (st+dr)/2;
    pi now = {0, 0};
    if(m >= l)
        now = query1(nod*2, st, m, l, r);
    if(m+1 <= r){
        pi now2 = query1(nod*2+1, m+1, dr, l, r);
        int h1 = now.ss;
        h1 = (1ll*h1*pw1[now2.ff])%M1;
        now.ss = (h1+now2.ss)%M1;
        now.ff += now2.ff;
    }
    return now;
}

pi query2(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return {aintsz[nod], ainth[nod].ss};
    int m = (st+dr)/2;
    pi now = {0, 0};
    if(m >= l)
        now = query2(nod*2, st, m, l, r);
    if(m+1 <= r){
        pi now2 = query2(nod*2+1, m+1, dr, l, r);
        int h2 = now.ss;
        h2 = (1ll*h2*pw2[now2.ff])%M2;
        now.ss = (h2+now2.ss)%M2;
        now.ff += now2.ff;
    }
    return now;
}

int findIndex(int lf)
{
    int st = 1, dr = n, m, now=-1;
    for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
        if(m-read(m) >= lf){
            now = m;
            dr = m-1;
        }else st = m+1;
    return now;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    pw1[0] = 1;
    for (int i = 1; i < nmax; ++i)
        pw1[i] = (1ll*pw1[i-1]*B)%M1;
    pw2[0] = 1;
    for (int i = 1; i < nmax; ++i)
        pw2[i] = (1ll*pw2[i-1]*B)%M2;
    fin >> n >> test;
    fin >> s;
    for (int i = 1; i <= test; ++i){
        fin >> e[i].t;
        if(e[i].t == 1){
            fin >> e[i].p >> e[i].x;
            ++n;
            ++e[i].p;
        }else{
            fin >> e[i].q1 >> e[i].q2 >> e[i].lg;
            ++e[i].q1;
            ++e[i].q2;
        }
    }
    for (int i = test; i >= 1; --i)
        if(e[i].t == 1){
            int now = findIndex(e[i].p);
            update(now, 1);
            v[now] = e[i].x;
        }
    int last = 0;
    for (int i = 1; i <= n; ++i)
        if(v[i] == 0)
            v[i] = s[last++];
    memset(aib, 0, sizeof(aib));
    build(1, 1, n);
    for (int i = test; i >= 1; --i)
        if(e[i].t == 1){
            int now = findIndex(e[i].p);
            update(now, 1);
            updateaint(1, 1, n, now);
        }else{
            int a1, a2, b1, b2;
            a1 = findIndex(e[i].q1);
            b1 = findIndex(e[i].q2);
            a2 = findIndex(e[i].q1+e[i].lg-1);
            b2 = findIndex(e[i].q2+e[i].lg-1);
            pi ha1 = query1(1, 1, n, a1, a2);
            pi hb1 = query1(1, 1, n, b1, b2);
            if(ha1 != hb1)
                continue;
            pi ha2 = query2(1, 1, n, a1, a2);
            pi hb2 = query2(1, 1, n, b1, b2);
            if(ha2 != hb2)
                continue;
            ans[i] = 1;
        }
    for (int i = 1; i <= test; ++i)
        if(e[i].t == 2)
            fout << ans[i] << "\n";
    return 0;
}
