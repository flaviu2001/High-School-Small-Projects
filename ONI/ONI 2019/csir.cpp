#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int n, test;
char v[50005];

int main()
{
    ifstream fin ("csir.in");
    ofstream fout ("csir.out");
    fin >> test;
    while(test--){
        fin >> v+1;
        n = strlen(v+1);
        int B = 0;
        for (int i = 1; i <= n; ++i)
            if(v[i] == 'B')
                ++B;
        if(B == 0){
            fout << "1\n";
            continue;
        }
        ld mn = 1e5, mx = -1e5;
        int now = 0;
        for (int i = 1; i <= n; ++i)
            if(v[i] == 'B'){
                ++now;
                mn = min(mn, ld(now*n)/B-ld(i));
                mx = max(mx, ld(now*n)/B-ld(i));
            }
        if(mx-mn >= 0.999999)
            fout << "0\n";
        else fout << "1\n";
    }
    return 0;
}
