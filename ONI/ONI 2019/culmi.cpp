#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "culmi";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, base = 1000000000;

int n, t;
int pd[105][105][2][2][7];

void cpy(int a[], int b[])
{
    a[0] = b[0];
    for (int i = 1; i <= a[0]; ++i)
        a[i] = b[i];
}

inline void add(int a[], int b[])
{
    int c = a[0];
    int &d = b[0];
    for(int i = 1; i <= c; ++i)
        b[i] += a[i];
    if(c > d)
        d = c;
    for(int i = 1; i <= d; ++i)
    {
        if(b[i] >= base)
        {
            b[i+1]++;
            b[i] -= base;
            if(i == d)
                ++d;
        }
    }
}

void Set(int a[], int x)
{
    for (int i = 1; i <= 6; ++i)
        a[i] = 0;
    a[0] = 1;
    a[1] = x;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> t;
    Set(pd[0][0][0][1], 1);
    for (int k = 0; k <= t; ++k)
        for (int l = 0; l <= n; ++l)
            for (int r = 0; r <= n; ++r){
                Set(pd[l][r][k%2][0], 0);
                Set(pd[l][r][k%2][1], 0);
                if(l >= r){
                    if(l+r == 0)
                        continue;
                    if(l == 1 && r == 0 && k == 0){
                        Set(pd[1][0][k%2][0], 1);
                        continue;
                    }
                    if(r == 1 && l == 0 && k == 0){
                        Set(pd[0][1][k%2][1], 1);
                        continue;
                    }
                    if(l-1 >= 0){
                        add(pd[l-1][r][k%2][1], pd[l][r][k%2][0]);
                        add(pd[l-1][r][k%2][0], pd[l][r][k%2][0]);
                    }
                    if(r-1 >= 0 && k-1 >= 0)
                        cpy(pd[l][r][k%2][1], pd[l][r-1][(k-1)%2][0]);
                    if(r-1 >= 0)
                        add(pd[l][r-1][k%2][1], pd[l][r][k%2][1]);

                }
            }
    for (int i = pd[n][n][t%2][1][0]; i >= 1; --i)
        if(i == pd[n][n][t%2][1][0])
            fout << pd[n][n][t%2][1][i];
        else{
            ll p = pd[n][n][t%2][1][i];
            while(p*10 < base){
                p *= 10;
                fout << 0;
            }
            fout << pd[n][n][t%2][1][i];
        }
    return 0;
}
