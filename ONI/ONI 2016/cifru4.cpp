#include <fstream>

using namespace std;

int v[10];

int main()
{
    FILE*fin=fopen("cifru4.in","r");
    FILE*fout=fopen("cifru4.out","w");
    int n,nc,k=0,d=1,i,j,s1=0,s2=0;
    fscanf(fin,"%d",&n);
    nc=n;
    while(nc>0)
        ++k, nc/=10;
    for(i=1;i<=k;++i)
    {
        v[i]=n/d;
        d*=10;
        if(v[i]%k==0)++s1;
    }
    printf("%d\n",s1);
    for(i=1;i<k;++i)
        for(j=i+1;j<=k;++j)
            if((v[i]-v[j])%k==0 && v[i]%k!=0)
                ++s2;
    fprintf(fout,"%d",s1+s2);
    return 0;
}