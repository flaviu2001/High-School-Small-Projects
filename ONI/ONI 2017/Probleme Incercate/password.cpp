#include<cstdio>
#include<string.h>

char s[200005],sol[200005];

int main()
{
   freopen("password.in","r",stdin);
   freopen("password.out","w",stdout);
   int n,i,n1,nr=0;char aux;
   gets(s);n1=strlen(s);
   strcpy(sol,s);
   strcat(s,sol);
   n=strlen(s)-1;s[n]=0;
   for ( i = 0;i < n1; ++i )
      {
          aux=s[i+n1];s[i+n1]=0;
          if(strcmp(s+i,sol)<0)
              strcpy(sol,s+i),
              nr=i;
          s[i+n1]=aux;
      }
   printf("%d\n",nr);
   return 0;
}
