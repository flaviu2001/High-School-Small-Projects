#include <bits/stdc++.h>

using namespace std;

const int nmax = 50005, inf = 1<<30;
int n, k, pr, mn[nmax], mn2[nmax], sol=-inf, solx, soly;

int main()
{
    ifstream fin ("secv2.in");
    ofstream fout ("secv2.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        pr += x;
        mn[i] = mn[i-1];
        mn2[i] = mn2[i-1];
        if(pr < mn[i]){
            mn[i] = pr;
            mn2[i] = i;
        }
        if(i >= k && pr-mn[i-k] > sol){
            sol = pr-mn[i-k];
            solx = mn2[i-k];
            soly = i;
        }
    }
    fout << solx+1 << " " << soly << " " << sol << "\n";
    return 0;
}

