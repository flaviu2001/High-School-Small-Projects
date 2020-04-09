#include <bits/stdc++.h>

using namespace std;

long long n, phi[1000005], sumphi[1000005];
unordered_map<long long, long long> m;

long long rec(long long x)
{
    if(x <= 1000000)
        return sumphi[x]; //My original solution got 75p without using the sieve for values under 1mil
    if(m.find(x) != m.end())
        return m[x];
    long long ans = x*(x+1)/2;
    long long last = x/2, sq = sqrt(x);
    ans -= rec(x/2);
    ans -= (x+1)/2;
    for (long long i = 3; i <= sq; ++i){
        ans -= rec(x/i);
        ans -= (last-(x/i))*rec(i-1);
        last = x/i;
    }
    for (long long i = (x/sq); i > sq; --i)
        ans -= rec(x/i);
    m[x] = ans;
    return ans;
}

int main()
{
    ifstream fin ("cntgcd.in");
    ofstream fout ("cntgcd.out");
    long long a, b;
    fin >> a >> b;
    n = a/b;
    for (int i = 1; i <= 1000000; ++i)
        phi[i] = i;
    for (int i = 2; i <= 1000000; ++i)
        if(phi[i] == i)
            for (int j = i; j <= 1000000; j += i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
    sumphi[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
        sumphi[i] = phi[i] + sumphi[i-1];
    fout << rec(n) << "\n";
    fin.close();
    fout.close();
    return 0;
}

