#include <bits/stdc++.h>
 
using namespace std;
 
typedef long double ll;
int n, a[2];
int pd[2][105][105][40], k[40];
char s[40];
 
void Add(int A[], int B[])
{   int i,t=0;
    for(i=1;i<=A[0]||i<=B[0]||t;++i,t/=10) A[i]=(t+=A[i]+B[i])%10;
    A[0]=i-1;
}
void Scad(int A[], int B[])
{   int i,t=0;
    for(i=1;i<=A[0];++i)
    {   if(i<=B[0]) A[i]=A[i]-B[i]-t; else A[i]=A[i]-t;
        if(A[i]<0) {t=1; A[i]+=10;} else t=0;
    }
    while(A[0]>1 && A[A[0]]==0) A[0]--;
}
int Compara(int A[], int B[])
{   if(A[0]<B[0]) return -1;
    if(A[0]>B[0]) return 1;
    for(int i=A[0];i;--i)
    {   if(A[i]<B[i]) return -1;
        if(A[i]>B[i]) return 1;
    }
    return 0;
}
 
int main()
{
    ifstream fin ("pavare2.in");
    ofstream fout ("pavare2.out");
    fin >> n >> a[0] >> a[1];
    for (int i = 1; i <= a[0]; ++i){
        pd[0][i][0][0] = 1;
        pd[0][i][0][1] = 1;
    }
    for (int i = 1; i <= a[1]; ++i){
        pd[1][i][0][0] = 1;
        pd[1][i][0][1] = 1;
    }
    for (int i = 1; i < n; ++i)
        for (int t = 0; t < 2; ++t)
            for (int j = 1; j <= a[t] && j+i <= n; ++j)
                for (int k = 1; k <= a[1-t] && k <= i; ++k)
                    Add(pd[t][j][i], pd[1-t][k][i-k]);
    int ans[40], ans2[40];
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for (int i = 1; i <= a[0]; ++i)
        Add(ans, pd[0][i][n-i]);
    for (int i = 0; i < 40; ++i)
        ans2[i] = ans[i];
    for (int i = 1; i <= a[1]; ++i)
        Add(ans, pd[1][i][n-i]);
    for (int i = ans[0]; i >= 1; --i)
        fout << ans[i];
    fout << "\n";
    fin >> (s+1);
    int ns = strlen(s+1);
    for (int i = 1; i <= ns; ++i)
        k[i] = s[ns-i+1]-'0';
    k[0] = ns;
    int p = 1, type;
    if(Compara(k, ans2) == 1){
        Scad(k, ans2);
        type = 1;
    }else type = 0;
    while(p <= n){
        int rem = n-p+1;
        if(type == 0){
            int last = a[0];
            int all[40];
            memset(all, 0, sizeof(all));
            all[0] = 1;
            for (int i = a[0]; i >= 1; --i){
                Add(all, pd[0][i][rem-i]);
                if(Compara(all, k) >= 0){
                    last = i;
                    break;
                }
            }
            Add(k, pd[0][last][rem-last]);
            Scad(k, all);
            for (int i = 1; i <= last; ++i){
                fout << 0;
                ++p;
            }
        }else{
            int first = 1;
            int all[40];
            memset(all, 0, sizeof(all));
            all[0] = 1;
            for (int i = 1; i <= a[1]; ++i){
                Add(all, pd[1][i][rem-i]);
                if(Compara(all, k) >= 0){
                    first = i;
                    break;
                }
            }
            Add(k, pd[1][first][rem-first]);
            Scad(k, all);
            for (int i = 1; i <= first; ++i){
                fout << 1;
                ++p;
            }
        }
        type = 1-type;
    }
    return 0;
}
