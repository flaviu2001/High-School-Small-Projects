#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "xortransform";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, m, q, dp[(1<<21)+5];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            int x;
            fin >> x;
            dp[i|j] ^= x;
        }
    for (int j = 0; j <= 21; ++j)
        for (int i = (1<<21)-1; i >= 0; --i)
            if(i&(1<<j))
                dp[i] ^= dp[i^(1<<j)];
    int ans = 0;
    while(q--){
        int k;
        fin >> k;
        k ^= ans;
        ans = dp[((1<<21)-1)&k];
        fout << ans << "\n";
    }
    return 0;
}
