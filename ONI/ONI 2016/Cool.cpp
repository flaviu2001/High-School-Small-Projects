#include <fstream>
#include <algorithm>
using namespace std;
int v[5001],r[1003];
int main()
{
    FILE*fin=fopen("cool.in","r");
    FILE*fout=fopen("cool.out","w");
    int test,n,k,x,i,z=0,j,m1,m2,m3=0,u=1;
    bool ok=1,ko;
    fscanf(fin,"%d%d%d",&test,&n,&k);
    for(i=1;i<=n;++i)
    {
        fscanf(fin,"%d",&x);
        v[i]=x;
    }
    if(test==1)
    {
        sort(v+1,v+k+1);
        for(i=2;i<=k;++i)
            if(v[i]!=v[i-1]+1)
                ok=0;
        for(i=1;i<k;++i)
        {
            if(v[i]!=v[i+1]&&v[i+1]!=v[i+2])
            {
            ++z;
            ko=1;
            }
        }
        if(!ko)z=0;
        if(ok)fprintf(fout,"%d",v[k]);
            else fprintf(fout,"%d",z);
    }
    else
    {
        for(i=1;i<n;++i)
        {
            m1=v[i];m2=v[i];
            r[v[i]]=1;
            for(j=i+1;j<=n;++j)
            {
                if(r[v[j]])break;
                r[v[j]]=1;
                if(v[j]>m1)m1=v[j];
                if(v[j]<m2)m2=v[j];
                k=j-i+1;
                if(m1-m2==k-1)
                {
                    if(k>m3)m3=k, u=1;
                    else if(k==m3)++u;
                }
            }
            fill(r,r+1002,0);
        }
        fprintf(fout,"%d\n%d",m3,u);
    }
    return 0;
}
