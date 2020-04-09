#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;

struct thing{
    int val, i;
    bool x;
    bool operator<(const thing &obj)const{
        return val < obj.val;
    }
};

const int nmax = 200005;
int n, T, p, dep[nmax], e[nmax*2], first[nmax], lg2[nmax*2], col[nmax], last[nmax];
vector<int> v[nmax];
pair<int, int> pd[19][nmax*2];
vector<thing> r[nmax];

thing mkt(int val, int i, bool x)
{
    thing aux;
    aux.val = val;
    aux.i = i;
    aux.x = x;
    return aux;
}

void dfs(int x, int pred = 0)
{
    dep[x] = dep[pred]+1;
    ++p;
    e[p] = x;
    first[x] = p;
    for (auto y : v[x])
        if(y != pred){
            dfs(y, x);
            e[++p] = x;
        }
}

int query(int x, int y)
{
    if (x == y)
        return x;
    if(first[x] > first[y])
        swap(x, y);
    int sz = lg2[first[y]-first[x]];
    return min(pd[sz][first[x]].ss, pd[sz][first[y]-(1<<sz)].ss);
}

ll solve(vector<thing> &w)
{
    ll sol = 0;
    if(w.size() <= 1)
        return 0;
    int sz = w.size(), all;
    int pr[sz+2];
    pr[0] = w[0].x;
    for (int i = 1; i < sz; ++i)
        pr[i] = pr[i-1]+w[i].x;
    all = pr[sz-1];
    for (auto x : w)
        if(x.x)
            sol += x.val*(all-1);
    int rgt[sz+2], lft[sz+2], st[sz+2], vf = 0;
    rgt[sz-1] = sz;
    st[++vf] = sz-1;
    for (int i = sz-2; i >= 0; --i){
        while(vf > 0 && w[i].val <= w[st[vf]].val)
            --vf;
        if(vf == 0)
            rgt[i] = sz;
        else rgt[i] = w[st[vf]].i;
        st[++vf] = i;
    }
    vf = 0;
    lft[0] = -1;
    st[++vf] = 0;
    for (int i = 1; i < sz; ++i){
        while(vf > 0 && w[i].val < w[st[vf]].val)
            --vf;
        if(vf == 0)
            lft[i] = -1;
        else lft[i] = w[st[vf]].i;
        st[++vf] = i;
    }
    ll lca = 0;
    for (auto x : w){
        ll lo = lft[x.i]+1, hi = rgt[x.i]-1;
        lca += 1ll*x.val*(x.i == 0 ? 0 : (pr[x.i-1]-(lo == 0 ? 0 : pr[lo-1])))*(pr[hi]-pr[x.i]);
        if(x.x)
            lca += 1ll*x.val*(pr[hi]-pr[lo]);
    }
    lca *= 2;
    sol -= lca;
    return sol;
}

int main()
{
    ifstream fin ("kdist.in");
    ofstream fout ("kdist.out");
    fin >> n >> T;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    lg2[1] = 0;
    for (int i = 2; i < nmax*2; ++i)
        lg2[i] = lg2[i/2]+1;
    for (int i = 1; i < p; ++i){
        pd[0][i] = {e[i], dep[e[i]]};
        if(dep[e[i]] > dep[e[i+1]])
            pd[0][i] = {e[i+1], dep[e[i+1]]};
    }
    for (int t = 1; t <= lg2[p-1]; ++t)
        for (int i = 1; i <= p-(1<<t); ++i)
            if(pd[t-1][i].ss < pd[t-1][i+(1<<(t-1))].ss)
                pd[t][i] = pd[t-1][i];
            else pd[t][i] = pd[t-1][i+(1<<(t-1))];
    for (int i = 1; i <= n; ++i)
        fin >> col[i];
    for (int i = 1; i <= p; ++i)
        if(last[col[e[i]]] == 0){
            r[col[e[i]]].push_back(mkt(dep[e[i]], 0, 1));
            last[col[e[i]]] = i;
        }else if(i == first[e[i]]){
            if(i-1 != first[e[i-1]] || col[e[i-1]] != col[e[i]]){
                int in = r[col[e[i]]].size();
                r[col[e[i]]].push_back(mkt(query(e[last[col[e[i]]]], e[i]), in, false));
            }
            int in = r[col[e[i]]].size();
            r[col[e[i]]].push_back(mkt(dep[e[i]], in, true));
            last[col[e[i]]] = i;
        }
    for (int i = 1; i <= T; ++i)
        fout << solve(r[i]) << "\n";
    return 0;
}
