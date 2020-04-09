#include <bits/stdc++.h>
#define M 19997

using namespace std;

int v[2005], k;

int rec(int n)
{
    if(v[n] != -1)
        return v[n];
    if(n == 0)
        return 1;
    int a = 1, sol = 0;
    if(v[n-1] == -1)
        v[n-1] = rec(n-1);
    sol += v[n-1];
    for (int i = 2; i <= n && i <= k; ++i){
        a = (1LL*a*(n-i+1))%M;
        if(k%i == 0){
            if(v[n-i] == -1)
                v[n-i] = rec(n-i);
            sol = (sol+1LL*a*v[n-i])%M;
        }
    }
    v[n] = sol%M;
    return sol%M;
}

int main()
{
    ifstream fin ("cifru.in");
    ofstream fout ("cifru.out");
    int n;
    fin >> n >> k;
    memset(v, -1, sizeof(v));
    fout << rec(n);
    fin.close();
    fout.close();
    return 0;
}

