#include <bits/stdc++.h>

using namespace std;

const int M = 700001;
int n, pd[2][50005], pd2[2][50005], sq;

int main()
{
    ifstream fin ("crescator2.in");
    ofstream fout ("crescator2.out");
    fin >> n; sq = sqrt(n);
    for (int s = 1; s <= n; ++s)
        pd[1][s] = 1;
    for (int i = sq+1; i <= n; ++i)
        pd2[(sq+1)%2][i] = (pd2[(sq+1)%2][i] + pd[1][i-sq])%M;
    for (int t = 2; t <= n; ++t){
        for (int s = 1; s <= t; ++s)
            pd[t%2][s] = pd[(t-1)%2][s];
        pd[t%2][t] = (pd[t%2][t] + 1)%M;
        for (int s = t+1; s <= n; ++s)
            pd[t%2][s] = (pd[t%2][s-t] + pd[(t-1)%2][s])%M;
        if(sq*t+1 > n)
            break;
        for (int i = sq*t+1; i <= n; ++i)
            pd2[(sq+1)%2][i] = (pd2[(sq+1)%2][i] + pd[t%2][i-sq*t]-pd[(t-1)%2][i-sq*t]+M)%M;
    }
    for (int t = sq; t >= 1; --t){
        pd2[t%2][t] = 1;
        for (int s = t+1; s <= n; ++s)
            pd2[t%2][s] = (pd2[t%2][s-t] + pd2[(t+1)%2][s])%M;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans+pd2[1][i])%M;
    fout << ans << "\n";
    return 0;
}
