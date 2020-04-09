#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define INF 1LL<<60-1

using namespace std;

vector< pair<ll, ll> > ducks, walls, e;
ll n, m, sol, l[1005], r[1005];

ll cp(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    return (a.first - c.first) * (b.second - c.second) - (a.second-c.second) * (b.first - c.first);
}

ll find_min_pos(pair<ll, ll> duck, vector < pair<ll, ll> > s)
{
    if(duck.second <= s[0].second)
        return INF;
    double x = (s[0].first * duck.second - duck.first * s[0].second) * 1.0 / (duck.second - s[0].second);
    return (fabs(x) - (ll)x <= 1e-6) ? x : x + 1.0;
}

ll find_max_pos(pair<ll, ll> duck, vector < pair<ll, ll> > s)
{
    if(duck.second <= s[0].second)
        return -INF;
    double x = (s[0].first * duck.second - duck.first * s[0].second) * 1.0 / (duck.second - s[0].second);
    return x;
}

bool cmp (pair<ll, ll> e1, pair<ll, ll> e2)
{
    if(e1.first == e2.first)
        return e1.second > e2.second;
    return e1.first < e2.first;
}

int main()
{
    ifstream fin ("elmer.in");
    ofstream fout ("elmer.out");
    fin >> n;
    for (int i = 0; i < n; ++i){
        ll x, y;
        fin >> x >> y;
        ducks.push_back(make_pair(x, y));
    }
    walls.push_back(make_pair(0, 0));
    fin >> m;
    for (int i = 0; i < m; ++i){
        ll x, h;
        fin >> x >> h;
        walls.push_back(make_pair(x, h));
    }
    m += 2;
    walls.push_back(make_pair(INF, 0));

    sort(ducks.begin(), ducks.end());
    sort(walls.begin(), walls.end());
    for (int i = 0; i < n; ++i){
        pair<ll, ll> duck = ducks[i];
        ll lb = lower_bound(walls.begin(), walls.end(), duck)-walls.begin();
        vector< pair<ll, ll > > s;
        for (ll j = lb; j < m; ++j){
            pair<ll, ll> wall = walls[j];
            while(!s.empty() && cp(duck, s.back(), wall) >= 0)
                s.pop_back();
            s.push_back(wall);
            l[j] = find_min_pos(duck, s);
            r[j] = INF-1;
        }
        s.clear();
        for (ll j = lb-1; j >= 0; --j){
            pair<ll, ll> wall = walls[j];
            while(!s.empty() && cp(duck, s.back(), wall) <= 0)
                s.pop_back();
            s.push_back(wall);
            l[j] = -INF + 1;
            r[j] = find_max_pos(duck, s);
        }
        for (int j = 0; j+1 < m; ++j){
            ll l1, r1;
            l1 = max(walls[j].first+1, l[j]);
            r1 = min(walls[j+1].first-1, r[j+1]);
            if(l1 <= r1){
                e.push_back(make_pair(l1, 1));
                e.push_back(make_pair(r1, -1));
            }
        }
    }
    sort(e.begin(), e.end(), cmp);
    int hit = 0;
    for (unsigned i = 0; i < e.size(); ++i){
        hit += e[i].second;
        sol = max(sol, (ll) hit);
    }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}
