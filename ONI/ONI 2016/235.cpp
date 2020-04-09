#include <fstream>

using namespace std;
int r[40001],v[]={3 , 5 , 9 , 25 , 27 , 81 , 125 , 243 , 625 , 729 , 2187 , 3125 , 6561 , 15625 , 19683 , 59049 , 78125 , 177147 , 390625 , 531441 , 1594323 , 1953125 , 4782969 , 9765625 , 14348907 , 43046721 , 48828125 , 129140163 , 244140625 , 387420489 , 1162261467 , 1220703125};
int main()
{
    FILE*fin=fopen("235.in","r");
    FILE*fout=fopen("235.out","w");
    int n,x,s,d,m,p=0,i,j,k,s1,s2,y=0;
    bool ok;
    fscanf(fin,"%d",&n);
    for(;n>0;--n)
    {
        fscanf(fin,"%d",&x);
        s=0;d=32;ok=1;
        while(s<=d&&ok)
        {
            m=(s+d)/2;
            if(x<v[m])
                d=m-1;
                else if(x>v[m])
                    s=m+1;
                    else ok=0;
        }
        if(!ok)
        {
            ++p;
            if(x%3==0)r[p]=1;
                else r[p]=2;
        }
    }
    fprintf(fout,"%d\n",p);
    for(i=2;i<=p;i*=2)
    {
        s1=0;s2=0;
        for(j=1;j<=i;++j)
        {
            if(r[j]==1)++s1;
            else ++s2;
        }
        if(s1==s2)++y;
        for(;j<=p;++j)
        {
            if(r[j-i]==1)--s1;
            else --s2;
            if(r[j]==1)++s1;
            else ++s2;
            if(s1==s2)++y;
        }
    }
    fprintf(fout,"%d",y);
    return 0;
}
