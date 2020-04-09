#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int *aint[nmax*4], *e[nmax*4], n, test, v[nmax], r[nmax], pw2[nmax];
bool ok[nmax];

void update(int pos, int val, int len, int nod)
{
    ++pos;
    while(pos <= len){
        aint[nod][pos-1] += val;
        pos += (pos&(-pos));
    }
}

int read(int pos, int len, int nod)
{
    if(pos == -1)
        return 0;
    ++pos;
    int sum = 0;
    while(pos){
        sum += aint[nod][pos-1];
        pos -= (pos&(-pos));
    }
    return sum;
}

void build(int nod, int st, int dr)
{
    int len = dr-st+1;
    aint[nod] = new int[len];
    e[nod] = new int[len];
    for (int i = st; i <= dr; ++i)
        e[nod][i-st] = v[i], aint[nod][i-st] = 0;
    sort(e[nod], e[nod]+len);
    if(st != dr){
        int m = (st+dr)>>1;
        build(nod<<1, st, m);
        build((nod<<1)+1, m+1, dr);
    }
}

int find(int nod, int len, int x)
{
    if(e[nod][0] > x)
        return -1;
    int m = 0;
    for (int b = pw2[len-1]; b > 0; b >>= 1)
        if(m+b <= len-1 && e[nod][m+b] <= x)
            m += b;
    return m;
}

void flip(int nod, int st, int dr, int pos)
{
    int p = find(nod, dr-st+1, v[pos]);
    update(p, ok[pos] ? -1 : 1, dr-st+1, nod);
    if(st != dr){
        int m = (st+dr)>>1;
        if(pos <= m)
            flip(nod<<1, st, m, pos);
        else flip((nod<<1)+1, m+1, dr, pos);
    }
}

int count(int nod, int st, int  dr, int l, int r, int k)
{
    if(st >= l && dr <= r){
        int p = find(nod, dr-st+1, k);
        return p-read(p, dr-st+1, nod)+1;
    }
    int m = (st+dr)>>1, ans = 0;
    if(m >= l)
        ans += count(nod<<1, st, m, l, r, k);
    if(m+1 <= r)
        ans += count((nod<<1)+1, m+1, dr, l, r, k);
    return ans;
}

int main()
{
    ifstream fin ("mess.in");
    ofstream fout ("mess.out");
    fin >> n >> test;
    pw2[1] = 1;
    for (int i = 2; i <= n; ++i)
        if(pw2[i-1]*2 == i)
            pw2[i] = pw2[i-1]<<1;
        else pw2[i] = pw2[i-1];
    for (int i = 1; i <= n; ++i)
        fin >> v[i], r[i] = v[i];
    sort(r+1, r+n+1);
    build(1, 1, n);
    while(test--){
        int t;
        fin >> t;
        if(t == 1){
            int x;
            fin >> x;
            flip(1, 1, n, x);
            ok[x] ^= 1;
        }else{
            int a, b, k;
            fin >> a >> b >> k;
            int st = 1, dr = n, m, ans=0;
            for (m = (st+dr)>>1; st <= dr; m = (st+dr)>>1)
                if(count(1, 1, n, a, b, r[m]) >= k){
                    ans = r[m];
                    dr = m-1;
                }else st = m+1;
            fout << ans << "\n";
        }
    }
    return 0;
}
