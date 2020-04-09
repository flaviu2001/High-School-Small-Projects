#include <fstream>
using namespace std;
char a[60001],b[9];
int d[60001];
int main()
{
    FILE*fin=fopen("paritate.in","r");
    FILE*fout=fopen("paritate.out","w");
    int i,k,n,m,p=0,f=0,m1=60002;
    char x,y;
    bool ok=1;
    do
    {
        k=0;n=0;m=0;
        for(i=1;i<=8;++i)
        {
            fscanf(fin,"%c",&x);
            b[i]=x;
            if(i!=2)k=k+x-'0';
        }
        if(k%2!=b[2]-'0')
            {
                ok=0;
                if(p<m1)m1=p;
                d[f]=p;
                ++f;
            }
        for(i=1;i<=8;++i)
            n=n*2+b[i]-'0';
        n=n%128;
        y=n;
        a[p]=y;
        ++p;
    }while(x!='\n');
    if(ok||m1==p-1)
    {
        fprintf(fout,"DA\n");
        for(i=0;i<p-1;++i)fprintf(fout,"%c",a[i]);
    }
    else
    {
        fprintf(fout,"NU\n");
        for(i=0;i<f-1;++i)
            fprintf(fout,"%d ",d[i]);
    }
    return 0;
}