#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "porcjoc";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, sum, w[nmax*5];
pi v[nmax];
vector<int> divs[nmax*5];
bool ok[nmax*5];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    for (int i = 2; i < nmax*5; ++i)
        if(!ok[i])
            for (int j = i; j < nmax*5; j += i){
                ok[j] = 1;
                divs[j].push_back(i);
            }
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i].ff >> v[i].ss;
        sum += v[i].ss;
        for (int c = 1; c < (1<<(divs[v[i].ff].size())); ++c){
            int now = 1;
            for (int j = 0; j < divs[v[i].ff].size(); ++j)
                if(c&(1<<j))
                    now *= divs[v[i].ff][j];
            w[now] += v[i].ss;
        }
    }
    ll a, b;
    a = b = 1ll*sum*sum;
    for (int i = 1; i <= n; ++i){
        ll now = 0;
        for (int c = 1; c < (1<<(divs[v[i].ff].size())); ++c){
            int now = 1;
            for (int j = 0; j < divs[v[i].ff].size(); ++j)
                if(c&(1<<j))
                    now *= -divs[v[i].ff][j];
            if(now > 0)
                a += 1ll*v[i].ss*w[now];
            else a -= 1ll*v[i].ss*w[-now];
        }
    }
    ll gc = __gcd(a, b);
    fout << a/gc << "/" << b/gc << "\n";
    return 0;
}
