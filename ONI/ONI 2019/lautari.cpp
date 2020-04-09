#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;

const string file = "lautari";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, p, q, v[nmax], aib[nmax], nxt[nmax], last[nmax];

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

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> p >> q;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = n; i >= 1; --i){
        if(last[v[i]] != 0)
            nxt[i] = last[v[i]];
        last[v[i]] = i;
    }
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= n; ++i){
        if(last[v[i]] == 0)
            update(i, 1);
        last[v[i]] = i;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        int ans1 = -1, ans2 = -1;
        int st = i, dr = n, m;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(read(m)-read(i-1) >= p){
                ans1 = m;
                dr = m-1;
            }else st = m+1;
        st = i, dr = n;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(read(m)-read(i-1) <= q){
                ans2 = m;
                st = m+1;
            }else dr = m-1;
        if(ans2 != -1 && ans1 != -1 && ans2-ans1+1 >= 1)
            ans += ans2-ans1+1;
        if(nxt[i] != 0)
            update(nxt[i], 1);
    }
    fout << ans << "\n";
    return 0;
}
