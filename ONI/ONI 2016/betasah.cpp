#include <fstream>

using namespace std;

int v[1001][1001];

int main()
{
    FILE*fin=fopen("betasah.in","r");
    FILE*fout=fopen("betasah.out","w");
    int n,d,m,i,j,m1=0,p,k=0;
    fscanf(fin,"%d%d%d",&n,&d,&m);
    for(;d>0;--d)
    {
        fscanf(fin,"%d%d",&i,&j);
        v[i][j]=2;
    }
    for(;m>0;--m)
    {
        fscanf(fin,"%d%d",&i,&j);
        v[i][j]=1;
        ++v[i][0];
    }
    for(i=1;i<=n;++i)
    {
        p=i-v[i][0];
        if(p>m1)m1=p;
        for(j=1;j<=i;++j)
        {
            if(v[i][j]==2)
            {
                for(p=i+1;p<=n;++p)
                {
                    if(v[p][j]==0){++k;v[p][j]=3;}
                        else if(v[p][j]==1||v[p][j]==2) break;
                }
                for(p=i-1;p>=j;--p)
                {
                    if(v[p][j]==0){++k;v[p][j]=3;}
                        else if(v[p][j]==1||v[p][j]==2) break;
                }
                for(p=j-1;p>=1;--p)
                {
                    if(v[i][p]==0){++k;v[i][p]=3;}
                        else if(v[i][p]==1||v[i][p]==2) break;
                }
                for(p=j+1;p<=i;++p)
                {
                    if(v[i][p]==0){++k;v[i][p]=3;}
                        else if(v[i][p]==1||v[i][p]==2) break;
                }
                for(p=1;j-p>=1;++p)
                {
                    if(v[i-p][j-p]==0){++k;v[i-p][j-p]=3;}
                        else if(v[i-p][j-p]==1||v[i-p][j-p]==2) break;
                }
                for(p=1;i+p<=n;++p)
                {
                    if(v[i+p][j+p]==0){++k;v[i+p][j+p]=3;}
                        else if(v[i+p][j+p]==1||v[i+p][j+p]==2) break;
                }
                for(p=1;j+2*p<=i;++p)
                {
                    if(v[i-p][j+p]==0){++k;v[i-p][j+p]=3;}
                        else if(v[i-p][j+p]==1||v[i-p][j+p]==2) break;
                }
                for(p=1;i+p<=n&&j-p>=1;++p)
                {
                    if(v[i+p][j-p]==0){++k;v[i+p][j-p]=3;}
                        else if(v[i+p][j-p]==1||v[i+p][j-p]==2) break;
                }
            }
        }
    }
    fprintf(fout,"%d\n%d",m1,k);
    return 0;
}
