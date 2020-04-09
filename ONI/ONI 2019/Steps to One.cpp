#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, M = 1000000007;

int pw(int x, int y)
{
    int ans = 1;
    while(y)
        if(y%2 == 0){
            x = (1ll*x*x)%M;
            y /= 2;
        }else{
            ans = (1ll*ans*x)%M;
            --y;
        }
    return ans;
}

int n, m[100005];

int pinex(vector<int> &divs, int N)
{
    int ans = 0;
    for (int c = 1; c < (1<<divs.size()); ++c){
        int now = -1;
        for (int j = 0; j < int(divs.size()); ++j)
            if(c&(1<<j))
                now *= -divs[j];
        ans += N/now;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    m[1] = 1;
    for (int i = 2; i <= n; ++i){
        vector<int> divs;
        int x = i, go = 1;
        for (int d = 2; d*d <= x; ++d)
            if(x%d == 0){
                divs.push_back(d);
                go *= d;
                while(x%d == 0)
                    x /= d;
            }
        if(x != 1){
            divs.push_back(x);
            go *= x;
        }
        if(go != i){
            m[i] = m[go];
            continue;
        }
        int len = 1;
        for (int c = 1; c < (1<<divs.size()); ++c){
            int now = 1;
            vector<int> r;
            for (int j = 0; j < int(divs.size()); ++j)
                if(c&(1<<j)){
                    now *= divs[j];
                    r.push_back(divs[j]);
                }
            int now2 = i/now;
            now = n/now2 - pinex(r, n/now2);
            now = (1ll*now*pw(n, M-2))%M;
            now = (1ll*now*m[now2])%M;
            len = (len+now)%M;
        }
        int dv = n/i;
        dv = n-dv;
        dv = (1ll*dv*pw(n, M-2))%M;
        m[i] = (1ll*len*pw(dv, M-2))%M;
    }
    int sol = 0;
    for (int i = 1; i <= n; ++i)
        sol = (sol+m[i])%M;
    sol = (1ll*sol*pw(n, M-2))%M;
    cout << sol << "\n";
    return 0;
}
