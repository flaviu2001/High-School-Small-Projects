#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, c, pd[704][704];
vector<ll> sol;

int main()
{
    ifstream fin ("avere.in");
    ofstream fout ("avere.out");
    fin >> n >> c;
    pd[1][1] = 1;
    for (ll i = 0; i < 704; ++i)
        pd[0][i] = pd[1][i] = 1;
    for (ll i = 2; i <= 700; ++i){
        for (ll j = 1; j <= i; ++j){
            pd[i][j] = pd[i][j-1];
            if(j*(j-1)/2 >= i-j)
                pd[i][j] += pd[i-j][j-1];
        }
        for (ll j = i+1; j <= 700; ++j)
            pd[i][j] = pd[i][i];
    }
    ll now = n, prev = n+1;
    while(c && now){
        for (ll i = 1; i <= min(now, prev-1); ++i)
            if(i == min(now, prev-1) || (pd[now][i] >= c && pd[now][i-1] < c)){
                sol.push_back(i);
                c -= pd[now][i-1];
                now -= i;
                prev = i;
            }
    }
    fout << pd[n][n] << "\n";
    for (vector<ll>::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << *it << " ";
    return 0;
}

