#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M = 1000000009, B = 26;
int n, k, h[17000], pw[17000];
string s;

bool check(int m)
{
    unordered_map<int, int> mp;
    ++mp[h[m-1]];
    for (int i = m; i < n; ++i){
        int H = h[i]-ll(1ll*h[i-m]*pw[m])%M;
        if(H < 0)
            H = M+H%M;
        ++mp[H];
    }
    int mx = 1;
    for (auto x : mp)
        mx = max(mx, x.second);
    return mx >= k;
}

int main()
{
    ifstream fin ("substr.in");
    ofstream fout ("substr.out");
    fin >> n >> k >> s;
    h[0] = s[0]-'a';
    for (int i = 1; i < n; ++i)
        h[i] = ll(1ll*h[i-1]*B+s[i]-'a')%M;
    pw[0] = 1;
    for (int i = 1; i < 17000; ++i)
        pw[i] = ll(1ll*pw[i-1]*B)%M;
    int lo = 1, hi = n, m, ans = 0;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
        if(check(m)){
            ans = m;
            lo = m+1;
        }else hi = m-1;
    fout << ans << "\n";
    return 0;
}

