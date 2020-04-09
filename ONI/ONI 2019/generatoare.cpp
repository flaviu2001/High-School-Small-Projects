#include <bits/stdc++.h>

using namespace std;

const int nmax = 50005;
int n, v[nmax];
double p[32][nmax], ans;

int main()
{
    ifstream fin ("generatoare.in");
    ofstream fout ("generatoare.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int t = 0; t <= 30; ++t){
        int bit = (1<<t);
        for (int i = 1; i <= n; ++i){
            int ones = 0, zeroes = 0;
            int rem = v[i]-(v[i]%(bit*2));
            ones = rem/2;
            zeroes = rem/2;
            if(rem+bit <= v[i]){
                zeroes += bit;
                ones += v[i]-rem-bit;
            }else zeroes += v[i]-rem;
            p[t][i] = 1.0*ones/(ones+zeroes);
        }
        for (int i = 2; i <= n; ++i)
            p[t][i] = 1.0*p[t][i-1]*(1-p[t][i]) + 1.0*(1-p[t][i-1])*p[t][i];
        ans += 1.0*p[t][n]*(1<<t);
    }
    fout << fixed << setprecision(3) << ans << "\n";
    return 0;
}

