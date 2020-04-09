#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "stiva";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

string c;
int n, pd[505][505];

string compress(string s)
{
    string ans;
    ans += s[0];
    for (int i = 1; i < s.length(); ++i)
        if(s[i] != s[i-1])
            ans += s[i];
    return ans;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> c;
    int add = c.length();
    c = compress(c);
    n = c.length();
    c = " " + c;
    for (int d = 0; d < n; ++d)
        for (int i = 1; i+d <= n; ++i){
            int st = i, dr = i+d;
            if(st == dr){
                pd[st][dr] = 2;
                continue;
            }
            pd[st][dr] = inf;
            for (int i = st; i < dr; ++i)
                pd[st][dr] = min(pd[st][dr], pd[st][i]+pd[i+1][dr]);
            for(int i = st; i < dr; ++i)
                if(c[i] == c[dr])
                    pd[st][dr] = min(pd[st][dr], pd[st][i] + pd[i+1][dr-1]);
        }
    fout << pd[1][n]+add << "\n";
    return 0;
}
