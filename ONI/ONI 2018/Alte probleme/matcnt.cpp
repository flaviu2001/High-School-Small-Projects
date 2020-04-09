#include <bits/stdc++.h>

using namespace std;

const int64_t M = 200003;
int64_t n, sol, a[1000005];

int main()
{
    ifstream fin ("matcnt.in");
    ofstream fout ("matcnt.out");
    fin >> n;
    a[3] = 1;
    a[4] = 3;
    a[5] = 12;
    for (int64_t i = 6; i <= n; ++i)
        a[i] = (a[i-1]*(i-1) + a[i-3] * (i-1)*(i-2)/2)%M;
    sol = a[n];
    for (int64_t i = 2; i <= n; ++i)
        sol = (sol*i)%M;
    fout << sol;
    return 0;
}

