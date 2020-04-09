#include <fstream>

using namespace std;

int v[1001];

int main()
{
    FILE*fin=fopen("zid.in","r");
    FILE*fout=fopen("zid.out","w");
    int n,x,i,j,s,ok=0;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;++i)
        fscanf(fin,"%d",&v[i]);
    for(i=1;i<=n;++i)
    {
        s=v[i];
        for(j=i+1;j<=n;++j)
        {
            s+=v[j];
            if(v[i]+v[j]%n==0)
            {
                fprintf(fout,"2\n%d %d",v[i],v[j]);
                return 0;
            }
            else if(s%n==0)
            {
                fprintf(fout,"%d\n",j-i+1);
                for(;i<=j;++i)
                    fprintf(fout,"%d ",v[i]);
                return 0;
            }
        }
    }
    return 0;
}
