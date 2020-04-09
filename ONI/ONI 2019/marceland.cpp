#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "marceland";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 105, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int test, n, m, v[nmax][nmax], has[nmax*nmax], p;
pi liber[nmax*nmax];
char c[nmax][nmax];

void fill(int x, int y)
{
    if(v[x][y] == -3)
        has[p] = 1;
    if(v[x][y] == 0)
        liber[p] = {x, y};
    v[x][y] = -1;
    for (int d = 0; d < 4; ++d){
        int X = x+dx[d], Y = y+dy[d];
        if(v[X][Y] != -1)
            fill(X, Y);
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test;
    while(test--){
        memset(v, 0, sizeof(v));
        memset(has, 0, sizeof(has));
        p = 0;
        fin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j){
                char q;
                fin >> q;
                c[i][j] = q;
                if(q == '#')
                    v[i][j] = -1;
                if(q == 'M')
                    v[i][j] = -2;
                if(q == '@')
                    v[i][j] = -3;
            }
        for (int i = 0; i <= n+1; ++i)
            v[i][0] = v[i][m+1] = -1;
        for (int j = 0; j <= m+1; ++j)
            v[0][j] = v[n+1][j] = -1;
        bool good = true;
        int add = 0;
        for (int i = 1; i <= n && good; ++i)
            for (int j = 1; j <= m && good; ++j)
                if(v[i][j] == -2){
                    ++p;
                    liber[p] = {-1, -1};
                    fill(i, j);
                    if(!has[p] && liber[p].ff == -1)
                        good = false;
                    if(!has[p])
                        c[liber[p].ff][liber[p].ss] = '@', ++add;
                }
        if(!good){
            fout << "-1\n";
            continue;
        }
        fout << add << "\n";
        for (int i = 1; i <= n; ++i, fout << "\n")
            for (int j = 1; j <= m; ++j)
                fout << c[i][j];
    }
    return 0;
}
