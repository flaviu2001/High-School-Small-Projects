#include <fstream>

using namespace std;

int main()
{
    FILE*fin=fopen("cifre.in","r");
    FILE*fout=fopen("cifre.out","w");
    int test;
    long long int number;
    fscanf(fin,"%d%lld",&test,&number);
    if(test==1)
    {
        int segments=0;
        while(number>0)
        {
            if(number%10==0 || number%10==6 || number%10==9) segments+=6;
                else if(number%10==1) segments+=2;
                    else if(number%10==2 || number%10==3 || number%10==5) segments+=5;
                        else if(number%10==4) segments+=4;
                            else if(number%10==7) segments+=3;
                                else segments+=7;
            number/=10;
        }
        fprintf(fout,"%d",segments);
    }
    else
    {
        long long int combinations=1;
        bool notZero=0;
        while(number>0)
        {
            if(number%10==0 || number%10==2) combinations*=2, notZero=1;
                else if(number%10==1) combinations*=6, notZero=1;
                    else if(number%10==3 || number%10==4 || number%10==6 || number%10==7)combinations*=3;
                        else if(number%10==5) combinations*=4;
            number/=10;
        }
        fprintf(fout,"%lld",--combinations);
    }
    return 0;
}
