#include <fstream>
using namespace std;
int v[700002];
int main()
{
    FILE*fin=fopen("livada1.in","r");
    FILE*fout=fopen("livada1.out","w");
    int m,n,p,i,x,k,j,y,a,l=0,q1=1,q2=1;
    fscanf(fin,"%d%d%d",&m,&n,&p);
    for(j=1;j<=m;++j)
    {
        k=1;a=0;q1=1;
        fscanf(fin,"%d",&x);
        v[1]=x;
        for(i=2;i<=n;++i)
            {
                fscanf(fin,"%d",&y);
                v[i]=y;
                if(x==y) ++k;
                else if(k>0){--k;q1=1;}
                    else{x=y;k=1;}
                if(v[i-1]==v[i])
                    {
                    ++q1;
                    if(q1>q2)
                        q2=q1;
                    }
            }
        for(i=1;i<=n;++i)if(x==v[i])++a;
        if(a>n/2)++l;
    }
    fprintf(fout,"%d\n%d",l,q2);
    return 0;
}