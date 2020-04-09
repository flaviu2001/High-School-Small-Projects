#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "identice";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1005;

ll test, n, D, vf, pred[nmax][nmax], v[nmax][nmax], mars[nmax][nmax];
pi s[nmax];

ll cerinta1()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            pred[i][j] = pred[i][j-1];
            if(v[i][j] == 1)
                pred[i][j] = j;
        }
    ll sol = 0;
    for (int j = 1; j <= n; ++j){
        ll now = 0;
        vf = 0;
        for (int i = 1; i <= n; ++i){
            ll modif = 0, many = 1;
            ll x = j-pred[i][j];
            while(vf > 0 && s[vf].ff >= x){
                many += s[vf].ss;
                modif += s[vf].ff*s[vf].ss;
                --vf;
            }
            now -= modif;
            now += x*many;
            s[++vf] = {x, many};
            sol += now;
        }
    }
    return sol;
}

ll cerinta2()
{
    memset(mars, 0, sizeof(mars));
    int sol = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            mars[i][j] += mars[i-1][j]+mars[i][j-1]-mars[i-1][j-1];
            if((v[i][j]+mars[i][j])%2 == 1){
                ++sol;
                mars[i][j] += 1;
                if(max(i+D, j+D) > n+1)
                    return inf;
                mars[i+D][j] -= 1;
                mars[i][j+D] -= 1;
                mars[i+D][j+D] += 1;
            }
        }
    return sol;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test >> n >> D;fin.get();
    for (int i = 1; i <= n; ++i){
        char c[nmax];
        fin.getline(c, n+1);
        for (int j = 1; j <= n; ++j)
            if(c[j-1] == '1')
                v[i][j] = 1;
    }
    if(test == 1){
        ll sol = cerinta1();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                v[i][j] = 1-v[i][j];
        sol += cerinta1();
        fout << sol << "\n";
    }else{
        ll ans = cerinta2();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                v[i][j] = 1-v[i][j];
        ans = min(ans, cerinta2());
        fout << (ans == inf ? -1 : ans) << "\n";
    }
    return 0;
}
