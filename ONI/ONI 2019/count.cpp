#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "count";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, m;
vector<pi> e;
vector<int> v[30005];
unordered_set<int> s[30005];

int count4()
{
    int ans = 0;
    for (auto x : e){
        int a = x.ff, b = x.ss;
        if(v[a].size() > v[b].size())
            swap(a, b);
        vector<int> r;
        for (auto y : v[a])
            if(s[b].find(y) != s[b].end())
                r.push_back(y);
        for (vector<int>::iterator it = r.begin(); it < r.end(); ++it)
            for (vector<int>::iterator it2 = it+1; it2 < r.end(); ++it2)
                if(s[*it].find(*it2) != s[*it].end())
                    ++ans;
    }
    return ans;
}

int count3()
{
    int ans = 0;
    for (auto x : e){
        int a = x.ff, b = x.ss;
        if(v[a].size() > v[b].size())
            swap(a, b);
        for (auto y : v[a])
            if(s[b].find(y) != s[b].end())
                ++ans;
    }
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        s[x].insert(y);
        s[y].insert(x);
        e.push_back({min(x, y), max(x, y)});
    }
    int ans = 0;
    ans = count4();
    if(ans != 0)
        fout << "4 " << ans/6 << "\n";
    else if(ans = count3())
        fout << "3 " << ans/3 << "\n";
    else fout << "2 " << m << "\n";
    return 0;
}
