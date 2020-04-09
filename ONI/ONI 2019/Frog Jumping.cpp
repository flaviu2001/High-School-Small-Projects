#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, a, b, pd[1000006], stop;
bool ok[1000006];

ll gauss(int x)
{
    return 1ll*x*(x+1)/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    cin >> n >> b >> a;//hack a == b
    int rem = max(a, b)/__gcd(a, b)+1;
    ok[0] = 1;
    priority_queue< pi, vector<pi>, greater<pi> > q;
    q.push({0, 0});
    while(!q.empty() && (rem || (rem == 0 && max(q.top().ff, q.top().ss) == stop))){
        pi now = q.top();
        q.pop();
        now.ss = max(now.ff, now.ss);
        ++pd[now.ss];
        if(now.ff <= max(a, b))
            --rem;
        if(rem == 0 && stop == 0)
            stop = now.ss;
        if(now.ff-a >= 0 && !ok[now.ff-a]){
            q.push({now.ff-a, now.ss});
            ok[now.ff-a] = 1;
        }
        if(!ok[now.ff+b]){
            q.push({now.ff+b, now.ss});
            ok[now.ff+b] = 1;
        }
    }
    for (int i = 1; i <= stop; ++i)
        pd[i] += pd[i-1];
    ll ans = 0;
    ans += gauss(n/__gcd(a, b))*__gcd(a, b);
    if(n%__gcd(a, b) != n-1)
        ans += ((n%__gcd(a, b))+1)*(n/__gcd(a, b)+1);
    //cout << ans << "\n";
    for (int i = 0; i <= min(n, stop); ++i)
        ans -= (i/__gcd(a, b)+1)-pd[i];
    //cout << stop << " " << pd[stop] << "\n";
    cout << ans << "\n";
    return 0;
}