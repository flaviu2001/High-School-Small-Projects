#include <fstream>
using namespace std;
int v[8];
int main()
{
    FILE*fin=fopen("expresie.in","r");
    FILE*fout=fopen("expresie.out","w");
    long long n,x,y,z,i,s,s1,s2,m1,m2=0,m3=0;
    bool ok;
    fscanf(fin,"%lld%lld%lld%lld",&n,&z,&y,&x);
    s=x+y+z;
    m1=z*y;
    v[0]=z;
    v[1]=y;
    if(y*x>m1)
        {
            m2=m1;
            m1=x*y;
            v[2]=v[0];
            v[3]=v[1];
            v[0]=x;
            v[1]=y;
        }
    m3=z*y*x;
    v[4]=z;
    v[5]=y;
    v[6]=x;
    for(i=4;i<=n;++i)
    {
        z=y;y=x;
        fscanf(fin,"%lld",&x);
        s+=x;
        if(x*y>=m1)
            {
                m2=m1;
                v[2]=v[0];
                v[3]=v[1];
                m1=x*y;
                if(x*y==m1)
                {
                v[0]=x;
                v[1]=y;
                }
            }
            else if(x*y>m2&&x+y>v[2]+v[3])
                {
                    m2=x*y;
                    v[2]=x;
                    v[3]=y;
                }
        if(x*y*z>=m3)
            {
                m3=x*y*z;
                if(x+y+z>v[4]+v[5]+v[6])
                {
                v[4]=x;
                v[5]=y;
                v[6]=z;
                }
            }
    }
    s1=s-v[0]-v[1]-v[2]-v[3]+m1+m2;
    s2=s-v[4]-v[5]-v[6]+m3;
    s=s1;if(s2>s)s=s2;
    fprintf(fout,"%lld",s);
    return 0;
}