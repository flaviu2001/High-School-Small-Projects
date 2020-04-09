#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "omogene";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 100000;

int n, m;
long long sol;
vector< vector<int> > v, sp[3];
unordered_map<ll, int> mp;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    if(n <= m){
        for (int i = 0; i <= n; ++i){
            v.push_back(vector<int>(m+1));
            for (int k = 0; k < 3; ++k)
                sp[k].push_back(vector<int>(m+1));
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                fin >> v[i][j];
    }else{
        for (int i = 0; i <= m; ++i){
            v.push_back(vector<int>(n+1));
            for (int k = 0; k < 3; ++k)
                sp[k].push_back(vector<int>(n+1));
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                fin >> v[j][i];
        swap(n, m);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            for (int k = 0; k < 3; ++k)
                sp[k][i][j] = sp[k][i-1][j]+sp[k][i][j-1]-sp[k][i-1][j-1];
            ++sp[v[i][j]][i][j];
        }
    for (int i1 = 1; i1 <= n; ++i1)
        for (int i2 = i1; i2 <= n; ++i2){
            mp.clear();
            ++mp[0];
            for (int k = 1; k <= m; ++k){
                int p[3];
                for (int k2 = 0; k2 < 3; ++k2)
                    p[k2] = sp[k2][i2][k]-sp[k2][i1-1][k];
                int mn = min(p[0], min(p[1], p[2]));
                for (int k2 = 0; k2 < 3; ++k2)
                    p[k2] -= mn;
                ll cod = 1ll*p[0]*M*M+1ll*p[1]*M+p[2];
                sol += mp[cod];
                ++mp[cod];
            }
        }
    fout << sol << "\n";
    return 0;
}
