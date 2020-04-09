#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, M = 1000000007, nmax = 200005;

struct nod{
    int x, c;
    bool operator<(const nod &obj)const{
        return c < obj.c;
    }
};

int n, c[nmax], mx, C[nmax], rng[nmax];
pair<int, int> pd[nmax];
nod e[nmax];
int *v[nmax];
bool ok[nmax];

template <typename T,typename U>
pair<T,U> operator*(const pair<T,U> & l,const pair<T,U> & r) {
    return {(1ll*l.ff*r.ff+1ll*l.ss*r.ss)%M, (1ll*l.ff*r.ss+1ll*l.ss*r.ff)%M};
}

template <typename T,typename U>
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {
    return {(l.ff+r.ff)%M, (l.ss+r.ss)%M};
}

template <typename T,typename U>
pair<T,U> operator-(const pair<T,U> & l,const pair<T,U> & r) {
    return {(l.ff-r.ff+M)%M, (l.ss-r.ss+M)%M};
}

int find(int x)
{
    if(x == C[x])
        return x;
    x = find(C[x]);
    return x;
}

void unite(int x, int y)
{
    if(x == y)
        return;
    if(rng[x] > rng[y])
        C[y] = x;
    else C[x] = y;
    if(rng[x] == rng[y])
        ++rng[y];
}

int solve(int pw)
{
    for (int i = 1; i <= n; ++i)
        C[i] = i, rng[i] = 1;
    memset(ok, 0, sizeof(ok));
    int sol = 0;
    for (int t = n; t >= 1; --t){
        int x = e[t].x;
        ok[x] = 1;
        pair<int, int> all = {1, 0}, ex = {1, 0};
        for (int i = 1; i <= v[x][0]; ++i)
            if(ok[v[x][i]]){
                pair<int, int> now = pd[find(v[x][i])];
                sol = (sol+now.ss)%M;
                all = all*now;
                ex = ex + now - make_pair(1, 0);
            }
        if((c[x]&pw) == 0)
            pd[x] = all+all;
        else pd[x] = {(all.ff+all.ss)%M, (all.ff+all.ss)%M};
        all = all-ex;
        if((c[x]&pw) == 0)
            sol = (1ll*sol+2ll*all.ss)%M;
        else sol = (1ll*sol+all.ss+all.ff)%M;
        for (int i = 1; i <= v[x][0]; ++i)
            if(ok[v[x][i]]){
                unite(find(x), find(v[x][i]));
                pd[find(x)] = pd[x];
            }
    }
    return (1ll*pw*sol)%M;
}

int main()
{
    ifstream fin ("countfefete.in");
    ofstream fout ("countfefete.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> c[i];
        e[i] = {i, c[i]};
        mx = max(mx, c[i]);
        v[i] = (int*)realloc(v[i], sizeof(int));
        v[i][0] = 0;
    }
    sort(e+1, e+n+1);
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        ++v[x][0];
        ++v[y][0];
        v[x] = (int*)realloc(v[x], (v[x][0]+1)*sizeof(int));
        v[y] = (int*)realloc(v[y], (v[y][0]+1)*sizeof(int));
        v[x][v[x][0]] = y;
        v[y][v[y][0]] = x;
    }
    int pw = 1, ans = 0;
    while(pw <= mx){
        ans = (ans+solve(pw))%M;
        pw *= 2;
    }
    fout << ans << "\n";
    return 0;
}
