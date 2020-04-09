#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "yinyang";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, m, v[105][105];

int cmpcol(int x)
{
    int lss = 0, more = 0;
    for (int i = 1; i <= n; ++i)
        if(v[i][x] > v[i][x+1])
            more = 1;
        else if (v[i][x] < v[i][x+1])
            lss = 1;
    if(more+lss == 2)
        return -1;
    if(more)
        return 1;
    return 0;
}

int cmplin(int x)
{
    int lss = 0, more = 0;
    for (int j = 1; j <= m; ++j)
        if(v[x][j] > v[x+1][j])
            more = 1;
        else if (v[x][j] < v[x+1][j])
            lss = 1;
    if(more+lss == 2)
        return -1;
    if(more)
        return 1;
    return 0;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    int sol = 0;
    bool ok = 1;
    while(ok){
        ok = 0;
        for (int j = 1; j < m; ++j){
            int val = cmpcol(j);
            if(val == -1){
                fout << "-1\n";
                return 0;
            }
            if(val == 1){
                ok = 1;
                ++sol;
                for (int i = 1; i <= n; ++i)
                    swap(v[i][j], v[i][j+1]);
            }
        }
    }
    ok = 1;
    while(ok){
        ok = 0;
        for (int i = 1; i < n; ++i){
            int val = cmplin(i);
            if(val == -1){
                fout << "-1\n";
                return 0;
            }
            if(val == 1){
                ok = 1;
                ++sol;
                for (int j = 1; j <= m; ++j)
                    swap(v[i][j], v[i+1][j]);
            }
        }
    }
    fout << sol << "\n";
    return 0;
}
