#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "praslea";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

struct thing{
    int t, tip, f, r;
};

int n, R, pd[520][520];
ll sol;
thing e[1500];
multiset<pi> s;
map< int, vector<thing> > mp;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> R;
    for (int i = 1; i <= n; ++i){
        int t1, t2, f, r;
        fin >> t1 >> t2 >> f >> r;
        ++t2;
        e[i*2-1] = {t1, 0, f, r};
        e[i*2] = {t2, 1, f, r};
        mp[t1].push_back(e[i*2-1]);
        mp[t2].push_back(e[i*2]);
    }
    int last = -1, last2 = -1;
    for (auto vv : mp){
        for (auto x : vv.ss){
            if(x.tip == 0)
                s.insert({x.f, x.r});
            else s.erase(s.find({x.f, x.r}));
        }
        memset(pd, 0, sizeof(pd));
        int i = 0;
        for (auto x : s){
            ++i;
            for (int j = 0; j <= R; ++j)
                if(x.ss <= j)
                    pd[i][j] = max(pd[i-1][j-x.ss] + x.ff, pd[i-1][j]);
                else pd[i][j] = pd[i-1][j];
        }
        int val = pd[s.size()][R];
        if(last != -1)
            sol += 1ll*last2*(vv.ff-last);
        last = vv.ff;
        last2 = val;
    }
    fout << sol << "\n";
    return 0;
}
