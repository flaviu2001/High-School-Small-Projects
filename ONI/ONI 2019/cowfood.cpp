#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "cowfood";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 3210121;

int k, s, n, pd[35][10004], mx[35], v[25][35], st[25][35], vf, all;
bool ok[1<<20+5];

void rec(int t, int from = -1, int mult = 1)
{
    if(from != -1){
        ++vf;
        for (int i = 1; i <= k; ++i)
            st[vf][i] = max(st[vf-1][i], v[from][i]);
        int now = s;
        for (int i = 1; i <= k; ++i)
            now -= st[vf][i];
        if(now >= 0)
            all = (all+pd[k][now]*mult+M)%M;
    }
    ok[t] = 1;
    for (int i = 0; i < n; ++i)
        if((t&(1<<i)) == 0 && !ok[t|(1<<i)])
            rec(t|(1<<i), i, mult*-1);
    --vf;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> k >> s >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= k; ++j)
            fin >> v[i][j];
    for (int i = 0; i <= k; ++i)
        pd[i][0] = 1;
    for (int j = 0; j <= s; ++j)
        pd[0][j] = 1;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= s; ++j)
            pd[i][j] = (pd[i-1][j] + pd[i][j-1])%M;
    all = (pd[k][s]-((s*k+1)%M)+M)%M;
    rec(0);
    fout << all << "\n";
    return 0;
}
