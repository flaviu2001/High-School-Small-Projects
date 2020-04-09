#include <fstream>

using namespace std;
int platan[101][361],frq[101];
int main()
{
    FILE*fin=fopen("defrag.in","r");
    FILE*fout=fopen("defrag.out","w");
    int test,pista,sector,pistaMax,sectorMax,ocupat,contor,i,j,x,y,minim,k;
    fscanf(fin,"%d%d%d%d",&test,&pistaMax,&sectorMax,&ocupat);
    if(test==1)
    {
        contor=pistaMax;
        for(;ocupat>0;--ocupat)
        {
            fscanf(fin,"%d%d",&pista,&sector);
            ++frq[pista];
            if(frq[pista]==1)--contor;
        }
        fprintf(fout,"%d",contor);
    }
    else
    {
        for(;ocupat;--ocupat)
            {
            fscanf(fin,"%d%d",&pista,&sector);
            platan[pista][sector]=1;
            ++platan[pista][0];
            }
        for(pista=1;pista<=pistaMax;++pista)
        {
            minim=platan[pista][0];
            x=platan[pista][0];
            for(i=1;i<=sectorMax-x+1;++i)
            {
                contor=0;
                for(j=i;j<i+x;++j)
                    if(platan[pista][j]==0)++contor;
                if(contor<minim)minim=contor;
            }
            for(i=sectorMax-x+2;i<=sectorMax;++i)
            {
                contor=0;y=sectorMax-i;k=0;
                for(j=i;j<=sectorMax;++j)
                    {
                        if(platan[pista][j]==0)++contor;
                        ++k;
                    }
                for(j=1;j<=x-k;++j)
                    if(platan[pista][j]==0)++contor;
                if(contor<minim)minim=contor;
            }
            fprintf(fout,"%d ",minim);
        }
    }
    return 0;
}
