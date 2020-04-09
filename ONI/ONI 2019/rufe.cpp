#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "rufe";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

ll n, m, a, b, k;

ll gauss(ll x)
{
    return 1ll*x*(x+1)/2;
}

ll f(ll d)
{
    ll sum = min(a-1, d)+min(n-a, d)+min(b-1, d)+min(m-b, d)+1;
    ll meet = d-b+1;
    if(meet > 1)
        sum += (min(meet-1, min(d-1, a-1)))*(b-1);
    sum += gauss(min(d-1, b-1))-gauss(min(b-1, d-(min(d-1, a-1)+1)));
    meet = d-m+b;
    if(meet > 1)
        sum += (min(meet-1, min(d-1, a-1)))*(m-b);
    sum += gauss(min(d-1, m-b))-gauss(min(m-b, d-(min(d-1, a-1)+1)));
    meet = d-b+1;
    if(meet > 1)
        sum += (min(meet-1, min(d-1, n-a)))*(b-1);
    sum += gauss(min(d-1, b-1))-gauss(min(b-1, d-(min(d-1, n-a)+1)));
    meet = d-m+b;
    if(meet > 1)
        sum += (min(meet-1, min(d-1, n-a)))*(m-b);
    sum += gauss(min(d-1, m-b))-gauss(min(m-b, d-(min(d-1, n-a)+1)));
    return sum;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> a >> b >> k;
    ll st = 0, dr = n+m+1, mid, ans = 0;
    for (mid = (st+dr)/2; st <= dr; mid = (st+dr)/2)
        if(n*m-f(mid) >= k){
            ans = mid+1;
            st = mid+1;
        }else dr = mid-1;
    fout << ans << "\n";
    return 0;
}
