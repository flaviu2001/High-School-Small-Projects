#include <bits/stdc++.h>
#define M 10007

using namespace std;

int m[2][10005];

int main()
{
    ifstream fin ("desc2.in");
    ofstream fout ("desc2.out");
    int n, k, x;
    fin >> n >> k >> x;
    n -= x*(k-1)*k/2;
    for (int i = 1; i <= n; ++i)
        m[1][i] = 1;
    for (int i = 2; i <= k; ++i){
        m[i%2][i] = 1;
        for (int j = 1; j < i; ++j)
            m[i%2][j] = 0;
        for (int j = i+1; j <= n; ++j)
            m[i%2][j] = (m[i%2][j-i] + m[1-(i%2)][j-1])%M;
    }
    fout << m[k%2][n] << "\n";
    fin.close();
    fout.close();
    return 0;
}
