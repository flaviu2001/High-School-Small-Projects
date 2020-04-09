#include <bits/stdc++.h>

using namespace std;

const string file = "color5";

int n;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    int k = 3;
    if(n <= 6)
        k = 2;
    if(n == 3)
        k = 1;
    fout << k << "\n";
    for (int i = 1; i <= n; ++i)
        fout << (i%n) << " " << i-1 << " " << (i%k == 0 ? k : i%k) << "\n";
    for (int i = 2; i <= n+1; ++i)
        fout << n << " " << i-2 << " " << (i%k == 0 ? k : i%k) << "\n";
    return 0;
}
