#include <bits/stdc++.h>

using namespace std;

int n, ans = 0, v[1005];

int main()
{
    ifstream fin ("prieteni.in");
    ofstream fout ("prieteni.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    sort(v+1, v+n+1);
    int p = n;
    while(p > 3){
        if(v[p-1]+v[p]+2*v[1] <= v[p]+2*v[2]+v[1]){
            fout << v[1] << " " << v[p-1] << "\n";
            ans += v[p-1];
            fout << v[1] << "\n";
            ans += v[1];
            fout << v[1] << " " << v[p] << "\n";
            ans += v[p];
            fout << v[1] << "\n";
            ans += v[1];
        }else{
            fout << v[1] << " " << v[2] << "\n";
            ans += v[2];
            fout << v[1] << "\n";
            ans += v[1];
            fout << v[p-1] << " " << v[p] << "\n";
            ans += v[p];
            fout << v[2] << "\n";
            ans += v[2];
        }
        p -= 2;
    }
    if(p == 3){
        fout << v[1] << " " << v[2] << "\n";
        ans += v[2];
        fout << v[1] << "\n";
        ans += v[1];
        fout << v[1] << " " << v[3] << "\n";
        ans += v[3];
    }else{
        fout << v[1] << " " << v[2] << "\n";
        ans += v[2];
    }
    fout << ans << "\n";
    return 0;
}

