#include <fstream>
#include <cmath>
using namespace std;
int v[29991];
int main()
{
    FILE*fin=fopen("exp1.in","r");
    FILE*fout=fopen("exp1.out","w");
    int m,n,x,p=1,i,d;
    bool ok=0;
    fscanf(fin," %d %d ",&m,&n);
    for( ; n>0 ; --n)
    {
        fscanf(fin,"%d",&x);
        p*=x;d=2;
        while(x>1)
        {
            i=0;
            while(x%d==0){++i;x/=d;}
            v[d]+=i;++d;
        }
    }
    for(i=2;i<=29989;++i)
    {
        if(v[i]!=0&&v[i]%m!=0)
        ok=1;
    }
    if(ok)fprintf(fout,"0");
    else
    {
    fprintf(fout,"1\n");
    for(i=2;i<=29989;++i)
    {
        if(v[i]!=0&&v[i]%m==0)
        fprintf(fout,"%d %d\n",i,v[i]/m);
    }
    }
    return 0;
}