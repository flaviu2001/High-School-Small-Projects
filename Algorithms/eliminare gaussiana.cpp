#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "gauss";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, m;
double v[305][305], val[305];

bool check()
{
    for (int i = 1; i <= n; ++i){
        double now = 0;
        for (int j = 1; j <= m; ++j)
            now += v[i][j]*val[j];
        if(abs(now-v[i][m+1]) > 0.001)
            return false;
    }
    return true;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m+1; ++j)
            fin >> v[i][j];
    int a = 1, b = 1;
    while(a <= n && b <= m){
        int first = -1;
        for (int i = a; i <= n; ++i)
            if(v[i][b] != 0){
                first = i;
                break;
            }
        if(first == -1){
            ++b;
            continue;
        }
        for (int j = 1; j <= m+1; ++j)
            swap(v[a][j], v[first][j]);
        for (int j = b+1; j <= m+1; ++j)
            v[a][j] /= v[a][b];
        v[a][b] = 1;
        for (int i = a+1; i <= n; ++i){
            double x = v[i][b];
            for (int j = 1; j <= m+1; ++j)
                v[i][j] -= x*v[a][j];
        }
        ++a, ++b;
    }
    --a;
    while(a >= 1){
        b = -1;
        for (int j = 1; j <= m; ++j)
            if(v[a][j] != 0){
                b = j;
                break;
            }
        if(b == -1){
            if(v[a][m+1] == 0)
                continue;
            else
                break;
        }
        double now = v[a][m+1];
        for (int j = b+1; j <= m; ++j)
            now -= v[a][j]*val[j];
        val[b] = now;
        --a;
    }
    if(!check())
        fout << "Imposibil\n";
    else for (int i = 1; i <= m; ++i)
        fout << fixed << setprecision(12) << val[i] << " ";
    return 0;
}
