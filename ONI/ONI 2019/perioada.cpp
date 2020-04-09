#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "perioada";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005, M = 1000000009, B = 26;

int n, test, h[nmax], pw[nmax], inv[nmax];
char c[nmax];
vector<int> divs[nmax];

void gcd(ll &x, ll &y, ll a, ll b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        ll aux = x;
        x = y;
        y = aux - y*(a/b);
    }
}

ll invers(ll x)
{
    ll a, b;
    gcd(a, b, x, M);
    if(a < 0)
        a = M+a%M;
    return a;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> (c+1) >> test;
    h[1] = c[1]-'a';
    for (int i = 2; i <= n; ++i)
        h[i] = (1ll*h[i-1]*B+c[i]-'a')%M;
    pw[0] = 1;
    for (int i = 1; i < nmax; ++i){
        pw[i] = (1ll*pw[i-1]*B)%M;
        inv[i] = invers(pw[i]-1);
    }
    for (int i = 1; i < nmax; ++i)
        for (int j = i+i; j < nmax; j += i)
            divs[j].push_back(i);
    while(test--){
        int a, b;
        fin >> a >> b;
        int ans = 0;
        int H2 = h[b];
        H2 -= (1ll*h[a-1]*pw[b-a+1])%M;
        H2 = (H2+M)%M;
        for (auto x : divs[b-a+1]){
            int H = h[a+x-1];
            H -= (1ll*h[a-1]*pw[x])%M;
            H = (H+M)%M;
            int Check = (pw[b-a+1]+M-1)%M;
            Check = (1ll*Check*inv[x])%M;
            Check = (1ll*Check*H)%M;
            if(H2 == Check)
                ++ans;
        }
        fout << ans << "\n";
    }
    return 0;
}
