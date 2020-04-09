#include <bits/stdc++.h>

using namespace std;

int test, v[505][505];

int main()
{
    ifstream fin ("magicmatrix.in");
    ofstream fout ("magicmatrix.out");
    fin >> test;
    while(test--){
        int n;
        fin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                fin >> v[i][j];
        bool good = true;
        for (int i = 2; i <= n && good; ++i)
            for (int j = 2; j <= n && good; ++j)
                if(v[i][j] + v[i-1][j-1] != v[i][j-1] + v[i-1][j])
                    good = false;
        if(good)
            fout << "YES\n";
        else fout << "NO\n";
    }
    fin.close();
    fout.close();
    return 0;
}

