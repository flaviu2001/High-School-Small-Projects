#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "smooth2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n;
set<char> s2;
string s;

int calc(int k)
{
    int l = 0, r = k-1, ans = 0;
    while(l < n){
        char F[26];
        memset(F, 0, sizeof(F));
        for (int i = l; i <= r; ++i){
            ++F[s[i]-'a'];
            if(F[s[i]-'a'] > 1)
                ++ans;
        }
        l += k;
        r += k;
        r = min(r, n-1);
    }
    return ans;
}

int calc2(int k)
{
    int l = 0, r = k-1;
    int f[27];
    memset(f, 0, sizeof(f));
    while(l < n){
        bool ok[26];
        memset(ok, 0, sizeof(ok));
        for (int i = l; i <= r; ++i){
            if(!ok[s[i]-'a'])
                ++f[s[i]-'a'];
            ok[s[i]-'a'] = 1;
        }
        l += k;
        r += k;
        r = min(r, n-1);
    }
    pair<int, int> M[27];
    for (int i = 0; i <= 'z'-'a'; ++i)
        M[i] = {f[i], i};
    sort(M, M+26);
    bool ok[27];
    memset(ok, 0, sizeof(ok));
    for (int i = 25; i >= 26-k; --i)
        ok[M[i].ss] = 1;
    int ans = 0;
    l = 0, r = k-1;
    while(l < n){
        char F[26];
        memset(F, 0, sizeof(F));
        for (int i = l; i <= r; ++i){
            ++F[s[i]-'a'];
            if(ok[s[i]-'a'] && F[s[i]-'a'] > 1)
                ++ans;
            else if(!ok[s[i]-'a'])
                ++ans;
        }
        l += k;
        r += k;
        r = min(r, n-1);
    }
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> s; n = s.length();
    for (int i = 0; i < n; ++i)
        s2.insert(s[i]);
    int ans = calc(s2.size());
    for (int i = s2.size()+1; i <= min(26, n); ++i)
        ans = min(ans, calc(i));
    for (int i = s2.size()-1; i >= 1; --i)
        ans = min(ans, calc2(i));
    fout << ans << "\n";
    return 0;
}
