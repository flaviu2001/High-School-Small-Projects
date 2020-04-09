#include <bits/stdc++.h>

using namespace std;

const int M = 1999999973;
int64_t a, b, p = 1;

int main()
{
    ifstream fin ("lgput.in");
    ofstream fout ("lgput.out");
    fin >> a >> b;
    while(b)
        if(b%2 == 0){
            a = (a*a)%M;
            b >>= 1;
        }else{
            p = (p*a)%M;
            --b;
        }
    fout << p << "\n";
    return 0;
}

