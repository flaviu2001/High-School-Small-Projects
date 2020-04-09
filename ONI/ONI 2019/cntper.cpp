#include <bits/stdc++.h>

using namespace std;

const int M = 666013;
int n, test, v[1000005];

int main()
{
    ifstream fin ("cntper.in");
    ofstream fout ("cntper.out");
    fin >> test;
    v[1] = 26;
    for (int i = 2; i <= 1000000; ++i)
        v[i] = (v[i-1]*26)%M;
    for (int i = 1; i <= 1000000; ++i)
        for (int j = i+i; j <= 1000000; j += i){
            v[j] -= v[i];
            if(v[j] < 0)
                v[j] += M;
        }
    while(test--){
        int n;
        fin >> n;
        fout << v[n] << "\n";
    }
    return 0;
}

