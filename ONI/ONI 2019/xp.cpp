#pragma gcc optimize ("Ofast")
#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "xp";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, nmax = 2005;

int n, a, b, A, B, V, g[nmax], st[nmax], dr[nmax], sq, sq_, P, M, v[nmax+5], st2[nmax+5], dr2[nmax+5];

int grup(int i)
{
    return (i+sq_)/sq;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> a >> b >> P >> M; sq = sqrt(n), sq_ = sq-1; A = a, B = b;
    for (int i = 0; i < nmax; ++i)
        g[i] = 1;
    V = max(1, (1^(((a+1)&(b+1))%P))%P);
    g[1] = V;
    for (int i = 2; i <= n; ++i){
        int na, nb;
        na = ((a+P-1)^(b+1))%P;
        nb = ((a+P-1)|(b+1))%P;
        a = na;
        b = nb;
        V = max(1, ((i%P)^(((a+1)&(b+1))%P))%P);
        g[grup(i)] = (1ll*g[grup(i)]*V)%M;
    }
    st[0] = 1;
    for (int i = 1; i <= grup(n); ++i)
        st[i] = (1ll*st[i-1]*g[i])%M;
    dr[grup(n)+1] = 1;
    for (int i = grup(n); i >= 1; --i)
        dr[i] = (1ll*dr[i+1]*g[i])%M;
    int ans = 0, l = 1, r = sq, guy;
    a = A, b = B;
    while(l <= n){
        v[1] = max(1, ((l%P)^(((a+1)&(b+1))%P))%P);
        r = min(r, n);
        for (int i = l+1; i <= r+1; ++i){
            int na, nb;
            na = ((a+P-1)^(b+1))%P;
            nb = ((a+P-1)|(b+1))%P;
            a = na;
            b = nb;
            v[i-l+1] = max(1, ((i%P)^(((a+1)&(b+1))%P))%P);
        }
        st2[0] = 1;
        for (int i = l; i <= r; ++i)
            st2[i-l+1] = (1ll*st2[i-l+1-1]*v[i-l+1])%M;
        dr2[r-l+1+1] = 1;
        for (int i = r; i >= l; --i)
            dr2[i-l+1] = (1ll*dr2[i-l+1+1]*v[i-l+1])%M;
        for (int i = l; i <= r; ++i)
            ans = ((1ll*((1ll*((1ll*st[grup(l)-1]*dr[grup(r)+1])%M)*st2[i-l])%M)*dr2[i-l+2])%M)^ans;
        l += sq;
        r += sq;
    }
    fout << ans << "\n";
    return 0;
}
