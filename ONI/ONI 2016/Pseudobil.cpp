#include <fstream>
using namespace std;
bool v[3005][3005];
int nr[3005][3005];
int main()
{
    FILE*fin=fopen("pseudobil.in","r");
    FILE*fout=fopen("pseudobil.out","w");
    int k,p,d,n,i,j,x1,y1,x,y,m;
    fscanf(fin,"%d%d%d%d",&p,&n,&k,&d);
    if(p==1)
        fprintf(fout,"%d",d*d/2-d+1);
    else
    {
        for(;k>0;--k)
            {
                fscanf(fin,"%d%d",&i,&j);
                v[i+j-1][n-i+j]=1;
            }
        for (i=1;i<=2*n-1;++i)
            for (j=1;j<=2*n-1;++j)
                nr[i][j]=nr[i-1][j]+nr[i][j-1]-nr[i-1][j-1]+v[i][j];
        fscanf(fin,"%d",&m);
        for(;m>0;--m)
        {
            fscanf(fin,"%d%d",&x,&y);
            x1=x+y-1;y1=n-x+y;
            k=nr[x1+d][y1]-nr[x1+d][y1-d-1]-nr[x1-1][y1]+nr[x1-1][y1-d-1];
            fprintf(fout,"%d\n",k);
        }
    }
    return 0;
}
