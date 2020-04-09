#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "cuplaje";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 200005;

int n, m, v1[nmax], v2[nmax];
vector<int> v[nmax];
set<int> s;


int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fin >> v1[i];
        v[v1[i]].push_back(i);
    }
    for (int i = 1; i <= m; ++i)
        fin >> v2[i];
    int sol = 0;
    for (int i = m; i >= 1; --i){
        for (auto x : v[i])
            s.insert(-x);
        if(s.empty())
            continue;
        set<int>::iterator it = s.lower_bound(-v2[i]);
        if(it == s.end())
            continue;
        ++sol;
        s.erase(it);
    }
    fout << sol;
    return 0;
}
