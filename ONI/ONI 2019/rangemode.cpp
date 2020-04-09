#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "rangemode";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, test, v[nmax], ans[nmax], f[nmax], curr;

struct qr{
    int x, y, i;
    bool operator<(const qr &obj)const{
        if(x/330 != obj.x/330)
            return x/330 < obj.x/330;
        return y < obj.y;
    }
} e[nmax];

void add(int x, int &cur)
{
    ++f[x];
    if(f[x] > f[cur] || (f[x] == f[cur] && x < cur))
        cur = x;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= test; ++i)
        fin >> e[i].x >> e[i].y, e[i].i = i;
    sort(e+1, e+test+1);
    int dr;
    for (int t = 1; t <= test; ++t){
        int x = e[t].x, y = e[t].y;
        if(t == 1 || x/330 != e[t-1].x/330){
            memset(f, 0, sizeof(f));
            curr = 0;
            dr = 330*(e[t].x/330+1);
        }
        while(dr <= y)
            add(v[dr++], curr);
        int newcurr = curr;
        for (int i = x; i <= min(330*(e[t].x/330+1)-1, y); ++i)
            add(v[i], newcurr);
        ans[e[t].i] = newcurr;
        for (int i = x; i <= min(330*(e[t].x/330+1)-1, y); ++i)
            --f[v[i]];
    }
    for (int i = 1; i <= test; ++i)
        fout << ans[i] << "\n";
    return 0;
}
