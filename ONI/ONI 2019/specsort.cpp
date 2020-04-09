#include <bits/stdc++.h>
 
using namespace std;
 
int n, v[50005], r[50005];
 
int main()
{
    ifstream fin ("specsort.in");
    ofstream fout ("specsort.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    int pw = 1;
    while(pw <= n){
        int p = 0;
        for (int i = 1; i <= n; ++i)
            if(!(v[i]&pw))
                r[++p] = v[i];
        for (int i = 1; i <= n; ++i)
            if(v[i]&pw)
                r[++p] = v[i];
        for (int i = 1; i <= n; ++i){
            v[i] = r[i];
            fout << r[i] << " ";
        }
        pw *= 2;
        fout << "\n";
    }
    return 0;
}
