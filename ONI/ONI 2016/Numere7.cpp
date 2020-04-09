#include <fstream>
using namespace std;
int v[250001];
int main()
{
    FILE*fin=fopen("numere7.in","r");
    FILE*fout=fopen("numere7.out","w");
    int n,a,b,x,i,m;
    bool ok=1;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n*n;++i)
    {
        fscanf(fin,"%d",&x);
        if(x!=0)v[x]=1;
    }
    for(i=1;v[i]==1;++i);fprintf(fout,"%d ",i);
    for(i=n*n;v[i]==1;--i);fprintf(fout,"%d",i);
    return 0;
}
