#include <bits/stdc++.h>
 
using namespace std;
 
ofstream fout ("triunghi.out");
int n, s, coef[25], pascal[25][25], v[25], m[25][25];
bool gameover;
 
void bkt(int k, int sum, int last = 1)
{
    if(k == n+1){
        if(sum == 0){
            gameover = true;
            for (int i = 1; i <= n; ++i)
                m[1][i] = v[i];
            for (int i = 2; i <= n; ++i)
                for (int j = 1; j <= n-i+1; ++j)
                    m[i][j] = m[i-1][j]+m[i-1][j+1];
            for (int i = n; i >= 1; --i){
                for (int j = 1; j <= n-i+1; ++j)
                    fout << m[i][j] << " ";
                fout << "\n";
            }
        }
    }else{
        for (int i = last; !gameover; ++i){
            int S = i*coef[k];
            for (int j = k+1; j <= n; ++j)
                S += 1*coef[j];
            if(S > sum)
                break;
            v[k] = i;
            bkt(k+1, sum-i*coef[k], i);
        }
    }
}
 
int main()
{
    ifstream fin ("triunghi.in");
    fin >> n >> s;
    for (int i = 1; i <= n; ++i)
        coef[i] = 1;
    pascal[0][0] = 1;
    for (int i = 1; i <= n-1; ++i){
        pascal[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        int l = 1, r = i+1;
        while(r <= n){
            for (int j = l; j <= r; ++j)
                coef[j] += pascal[i][j-l];
            ++l;++r;
        }
    }
    bkt(1, s);
    if(!gameover)
        fout << "imposibil\n";
    return 0;
}
