#include <bits/stdc++.h>
 
using namespace std;
 
long long v[100005];
long long k, n, sol, del;
 
int main()
{
    ifstream fin ("lss.in");
    ofstream fout ("lss.out");
    fin >> k >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    sort(v+1, v+n+1);
    for (int i = 1; i <= n; ++i){
        v[i] %= k;
        if(v[i] == 0)
            v[i] = k;
        sol += max(v[i]-i+1, 1ll);
    }
    fout << sol <<"\n";
    fin.close();
    fout.close();
    return 0;
}
