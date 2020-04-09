#include <fstream>

using namespace std;

int s[201],v[101];

int main()
{
    FILE*fin=fopen("noroc.in","r");
    FILE*fout=fopen("noroc.out","w");
    int n,i,j,s;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;++i)
        fscanf(fin,"%d",&v[i]);
    for(i=1;i<=n;++i)
    {
        s=(v[i]*v[i]);
        for(j=i+1;j<=n;++j)
        {
            s+=(v[j]*v[j]);
            if(s%n==0)
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
