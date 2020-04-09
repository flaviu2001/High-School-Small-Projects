#include <fstream>
#include <iostream>
using namespace std;
int v[100001];
char q[100001];
int main()
{
    ifstream fin("vase.in");
    ofstream fout("vase.out");
    int n,x,i;
    long long s=0,y=0,s1,d1;
    fin>>n;
	for(i=1;i<=n;++i)
		{
            fin>>v[i]>>q[i];
            s+=v[i];
		}
    fout<<s/2<<"\n";
	fin>>x;
	for(i=1;i<x;++i)
        y+=v[i];
    y/=2;
    if(q[x]=='S')
        {
            s1=-y-v[x]/2;
            d1=-y+v[x]/2;
        }
    else
        {
            s1=y-v[x]/2;
            d1=y+v[x]/2;
        }
    for(i=x+1;i<=n;++i)
    {
		if(q[i]=='S')
			{
			    s1=s1+v[i]/2;
			    d1=d1+v[i]/2;
			}
		else
			{
                s1=s1-v[i]/2;
                d1=d1-v[i]/2;
			}
    }
    if(s1>=0)
		fout<<d1<<" D\n"<<s1<<" D\n";
	else
		if(d1<=0)
            fout<<-s1<<" S\n"<<-d1<<" S\n";
		else
            fout<<-s1<<" S\n"<<d1<<" D\n";
    return 0;
}
