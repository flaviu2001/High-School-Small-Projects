#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "rascoala";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 505;

ll test, n, m, k, v[nmax][nmax];
bool ok[nmax][nmax];
vector<pi> guys[1200006];

bool check(ll lim)
{
    ll now = 0;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= m; ++j)
            if(v[i][j] < lim)
                now += lim-v[i][j];
    return now <= k;
}

int dist(pi a, pi b)
{
    return abs(a.ff-b.ff)+abs(a.ss-b.ss);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test >> n >> m >> k;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= m; ++j){
            fin >> v[i][j];
            guys[v[i][j]].push_back({i, j});
        }
    ll st = 1, dr = 2000000000, mid, ans = -1;
    for (mid = (st+dr)/2; st <= dr; mid = (st+dr)/2)
        if(check(mid)){
            ans = mid;
            st = mid+1;
        }else dr = mid-1;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= m; ++j)
            if(v[i][j] < ans){
                k -= ans-v[i][j];
                ok[i][j] = 1;
                v[i][j] = ans;
            }
    for (int t = 1; t <= 1000000 && k; ++t)
        for (int i = 0; i < guys[t].size() && k; ++i){
            --k;
            ok[guys[t][i].ff][guys[t][i].ss] = 1;
        }
    ll many = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            many += ok[i][j];
    if(test == 1)
        fout << many << "\n" << ans << "\n";
    else{
        pi N = {0, 0}, e, s, w;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if(ok[i][j]){
                    if(N.ff == 0)
                        N = e = s = w = {i, j};
                    else{
                        if(i+j > N.ff+N.ss)
                            N = {i, j};
                        if(i-j > e.ff-e.ss)
                            e = {i, j};
                        if(-i+j > -s.ff+s.ss)
                            s = {i, j};
                        if(-i-j > -w.ff-w.ss)
                            w = {i, j};
                    }
                }
        int ans2 = dist(N, e);
        ans2 = max(ans2, dist(N, s));
        ans2 = max(ans2, dist(N, w));
        ans2 = max(ans2, dist(e, s));
        ans2 = max(ans2, dist(e, w));
        ans2 = max(ans2, dist(s, w));
        fout << ans2 << "\n";
    }
    return 0;
}
