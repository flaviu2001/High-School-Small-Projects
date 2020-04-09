#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "karma";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, M = 1000000007;

int pd[1<<21], n, m;
char c[25][25];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int sum = 0;
        for (int j = 1; j <= m; ++j){
            fin >> c[i][j];
            if(c[i][j] == '(')
                ++sum;
            else --sum;
        }
        if(sum != 0){
            fout << "0\n";
            return 0;
        }
    }
    pd[0] = 1;
    for (int t = 0; t < (1<<m); ++t){
        int val[n+1] = {0};
        for (int j = 0; j < m; ++j)
            if(t&(1<<j))
                for (int i = 1; i <= n; ++i)
                    val[i] += (c[i][j+1] == '(' ? 1 : -1);
        bool good = true;
        for (int i = 1; i <= n; ++i)
            if(val[i] < 0)
                good = false;
        if(!good)
            continue;
        for (int j = 0; j < m; ++j)
            if((t&(1<<j)) == 0){
                good = true;
                for (int i = 1; i <= n; ++i)
                    if(val[i]+(c[i][j+1] == '(' ? 1 : -1) < 0)
                        good = false;
                if(good)
                    pd[t^(1<<j)] = (pd[t^(1<<j)] + pd[t])%M;
            }
    }
    fout << pd[(1<<m)-1] << "\n";
    return 0;
}
