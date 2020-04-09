#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "scmax";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, v[nmax], r[nmax], p, nxt[nmax], to[nmax];
unordered_map<int, int> mp;
pi aint[nmax*4];

void update(int nod, int st, int dr, int pos, pi val)
{
    if(st == dr)
        aint[nod] = val;
    else{
        int m = (st+dr)/2;
        if(m >= pos)
            update(nod*2, st, m, pos, val);
        else update(nod*2+1, m+1, dr, pos, val);
        aint[nod] = max(aint[nod*2], aint[nod*2+1]);
    }
}

pi query(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return aint[nod];
    int m = (st+dr)/2;
    pi ans = {0, 0};
    if(m >= l)
        ans = query(nod*2, st, m, l, r);
    if(m+1 <= r)
        ans = max(ans, query(nod*2+1, m+1, dr, l, r));
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i], r[i] = v[i];
    sort(r+1, r+n+1);
    for (int i = 1; i <= n; ++i)
        if(r[i] != r[i-1]){
            mp[r[i]] = ++p;
            to[p] = r[i];
        }
    for (int i = 1; i <= n; ++i)
        v[i] = mp[v[i]];
    nxt[n] = n+1;
    update(1, 1, n, v[n], {1, n});
    for (int i = n-1; i >= 1; --i){
        pi now = query(1, 1, n, v[i]+1, n);
        update(1, 1, n, v[i], {now.ff+1, i});
        nxt[i] = (now.ss == 0 ? n+1 : now.ss);
    }
    pi sol = query(1, 1, n, 1, n);
    fout << sol.ff << "\n";
    int I = sol.ss;
    while(I != n+1){
        fout << to[v[I]] << " ";
        I = nxt[I];
    }
    return 0;
}
