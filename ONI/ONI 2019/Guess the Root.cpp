#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 1000003;

set<ll> s;
ll n = 50, m = 11, v[105][105], val[105];

long long rand_seed()
{
	long long a = rng();
    return a;
}

ll pw(ll x, ll y)
{
    ll p = 1;
    while(y)
        if(y%2)
            p = (1ll*p*x)%M, --y;
        else x = (1ll*x*x)%M, y /= 2;
    return p;
}

ll invers(ll x)
{
    return pw(x, M-2);
}

bool check()
{
    for (int i = 1; i <= n; ++i){
        ll now = 0;
        for (int j = 1; j <= m; ++j)
            now = (now+1ll*v[i][j]*val[j])%M;
        if(now-v[i][m+1] != 0)
            return false;
    }
    return true;
}

ll eval(ll x)
{
    ll now = 0;
    for (int i = 1; i <= 11; ++i)
        now = (now+val[i]*pw(x, i-1))%M;
    return now;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    while(s.size() < 50){
        ll x = rand_seed()%M;
        s.insert(x);
    }
    ll cnt = 0;
    for (auto x : s){
        cout << "? " << x << endl;
        ++cnt;
        for (ll i = 0; i <= 10; ++i)
            v[cnt][i+1] = pw(x, i);
        cin >> v[cnt][m+1];
    }
    ll a = 1, b = 1;
    while(a <= n && b <= m){
        ll first = -1;
        for (ll i = a; i <= n; ++i)
            if(v[i][b] != 0){
                first = i;
                break;
            }
        if(first == -1){
            ++b;
            continue;
        }
        for (int j = 1; j <= m+1; ++j)
            swap(v[a][j], v[first][j]);
        for (int j = b+1; j <= m+1; ++j)
            v[a][j] = (1ll*v[a][j]*invers(v[a][b]))%M;
        v[a][b] = 1;
        for (int i = a+1; i <= n; ++i){
            ll x = v[i][b];
            for (int j = 1; j <= m+1; ++j)
                v[i][j] = ((v[i][j] - x*v[a][j])%M+M)%M;
        }
        ++a, ++b;
    }
    --a;
    while(a >= 1){
        b = -1;
        for (int j = 1; j <= m; ++j)
            if(v[a][j] != 0){
                b = j;
                break;
            }
        if(b == -1){
            if(v[a][m+1] == 0)
                continue;
            else
                break;
        }
        ll now = v[a][m+1];
        for (int j = b+1; j <= m; ++j)
            now = ((now-1ll*v[a][j]*val[j])%M+M)%M;
        val[b] = now;
        --a;
    }
    if(!check())
        return 0;
    ll now = -1;
    for (ll i = 0; i < M; ++i)
        if(eval(i) == 0){
            now = i;
            break;
        }
    if(now == -1)
        cout << "! -1" << endl;
    else cout << "! " << now << endl;
    return 0;
}