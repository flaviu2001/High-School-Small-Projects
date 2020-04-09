#include <fstream>

using namespace std;
int v[2001],r[2001];
int main()
{
    FILE*fin=fopen("impartire.in","r");
    FILE*fout=fopen("impartire.out","w");
    int c,n,i,x,d=0,ok=1;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;++i)
        fscanf(fin,"%d",&v[i]);
    fscanf(fin,"%d",&c);
    x=0;
    for(i=1;i<=n;++i)
    {
        x=x*10+v[i];
        ++d;
        r[d]=x/c;
        x=x%c;
    }
    i=1;
    while(r[i]==0)++i;
    for(;i<=d;++i)fprintf(fout,"%d",r[i]);
    return 0;
}