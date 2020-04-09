/*   You have lost, my dear   */

#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#define mod 1000000007
using namespace std;
long long n,sol;
long long fact[100002],inv[100002];
int fr[12];
int pi;
void bkt(int nc, int pr, int s, int ld)
{
    if(pr==1)
    {
        if(s+(n-nc)!=pi)
            return;
        fr[1]=pi-s;
        long long pot=fact[n];
        for(int j=1;j<=9;++j)
            pot=(pot*inv[fr[j]])%mod;
        sol=(sol+pot)%mod;
        return;
    }
    for(int j=ld;j<=9;++j)
        if(pr%j==0){
            fr[j]++;
            bkt(nc+1,pr/j,s+j,j);
            fr[j]--;
        }
}
long long lgput(long long b, long long ex)
{
    long long sol=1;
    while(ex)
    {
        if(ex&1)
            sol=(sol*b)%mod;
        b=(b*b)%mod;
        ex>>=1;
    }
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    if(n==1)
        sol=10;
    else
    {
        fact[0]=inv[0]=1;
        for(int j=1;j<=n;++j)
            fact[j]=(fact[j-1]*j)%mod,inv[j]=lgput(fact[j],mod-2);
        for(int j=1;j<=9*n;++j)
            pi=j,bkt(0,j,0,2);
        cout<<sol<<'\n';
    }
    return 0;
}
