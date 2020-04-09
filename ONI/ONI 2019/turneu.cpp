#include <bits/stdc++.h>
 
using namespace std;
typedef long double ld;
 
int test, n;
ld v[100005];
 
int main()
{
    ifstream fin ("turneu.in");
    ofstream fout ("turneu.out");
    fin >> test;
    while(test--){
        fin >> n;
        bool good = true;
        ld sum = 0, chk;
        for (int i = 1; i <= n; ++i){
            fin >> v[i];
            if(v[i]*2 != int(v[i]*2))
                good = false;
            sum += v[i];
            chk = 1ll*i*(i-1)/2;
            if(sum < chk)
                good = false;
        }
        fout << (good && sum == chk ? "YES" : "NO") << "\n";
    }
    return 0;
}
