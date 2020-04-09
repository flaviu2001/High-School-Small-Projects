#include <bits/stdc++.h>
 
using namespace std;

//Import Int class and use Int

int n;
int pd[205][205], m;//here
 
int main()
{
    ifstream fin ("arbsort.in");
    ofstream fout ("arbsort.out");
    fin >> n >> m;
    --n;
    pd[n][n] = 1;
    for (int i = n-1; i >= 1; --i)
        pd[n][i] = pd[n][i+1]+1;
    for (int i = n-1; i >= 1; --i){
        pd[i][i] = pd[i+1][i];
        for (int j = i-1; j >= 1; --j)
            pd[i][j] = pd[i][j+1] + pd[i+1][j];
    }
    fout << "0 1 ";
    int last = 1;
    for (int p = 2; p <= n; ++p){
        int now = last;
        while(now < p && pd[p][now]-pd[p][now+1] < m){
            m = m - (pd[p][now]-pd[p][now+1]);
            ++now;
        }
        last = now;
        fout << last << " ";
    }
    return 0;
}
