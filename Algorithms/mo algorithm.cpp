#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const string file = "suma6";
const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647, nmax = 100005, K = 310;

struct query{
    int a, b, i;
    bool operator<(const query &obj)const{
        if (a != obj.a)
            return a < obj.a;
        return b < obj.b;
    }
};

int n, test, S, v[nmax], f[1000006];
ll ans, sol[nmax*2];
vector<query> b[nmax/K+5];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> S;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    fin >> test;
    for (int i = 1; i <= test; ++i){
        int x, y;
        fin >> x >> y;
        b[y/K].push_back({x, y, i});
    }
    for (int t = 0; t <= n/K; ++t)
        if(b[t].size()){
            sort(b[t].begin(), b[t].end());
            ans = 0;
            for (int i = b[t][0].a; i <= b[t][0].b; ++i){
                if(S-v[i] >= 0)
                    ans += f[S-v[i]];
                ++f[v[i]];
            }
            int ba = b[t][0].a, bb = b[t][0].b;
            for (auto x : b[t]){
                while(bb < x.b){
                    if(S-v[bb+1] >= 0)
                        ans += f[S-v[bb+1]];
                    ++f[v[++bb]];
                }
                while(bb > x.b){
                    if(S-v[bb] >= 0)
                        ans -= f[S-v[bb]];
                    --f[v[bb--]];
                }
                while(ba < x.a){
                    if(S-v[ba] >= 0)
                        ans -= f[S-v[ba]];
                    --f[v[ba++]];
                }
                sol[x.i] = ans;
            }
            for (int i = ba; i <= bb; ++i)
                --f[v[i]];
        }
    for (int i = 1; i <= test; ++i)
        fout << sol[i] << "\n";
    return 0;
}
