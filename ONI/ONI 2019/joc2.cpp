#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "joc2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int pd[105][105], n;
pi guys[105];
bool f[10];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    pd[1][1] = 0;
    for (int i = 1; i <= 100; ++i)
        for (int j = 1; j <= i; ++j){
            memset(f, 0, sizeof(f));
            for (int k = 1; k < j; ++k){
                if(j-k > 0)
                    f[pd[i][k]^pd[i][j-k]] = 1;
                if(j-k-1 > 0)
                    f[pd[i][k]^pd[i][j-k-1]] = 1;
            }
            for (int k = 1; k < i; ++k){
                if(i-k > 0)
                    f[pd[k][j]^pd[i-k][j]] = 1;
                if(i-k-1 > 0)
                    f[pd[k][j]^pd[i-k-1][j]] = 1;
            }
            if(i > 2 && j > 2)
                f[pd[i-2][j-2]] = 1;
            for (int k = 0; k <= 8; ++k)
                if(f[k])
                    ++pd[i][j];
                else break;
            pd[j][i] = pd[i][j];
        }
    fin >> n;
    int issol = 0;
    for (int i = 1; i <= n; ++i){
        int x, y;
        fin >> x >> y;
        guys[i] = {x, y};
        issol ^= pd[x][y];
    }
    if(!issol)
        fout << "0\n";
    else{
        int sol = 0;
        for (int i = 1; i <= n; ++i){
            int x = guys[i].ff, y = guys[i].ss;
            int now = issol^pd[x][y];
            for (int k = 1; k < y; ++k){
                if(y-k > 0 && (pd[x][k]^pd[x][y-k]) == now)
                    ++sol;
                if(y-k-1 > 0 && (pd[x][k]^pd[x][y-k-1]) == now)
                    ++sol;
            }
            for (int k = 1; k < x; ++k){
                if(x-k > 0 && (pd[k][y]^pd[x-k][y]) == now)
                    ++sol;
                if(x-k-1 > 0 && (pd[k][y]^pd[x-k-1][y]) == now)
                    ++sol;
            }
            if(x > 2 && y > 2 && pd[x-2][y-2] == now)
                ++sol;
        }
        fout << sol << "\n";
    }
    return 0;
}
