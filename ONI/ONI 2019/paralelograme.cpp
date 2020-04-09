#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "paralelograme";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647;

int gcd[2005][2005];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    for (int i = 1; i <= 2000; ++i){
        gcd[i][i] = i;
        for (int j = i+1; j <= 2000; ++j)
            gcd[i][j] = gcd[j][i] = gcd[i][j-i];
    }
    ll n, m;
    fin >> n >> m;
    ll sol = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sol += (n-i+1)*(m-j+1)*((i+1)*(j+1)-3+(i-1)*(j-1)-(gcd[i][j]-1));
    fout << sol << "\n";
    return 0;
}
