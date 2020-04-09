#include <fstream>
using namespace std;
int v[151][102];
int main()
{
    FILE*fin=fopen("flori.in","r");
    FILE*fout=fopen("flori.out","w");
    int n,k,x,i,j,y,p;
    bool ok;
    fscanf(fin,"%d%d",&n,&k);
    for(i=1;i<=n;++i)
    {
        v[i][0]=i;
        for(j=1;j<=k;++j)
            {
                fscanf(fin,"%d",&x);
                v[i][x+1]=1;
            }
    }
    for(i=1;i<=n;++i)
        for(k=i+1;k<=n;++k)
        {
            x=v[i][0];y=v[k][0];
            if(x!=y)
                for(j=1;j<102;++j)
                    if(v[i][j]+v[k][j]==2)
                        for(p=1;p<=n;++p)
                            if(v[p][0]==v[k][0])v[p][0]=x;
        }
    for(i=1;i<=n;++i)
    {
        ok=0;
        for(j=1;j<=n;++j)
            if(v[j][0]==i){fprintf(fout,"%d ",j);ok=1;}
        if(ok)fprintf(fout,"\n");
    }
    return 0;
}