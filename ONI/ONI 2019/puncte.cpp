#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "puncte";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

struct line{
    ll a, b;
} v[nmax];

ll n, m, ans[nmax*2];
vector<line> s;
pi e[nmax*2];

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
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (ll i = 1; i <= n; ++i){
        ll a, b;
        fin >> a >> b;
        v[i].a = -2*a;
        v[i].b = a*a+b*b;
    }
    s.push_back(v[1]);
    for (ll i = 2; i <= n; ++i){
        if(v[i].a == s.back().a)
            continue;
        while(s.size() > 1 && check(s[s.size()-2], s[s.size()-1], v[i]))
            s.pop_back();
        s.push_back(v[i]);
    }
    for (ll t = 1; t <= m; ++t){
        fin >> e[t].ff;
        e[t].ss = t;
    }
    sort(e+1, e+m+1);
    unsigned pointer = 0;
    for (ll t = 1; t <= m; ++t){
        while(pointer+1 < s.size() && s[pointer].a*e[t].ff+s[pointer].b > s[pointer+1].a*e[t].ff+s[pointer+1].b)
            ++pointer;
        ans[e[t].ss] = s[pointer].a*e[t].ff+s[pointer].b+1ll*e[t].ff*e[t].ff;
    }
    for (ll i = 1; i <= m; ++i)
        fout << ans[i] << "\n";
    return 0;
}
