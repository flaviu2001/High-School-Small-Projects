#include <bits/stdc++.h>

using namespace std;

const int M = 100003;
int n, test, d[2005][2005], ans;

int main()
{
    ifstream fin ("fractii2.in");
    ofstream fout ("fractii2.out");
    fin >> test >> n;
    if(test == 1){
        for (int i = 1; i < n; ++i)
            fout << i << " ";
        fout << n-1 << "\n";
    }else{
        d[2][1] = 1;
        for (int i = 3; i <= n; ++i)
            for (int j = 1; j <= i/2; ++j){
                d[i][j] = (d[i][j-1] + d[i-j][(i-j)/2] - d[i-j][(j+1)/2-1])%M;
                if(d[i][j] < 0)
                    d[i][j] = M + d[i][j];
            }
        fout << d[n][n/2] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

