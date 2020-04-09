#include <fstream>

using namespace std;
int v[51][51],r[51][51],t[51][51],q[51][51];
int main()
{
    FILE*fin=fopen("cartele.in","r");
    FILE*fout=fopen("cartele.out","w");
    int n,m,i,j,o,g;
    fscanf(fin,"%d%d",&n,&m);
    bool ok;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            {
                fscanf(fin,"%d",&o);
                v[i][j]=o;
            }
    for(;m>0;--m)
    {
        ok=1;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                {
                    fscanf(fin,"%d",&o);
                    r[i][j]=o;
                    q[i][j]=o;
                }
        for(i=1;i<=n&&ok;++i)
            for(j=1;j<=n&&ok;++j)
                ok=v[i][j]==r[i][j];
        for(g=1;g<=4&&!ok;++g)
        {
            ok=1;
            for(i=1;i<=n;++i)
                for(j=1;j<=n;++j)
                    t[i][j]=r[n-j+1][i];
            for(i=1;i<=n;++i)
                for(j=1;j<=n;++j)
                    r[i][j]=t[i][j];
            for(i=1;i<=n&&ok;++i)
                for(j=1;j<=n&&ok;++j)
                    ok=v[i][j]==t[i][j];
            if(!ok){ok=1;
            for(i=1;i<=n&&ok;++i)
                for(j=1;j<=n&&ok;++j)
                    ok=v[i][j]==t[n-i+1][j];}
            if(!ok){ok=1;
            for(i=1;i<=n&&ok;++i)
                for(j=1;j<=n&&ok;++j)
                    ok=v[i][j]==t[i][n-j+1];}
        }
            fprintf(fout,"%d\n",ok);
    }
    return 0;
}