#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[20005];
int f[256], p;
bool exists[256];

int switch_neg(int neg)
{
    if(neg == -1)
        return 1;
    return -1;
}

void termen(int);

void eval(int neg)
{
    termen(neg);
    while(s[p] == '/' || s[p] == '*')
        switch(s[p]){
            case '/':
                ++p;
                termen(switch_neg(neg));
                break;
            case '*':
                ++p;
                termen(neg);
                break;
        }
}

void termen(int neg)
{
    if(s[p] == '('){
        ++p;
        eval(neg);
        ++p;
    }else{
        if(s[p] >= 'a' && s[p] <= 'z')
            f[s[p]] += neg;
        exists[s[p]] = 1;
        ++p;
    }
}

int main()
{
    ifstream fin ("expresie2.in");
    ofstream fout ("expresie2.out");
    fin.getline(s, 20005);
    eval(1);
    for (int i = 'a'; i <= 'z'; ++i)
        if(exists[i])
            fout << (char)i << " " << f[i] << "\n";
    return 0;
}

