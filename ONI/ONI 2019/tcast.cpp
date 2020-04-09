#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "tcast";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, test, pd[2005][3005], nxt[2005][1005], pre[2005], p[2005], t[2005], ac[2005][1005];
vector<int> v[2005];
bool ok[2005];

bool check(int nod, int d, int mx, int av, int sons)
{
    if(t[sons-1]+1 > mx)
        return false;
    int it = 0;
    for (auto x : v[nod])
        if(x != av){
            int ans = pre[x];
            while(ans >= 0 && pd[x][t[ans]+1] > mx)
                --ans;
            while(ans+1 < sons && pd[x][t[ans+1]+1] <= mx)
                ++ans;
            pre[x] = ans;
            if(ans == -1)
                return false;
            p[it++] = ans;
        }
    sort(p, p+sons);
    for (int i = 0; i < sons; ++i)
        if(i > p[i])
            return false;
    return true;
}

void dfs(int x)
{
    ok[x] = 1;
    int av = -1, sons = 0;
    for (auto y : v[x]){
        if(!ok[y]){
            dfs(y);
            ++sons;
        }else av = y;
    }
    if(sons == 0){
        for (int i = 1; i <= test+n; ++i)
            pd[x][i] = i;
        return;
    }
    for (int d = 1; d <= test+n; ++d){
        if(d > test){
            pd[x][d] = 1+pd[x][d-1];
            continue;
        }
        int chk = 1;
        if(d != 1)
            chk = pd[x][d-1];
        if(!ac[x][d])
            t[0] = d;
        else t[0] = nxt[x][d];
        for (int i = 2; i <= sons; ++i)
            if(t[i-2] > test)
                t[i-1] = t[i-2]+1;
            else t[i-1] = nxt[x][t[i-2]];
        while(!check(x, d, chk, av, sons))
            ++chk;
        pd[x][d] = chk;
    }
}

int main()
{
    ifstream fin (file+".in"); //needs parser for 100
    ofstream fout (file+".out");
    fin >> n >> test;
    for (int i = 2; i <= n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        pre[i] = -1;
    for(int i = 1; i <= n; ++i){
        for (int j = 1; j <= test; ++j)
            fin >> ac[i][j];
        nxt[i][test] = test+1;
        for (int j = test-1; j >= 1; --j)
            if(ac[i][j+1])
                nxt[i][j] = nxt[i][j+1];
            else nxt[i][j] = j+1;
    }
    dfs(1);
    fout << pd[1][1]-1 << "\n";
    return 0;
}
