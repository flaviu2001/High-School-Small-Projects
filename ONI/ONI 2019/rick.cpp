#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "rick";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 500005, M = 1000000007;

int n, m, v[nmax], f[nmax], pd[nmax], mx, pw2[nmax], sol=1;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        ++f[v[i]];
        mx = max(mx, v[i]);
    }
    pw2[0] = 0;
    for (int i = 1; i <= n; ++i)
        pw2[i] = (pw2[i-1]*2+1)%M;
    for (int i = 1; i <= mx; ++i)
        pd[i] = i;
    for (int i = 1; i <= mx; ++i){
        int many = 0, sum = 0;
        for (int j = i; j <= mx; j += i){
            many += f[j];
            if(j != i)
                pd[j] -= pd[i];
        }
        sol = (sol+1ll*pw2[many]*pd[i])%M;
    }
    fout << sol << "\n";
    return 0;
}
