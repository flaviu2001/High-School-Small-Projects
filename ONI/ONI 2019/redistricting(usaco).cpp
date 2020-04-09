#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "redistricting";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

vector<pi> v[300005];
deque<pi> dq[300005];
int n, k, pd[300005], prh[300005], prg[300005], last[300005], start[300005], mod[300005];
char c[300005];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> k >> (c+1);
    for (int i = 1; i <= n; ++i){
        prh[i] = prh[i-1];
        prg[i] = prg[i-1];
        if(c[i] == 'H')
            ++prh[i];
        else ++prg[i];
    }
    v[0].push_back({0, 0});
    dq[0].push_back({0, 0});
    for (int i = 1; i <= n; ++i){
        int h = 0, g = 0;
        int st = max(i-k, 0);
        h = prh[i]-prh[last[pd[st]]];
        g = prg[i]-prg[last[pd[st]]];
        mod[pd[st]] += g-h;
        while(start[pd[st]] < v[pd[st]].size() && v[pd[st]][start[pd[st]]].ff < st)
            ++start[pd[st]];
        while(!dq[pd[st]].empty() && dq[pd[st]].front().ff < st)
            dq[pd[st]].pop_front();
        int mn = inf;
        if(!dq[pd[st]].empty())
            mn = dq[pd[st]].front().ss;
        last[pd[st]] = i;
        if(mn != inf)
            pd[i] = pd[st]+(mn+mod[pd[st]] >= 0);
        if(pd[st] > 0 && start[pd[st]-1] < v[pd[st]-1].size()){
            h = prh[i]-prh[last[pd[st]-1]];
            g = prg[i]-prg[last[pd[st]-1]];
            mod[pd[st]-1] += g-h;
            while(start[pd[st]-1] < v[pd[st]-1].size() && v[pd[st]-1][start[pd[st]-1]].ff < st)
                ++start[pd[st]-1];
            while(!dq[pd[st]-1].empty() && dq[pd[st]-1].front().ff < st)
                dq[pd[st]-1].pop_front();
            mn = inf;
            if(!dq[pd[st]-1].empty())
                mn = dq[pd[st]-1].front().ss;
            last[pd[st]-1] = i;
            if(mn != inf)
                pd[i] = min(pd[i], pd[st]-1+(mn+mod[pd[st]-1] >= 0));
        }else last[pd[st]-1] = i;
        if(start[pd[i]] < v[pd[i]].size()){
            h = prh[i]-prh[last[pd[i]]];
            g = prg[i]-prg[last[pd[i]]];
            mod[pd[i]] += g-h;
            last[pd[i]] = i;
        }
        v[pd[i]].push_back({i, -mod[pd[i]]});
        while(!dq[pd[i]].empty() && dq[pd[i]].back().ss >= -mod[pd[i]])
            dq[pd[i]].pop_back();
        dq[pd[i]].push_back({i, -mod[pd[i]]});
    }
    fout << pd[n] << "\n";
    return 0;
}
