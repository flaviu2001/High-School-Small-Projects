#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "ghiozdan";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, g, pd[75005], use[75005], f[205];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> g;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        ++f[x];
    }
    pd[0] = 1;
    for (int i = 200; i >= 1; --i)
        for (int j = g; j >= 0; --j)
            if(pd[j]){
                for (int d = 1; d <= f[i] && j+d*i <= g && !pd[j+d*i]; ++d){
                    pd[j+d*i] = pd[j]+d;
                    use[j+d*i] = i;
                }
            }
    int now = g;
    while(now && !pd[now])
        --now;
    fout << now << " " << pd[now]-1 << "\n";
    while(now > 0){
        fout << use[now] << "\n";
        now -= use[now];
    }
    return 0;
}
