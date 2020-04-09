/*
    evaluare.in:
        (1+1)*13+10/2

    evaluare.out:
        31
*/


#include <fstream>
#include <cstdio>

using namespace std;

char s[100010];
int p;

int termen();
int factor();

int eval()
{
    int r = termen();
    while(s[p] == '+' || s[p] == '-'){
        switch(s[p]){
            case '+':
                ++p;
                r += termen();
                break;
            case '-':
                ++p;
                r -= termen();
                break;
        }
    }
    return r;
}

int termen()
{
    int r = factor();
    while(s[p] == '*' || s[p] == '/'){
        switch(s[p]){
            case '*':
                ++p;
                r *= factor();
                break;
            case '/':
                ++p;
                r /= factor();
                break;
        }
    }
    return r;
}

int factor()
{
    int r = 0;
    if(s[p] == '('){
        ++p;
        r = eval();
        ++p;
    }else{
        while(s[p] >= '0' && s[p] <= '9'){
            r = r * 10 + s[p] - '0';
            ++p;
        }
    }
    return r;
}

int main()
{
    ifstream fin ("evaluare.in");
    ofstream fout ("evaluare.out");
    fin.getline(s, 100010);

    fout << eval() << "\n";

    fin.close();
    fout.close();
    return 0;
}
