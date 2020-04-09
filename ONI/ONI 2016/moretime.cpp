#include <fstream>

using namespace std;

long long int v[10001], r[10001];

int main()
{
    FILE*fin=fopen("moretime.in","r");
    FILE*fout=fopen("moretime.out","w");
    long long int n,x,y,c,o,k=0,cx,s,i,j;
    fscanf(fin,"%lld",&n);
    for(;n>0;--n)
    {
        fscanf(fin,"%lld%lld",&x,&y);
        c=x%10, o=0, cx=x;
        while(x>0)
            o=o*10+x%10, x/=10;
        if(c==o%10)
            ++k, v[k]=cx, r[k]=y;
    }
    fprintf(fout,"%lld\n",k);
    for(i=1;i<=k;++i)
    {
        s=0;
        for(j=i;j<=k;++j)
        {
            s+=r[j];
            if(s%k==0)
            {
                fprintf(fout,"%lld\n",j-i+1);
                for(;i<=j;++i)
                    fprintf(fout,"%lld ",v[i]);
                return 0;
            }
        }
    }
    if ( k == 1 )
        fprintf( fout, "1\n%d", v[1] );
    return 0;
}