#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 65537;

int n, m, h, w, t;
vector<pi> mp[M+3];

int hsh(int x, int y)
{
    return (x*31+y)%M;
}

bool inside(int X, int Y, int x, int y)
{
    if(X < 0 || Y < 0)
        return 0;
    for (auto z : mp[hsh(X, Y)])
        if(x >= z.ff && x <= z.ff+h && y >= z.ss && y <= z.ss+w)
            return 1;
    return 0;
}

int main()
{
    ifstream fin ("ograzi.in");
    ofstream fout ("ograzi.out");
    fin >> n >> m >> h >> w;
    for (int i = 1; i <= n; ++i){
        int x, y, X, Y;
        fin >> x >> y;
        X = x/h;
        Y = y/w;
        mp[hsh(X, Y)].push_back({x, y});
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i){
        int x, y, X, Y;
        fin >> x >> y;
        X = x/h;
        Y = y/w;
        if (inside(X, Y, x, y))
            ++ans;
        else if (inside(X-1, Y, x, y))
            ++ans;
        else if (inside(X, Y-1, x, y))
            ++ans;
        else if (inside(X-1, Y-1, x, y))
            ++ans;
    }
    fout << ans << "\n";
    return 0;
}
