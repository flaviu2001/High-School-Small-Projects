#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int v[11],r[4001];

int main()
{
    ifstream fin ("pluton.in");
    ofstream fout ("pluton.out");
    int n,o,i,p=1,k=0,y,s,a1=0,a2=0,a3=1;
    fin>>n;s=n;a1=n;
    for(;n>0;--n)
    {
        fin>>o;i=1;k=0;
        while(o>0){v[i]=o%10;o/=10;++i;++k;}
        sort (v+1,v+k+1);y=0;
        for(i=k;i>0;--i)y=y*10+v[i];
        r[p]=y;++p;
    }
    sort(r+1,r+s+1);k=1;
    for(i=2;i<=s;i++)
    {
        if(r[i-1]==r[i])
        {
            --a1;++k;
            if(k>a2)
            {a2=k;a3=1;}
            else if(k==a2)++a3;
        }
        else k=1;
    }
    fout<<a1<<'\n'<<a2<<'\n'<<a3;
    return 0;
}