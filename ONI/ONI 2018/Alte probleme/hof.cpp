#include <bits/stdc++.h>

using namespace std;

long long idxr, lasts, r[100005], n, ans[2];

int main()
{
    ifstream fin ("hof.in");
    ofstream fout ("hof.out");
    fin >> n;
    r[1] = 1;
    r[2] = 3;
    ans[1] = 1;
    ans[0] = 3;
    lasts = 4;
    idxr = 3;
    for (long long i = 3; i <= n; ++i){
        if(i < 100005)
            r[i] = r[i-1] + lasts;
        ans[i%2] = ans[1-(i%2)] + lasts;
        ++lasts;
        if(lasts == r[idxr]){
            ++lasts;
            ++idxr;
        }
    }
    fout << ans[n%2] << "\n";
    fin.close();
    fout.close();
    return 0;
}

