#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "drept2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 2000105;

int n, m, a, b;
pi v[nmax];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> a >> b;
    swap(n, m);
    v[0].ss = -1;
    for (int i = 1; i <= n; ++i){
        fin >> v[i].ff >> v[i].ss;
        v[i].ss += v[i-1].ss-v[i-1].ff+v[i].ff;
    }
    ll sol = 0;
    deque<int> dmn, dmx;
    for (int i = 1; i <= n; ++i){
        if(!dmn.empty() && i-dmn.front() == a)
            dmn.pop_front();
        if(!dmx.empty() && i-dmx.front() == a)
            dmx.pop_front();
        while(!dmn.empty() && v[dmn.back()].ss >= v[i].ss)
            dmn.pop_back();
        while(!dmx.empty() && v[dmx.back()].ff <= v[i].ff)
            dmx.pop_back();
        dmn.push_back(i);
        dmx.push_back(i);
        if(i >= a)
            sol += max(0, v[dmn.front()].ss-v[dmx.front()].ff-b+2);
    }
    if(a != b){
        dmn.clear();
        dmx.clear();
        for (int i = 1; i <= n; ++i){
            if(!dmn.empty() && i-dmn.front() == b)
                dmn.pop_front();
            if(!dmx.empty() && i-dmx.front() == b)
                dmx.pop_front();
            while(!dmn.empty() && v[dmn.back()].ss >= v[i].ss)
                dmn.pop_back();
            while(!dmx.empty() && v[dmx.back()].ff <= v[i].ff)
                dmx.pop_back();
            dmn.push_back(i);
            dmx.push_back(i);
            if(i >= b)
                sol += max(0, v[dmn.front()].ss-v[dmx.front()].ff-a+2);
        }
    }
    fout << sol << "\n";
    return 0;
}
