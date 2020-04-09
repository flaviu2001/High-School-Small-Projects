#include <fstream>

using namespace std;

int main()
{
    FILE*fin=fopen("fact.in","r");
    FILE*fout=fopen("fact.out","w");
    int p, i, s, j;
    fscanf(fin,"%d",&p);
    if(p==0)
        fprintf(fout,"1");
    else if(p<5)
        fprintf(fout,"%d",p*5);
    else if(p>=5)
    {
        i=p*4;
        while(1==1)
        {
            s=0;
            for(j=5;j<=i;j*=5)
                s=s+i/j;
            if(s>p)
            {
                fprintf(fout,"-1");
                return 0;
            }
            else if(s==p)
            {
                fprintf(fout,"%d",i/5*5);
                return 0;
            }
            i+=5;
        }
    }
    return 0;
}
