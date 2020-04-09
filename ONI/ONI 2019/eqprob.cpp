#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll test, n, all, good, pd[55][55], pw[55];

int main()
{
    ifstream fin ("eqprob.in");
    ofstream fout ("eqprob.out");
    pw[0] = 1;
    for (ll i = 1; i < 51; ++i)
        pw[i] = pw[i-1]*2;
    fin >> test;
    while(test--){
        ll n;
        string s;
        fin >> n >> s;
        all = (pw[n]-1)*n*(n+1)/2;
        good = 0;
        for (int t1 = 0; t1 < s.length(); ++t1)
            for (int t2 = t1; t2 < s.length(); ++t2){
                memset(pd, 0, sizeof(pd));
                pd[t1][0] = (s[0] == s[t1]);
                for (int t = 1; t < s.length(); ++t)
                    pd[t1][t] = pd[t1][t-1]+(s[t] == s[t1]);
                for (int t = t1+1; t <= t2; ++t)
                    for (int r = 1; r < s.length(); ++r){
                        pd[t][r] = pd[t][r-1];
                        if(s[r] == s[t])
                            pd[t][r] += pd[t-1][r-1];
                    }
                good += pd[t2][s.length()-1];
            }
        double d = (1.0*good/all);
        fout << fixed << setprecision(12) <<  d << "\n";
    }
    return 0;
}

