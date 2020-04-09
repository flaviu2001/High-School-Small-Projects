#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "fibo4";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 666013, nmax = 1000005;

int n, test, f[1332028+5], mars[nmax], mars2[nmax], v[nmax];

int fib(ll k)
{
    return f[k%1332028];
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    f[1] = f[2] = 1;
    for (int i = 3; i <= 1332028; ++i)
        f[i] = (f[i-1]+f[i-2])%M;
    fin >> n >> test;
    for (int i = 1; i <= test; ++i){
        int st, dr;
        ll k;
        fin >> st >> dr >> k;
        if(st == dr){
            v[st] = (v[st] + fib(k))%M;
        }else if (dr-st == 1){
            v[st] = (v[st] + fib(k))%M;
            v[st+1] = (v[st+1] + fib(k+1))%M;
        }else{
            mars[st] = (mars[st] + fib(k))%M;
            mars[dr+1] = (mars[dr+1] - fib(dr-st+k+1) + M)%M;
            mars2[st] = (mars2[st] + fib(k-1))%M;
            mars2[dr+1] = (mars2[dr+1] - fib(dr-st+k) + M)%M;
        }
    }
    for (int i = 1; i <= n; ++i){
        mars[i] = (mars[i] + mars[i-1]+mars2[i-1])%M;
        mars2[i] = (mars2[i] + mars[i-1])%M;
        v[i] = (v[i] + mars[i])%M;
        fout << v[i] << " ";
    }
    return 0;
}
