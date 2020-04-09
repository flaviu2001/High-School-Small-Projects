#include <bits/stdc++.h>

using namespace std;

int n, v[20005], ok[20005];

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x%y));
}

int main()
{
    ifstream fin ("perm2.in");
    ofstream fout ("perm2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        if(!ok[i]){
            int p = v[i];
            ok[i] = 1;
            int len = 1;
            while(!ok[p]){
                ok[p] = 1;
                p = v[p];
                ++len;
            }
            int gc = gcd(ans, len);
            ans = ans*len/gc;
        }
    fout << ans << "\n";
    return 0;
}

