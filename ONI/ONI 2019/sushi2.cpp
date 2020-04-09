#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "sushi2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 200005;

int n, m, p1[nmax*4], p2[nmax*4], last[nmax], nxt[nmax*4], c[nmax], aint[nmax*8];
vector<int> v[nmax];
unordered_map<int, int> where[nmax], ok, qr;
bool vis[nmax];

void update(int nod, int st, int dr, int pos, int val)
{
    if(st == dr)
        aint[nod] = max(aint[nod], val);
    else{
        int mid = (st+dr)/2;
        if(mid >= pos)
            update(nod*2, st, mid, pos, val);
        else update(nod*2+1, mid+1, dr, pos, val);
        aint[nod] = max(aint[nod*2], aint[nod*2+1]);
    }
}

int query(int nod, int st, int dr, int l, int r)
{
    if(l > r)
        return -inf;
    if(st >= l && dr <= r)
        return aint[nod];
    int mid = (st+dr)/2, ans=-inf;
    if(mid >= l)
        ans = query(nod*2, st, mid, l, r);
    if(mid+1 <= r)
        ans = max(ans, query(nod*2+1, mid+1, dr, l, r));
    return ans;
}

int main()
{
    ifstream fin ("sushi2.in");
    ofstream fout ("sushi2.out");
    fin >> n >> m;
    for (int i = 1; i < nmax*8; ++i)
        aint[i] = -inf;
    for (int i = 1; i <= n; ++i){
        int sz;
        fin >> sz;
        for (int j = 0; j < sz; ++j){
            int x;
            fin >> x;
            v[i].push_back(x);
            where[i][x] = j;
        }
    }
    int x = 1, y = 0, vf = 0;
    while (1){
        ok[x*1000000+y] = 1;
        p2[vf] = x*1000000+y;
        p1[vf++] = x;
        int to = where[v[x][y]][x]+1;
        if(to == v[v[x][y]].size())
            to = 0;
        x = v[x][y];
        y = to;
        if(ok[x*1000000+y] == 1)
            break;
    }
    for (int i = vf; i < vf*2; ++i){
        p1[i] = p1[i-vf];
        p2[i] = p2[i-vf];
    }
    vf *= 2;
    for (int i = vf-1; i >= 0; --i){
        nxt[i] = last[p1[i]];
        last[p1[i]] = i;
    }
    for (int i = 1; i <= m; ++i){
        int x, y, t;
        fin >> x >> y >> t; --y;
        qr[x*1000000+y] = max(qr[x*1000000+y], t);
    }
    int mx = -inf, I = 0, add;
    vector<pi> bag;
    for (int t = 0; t < vf/2; ++t){
        if(qr.find(p2[t]) != qr.end()){
            int now = qr[p2[t]]-t;
            if(now > mx){
                add = now+t;
                mx = now;
                I = t;
            }
            update(1, 1, vf, t+1, now);
        }
        bag.push_back({p1[t], t});
    }
    for (int i = 0; i < vf/2; ++i)
        if(!vis[p1[i+I]]){
            vis[p1[i+I]] = 1;
            c[p1[i+I]] = max(c[p1[i+I]], i+add);
        }
    for (auto x : bag)
        c[x.ff] = max(c[x.ff], nxt[x.ss]+query(1, 1, vf, x.ss+2, nxt[x.ss]));
    for (int i = 1; i <= n; ++i)
        fout << c[i] << " ";
    return 0;
}
