#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1005];
int p, n;

void read()
{
    ifstream fin ("reziston.in");
    fin.getline(s, 1005);
    n = strlen(s);
    fin.close();
}

int calc_serie();

int calc_paralel()
{
    //++p; //trec de (
    int prod = 1, sum = 0, x;
    do{
        ++p;
        x = calc_serie();
        prod *= x;
        sum += x;
    }while(s[p] != ')');
    ++p; //trec de )
    return prod/sum;
}

int calc_serie()
{
    int r = 0;
    while(p < n){
        if(s[p] == '(')
            r += calc_paralel();
        if(s[p] == ',')
            return r;
        if(s[p] == ')')
            return r;
        if(s[p] == 'R'){
            ++p; // trec de caracter
            int x = 0;
            while(s[p] >= '0' && s[p] <= '9'){
                x = x * 10 + s[p] - '0';
                ++p;
            }
            r += x;
        }
    }
    return r;
}

void write()
{
    ofstream fout ("reziston.out");
    fout << calc_serie() << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}

