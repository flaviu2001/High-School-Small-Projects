#include <fstream>
int v[1000001];
using namespace std;

int main()
{
    FILE*fin=fopen("eliminare.in","r");
    FILE*fout=fopen("eliminare.out","w");
    int i,p,n,q,x,m,s,d;
    bool ok,ko;
    fscanf(fin,"%d%d",&n,&q);
    for(p=1;p<=n;++p)
    {
        fscanf(fin,"%d",&x);
        v[p]=x;
    }
    for(;q>0;--q)
    {
        fscanf(fin,"%d",&x);
        p=n;
        s=1;d=n;ok=1;ko=0;
        while(s<=d&&ok)
        {
            m=(s+d)/2;
            if(x<v[m])
                d=m-1;
                else if(x>v[m])
                    s=m+1;
                    else {ok=0;m=x;}
        }
        if(ok&&x<v[m])--m;
        fprintf(fout,"%d\n",x-m);
    }
    return 0;
}
