#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 10000007;

int n, l, r, sqn[nmax], pwn[nmax];

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x%y));
}

int calc(vector<int> &v, int x)
{
    int i = v.back()+1;
    int ans = v.size()*(x/i);
    x %= i;
    if(x == 0)
        return ans;
    int st = 0, dr = v.size()-1, m, ans2 = -1;
    for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
        if(x >= v[m]){
            ans2 = m;
            st = m+1;
        }else dr = m-1;
    return ans+ans2+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    cin >> n >> l >> r;
    if(n == 1){
        cout << r-l+1;
        return 0;
    }else if (n == 2){
        cout << 1ll*(r-l)*(r-l+1);
        return 0;
    }
    --n;
    for (int i = 2; i < nmax; ++i){
        ll now = i;
        for (int j = 1; j < n; ++j){
            now = 1ll*now*i;
            if(now > r)
                goto here;
        }
        pwn[i] = now;
        sqn[now] = i-1;
    }
    here:
    for (int i = 2; i < nmax; ++i)
        if(sqn[i] == 0)
            sqn[i] = sqn[i-1];
    ll sol = 0;
    for (int i = l; i <= r; ++i){
        int st = (l+i-1)/i, dr = r/i;
        sol += sqn[dr]-sqn[st-1];
    }
    for (int i = 1; i < nmax; ++i)
        ++sqn[i];
    for (int i = 2; i <= sqn[r]; ++i){
        vector<int> v;
        for (int j = 1; j < i; ++j)
            if(gcd(i, j) == 1)
                v.push_back(j);
        for (int d = pwn[i]; d <= r; d += i){
            if(d < l)
                continue;
            int many = 0;
            int x = d;
            while(x%i == 0){
                ++many;
                x /= i;
            }
            if(many >= n){
                int st = (l+(d/pwn[i])-1)/(d/pwn[i]), dr = r/(d/pwn[i]);
                sol += calc(v, sqn[dr])-calc(v, sqn[st-1]);
            }
        }
    }
    cout << sol;
    return 0;
}
