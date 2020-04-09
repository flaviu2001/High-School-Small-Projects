#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int inf = 2147483647, M = 1000000007;

int n, m, sb[100005], f[200005], d[200005], d2[200005], pd[100005], niv[200005];
vector<int> v[100005], vt[100005];
bool ok[100005];

void gcd(ll &x, ll &y, ll a, ll b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        ll aux = x;
        x = y;
        y = aux - 1ll*y*(a/b);
    }
}

int invers(ll x)
{
    ll a, b;
    gcd(a, b, x, M);
    if(a < 0)
        a = M+a%M;
    return a;
}

int comb(int x, int y)
{
    int ans = f[x];
    ans = (1ll*ans*invers(f[y]))%M;
    ans = (1ll*ans*invers(f[x-y]))%M;
    return ans;
}

int sbb(int x)
{
    return niv[d2[x]];
}

void dfs(int x)
{
    ok[x] = 0;
    int mn = inf, fii = v[x].size();
    for (auto y : v[x])
        mn = min(mn, d[y]);
    for (auto y : v[x])
        if(d[y] == mn && d2[x] < d2[y]){
            if(ok[y])
                dfs(y);
            int add = (1ll*f[sbb(x)-sbb(y)-fii]*comb(sbb(x), sbb(x)-sbb(y)-fii))%M;
            add = (1ll*add*f[fii-1])%M;
            add = (1ll*add*pd[y])%M;
            add = (1ll*add*comb(sbb(y)+fii, fii))%M;
            pd[x] = (pd[x]+add)%M;
        }
    if(pd[x] == 0)
        pd[x] = f[sbb(x)];
}

int main()
{
    ifstream fin ("shuffle2.in");
    ofstream fout ("shuffle2.out");
    f[0] = 1;
    for (int i = 1; i < 200005; ++i)
        f[i] = (1ll*f[i-1]*i)%M;
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        vt[y].push_back(x);
    }
    queue<int> q;
    q.push(n);
    ok[n] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (auto y : vt[x])
            if(!ok[y]){
                ok[y] = 1;
                d[y] = d[x]+1;
                q.push(y);
            }
    }
    memset(ok, 0, sizeof(ok));
    q.push(1);
    ok[1] = 1;
    d2[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        niv[d2[x]] += v[x].size();
        for (auto y : v[x])
            if(!ok[y]){
                ok[y] = 1;
                d2[y] = d2[x] + 1;
                q.push(y);
            }
    }
    for (int i = n-1; i >= 1; --i)
        niv[i] += niv[i+1];
    dfs(1);
    fout << pd[1] << "\n";
    return 0;
}
