#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const ll nmax = 10000007, tmax = 70005;
ll n, m, k, M, A[tmax], B[tmax], v[nmax], lft[nmax], rgt[nmax];
 
int main()
{
    ifstream fin ("cia.in");
    ofstream fout ("cia.out");
    fin >> n >> m >> k >> M;
    for (int i = 0; i < m; ++i)
        fin >> A[i];
    for (int i = 0; i < m; ++i)
        fin >> B[i];
    for (int i = 0; i < n; ++i)
        v[i+1] = (A[i%m] ^ B[i/m])%M;
    memset(lft, 1, sizeof(lft));
    memset(rgt, 1, sizeof(rgt));
    for (int i = n-n%k; i >= 1; --i)
        if(i%k == 0)
            lft[i] = v[i];
        else lft[i] = (1ll*lft[i+1]*v[i])%M;
    for (int i = k; i <= n; ++i)
        if(i%k == 0)
            rgt[i] = 1;
        else rgt[i] = (1ll*rgt[i-1]*v[i])%M;
    ll st = 1, dr = k, ans = 0;
    while(dr <= n){
        ans ^= (1ll*lft[st]*rgt[dr])%M;
        ++st;
        ++dr;
    }
    fout << ans << "\n";
    return 0;
}
