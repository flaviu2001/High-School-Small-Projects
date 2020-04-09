//If there is at least one period, it is sufficient to check for only the edges of the periods when going through them.
//No idea how to figure out if there is however one period at least.
#include <bits/stdc++.h>

using namespace std;

int n, sol;
char c[10000005];

int main()
{
    ifstream fin ("perioada2.in");
    ofstream fout ("perioada2.out");
    fin >> n >> c+1;
    for (int i = 1; i <= n/2; ++i)
        if(n%i == 0){
            bool good = true;
            for (int j = i+1; j <= n && good; j += i)
                if(c[j] != c[j-i] || c[j+i-1] != c[j-1])
                    good = false;
            if(good)
                ++sol;
        }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

