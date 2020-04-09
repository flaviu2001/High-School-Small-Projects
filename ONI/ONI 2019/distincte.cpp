#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct tst{
    ll r, i;
};

const ll M = 666013;
ll n, m, test, aib[100005], v[100005], b[100005], last[100005], ans[100005], r[100005];
vector<tst> q[100005];

void update(ll idx, ll val)
{
    while(idx <= n){
        aib[idx] += val;
        idx += (idx & (-idx));
    }
}

ll read(ll idx)
{
    ll sum = 0;
    while(idx){
        sum += aib[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main()
{
    ifstream fin ("distincte.in");
    ofstream fout ("distincte.out");
    fin >> n >> m >> test;
    for (ll i = 1; i <= n; ++i){
        fin >> v[i];
        b[i] = last[v[i]];
        r[b[i]] = i;
        if(b[i] == 0)
            update(i, v[i]);
        last[v[i]] = i;
    }
    for (ll t = 1; t <= test; ++t){
        ll l, r;
        fin >> l >> r;
        q[l].push_back({r, t});
    }

    for (ll t = 1; t <= n; ++t){
        if(t != 1 && r[t-1] != 0)
            update(r[t-1], v[r[t-1]]);
        for (auto Q : q[t])
            ans[Q.i] = read(Q.r)-read(t-1);
    }
    for (ll i = 1; i <= test; ++i)
        fout << ans[i]%M << "\n";
    return 0;
}
