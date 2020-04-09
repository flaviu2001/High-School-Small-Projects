#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1000006;

struct rect{
    ll x, y, a;
    bool operator<(const rect &obj)const{
        return x < obj.x;
    }
};

struct line{
    ll a, b;
    bool operator<(const line &obj)const{
        if(a != obj.a)
            return a < obj.a;
        return b > obj.b;
    }
};

ll n, pd[nmax];
rect m[nmax];
vector<line> s;

ld intersect(line x, line y)
{
    return ld(y.b-x.b)/(x.a-y.a);
}

bool check(line x, line y, line z)
{
    return intersect(x, y) >= intersect(x, z);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    cin >> n;
    for (ll i = 1; i <= n; ++i)
        cin >> m[i].x >> m[i].y >> m[i].a;
    sort(m+1, m+n+1);
    pd[1] = m[1].x*m[1].y-m[1].a;
    s.push_back({m[1].x, pd[1]});
    ll pointer = 0;
    for (ll i = 2; i <= n; ++i){
        pd[i] = m[i].x*m[i].y-m[i].a;
        pointer = min(pointer, max(ll(s.size())-2, 0ll));
        while(pointer < ll(s.size())-1 && 1ll*s[pointer].a*-m[i].y+s[pointer].b < 1ll*s[pointer+1].a*-m[i].y+s[pointer+1].b)
            ++pointer;
        pd[i] += max(0ll, 1ll*s[pointer].a*-m[i].y+s[pointer].b);
        while(s.size() > 1 && check(s[s.size()-2], s[s.size()-1], {m[i].x, pd[i]}))
            s.pop_back();
        s.push_back({m[i].x, pd[i]});
        pd[i] = max(pd[i], pd[i-1]);
    }
    cout << pd[n];
    return 0;
}
