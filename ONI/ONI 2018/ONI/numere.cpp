#include <bits/stdc++.h>

using namespace std;

long long n, v[15], p, factorial[25], sol[25];

int main()
{
    factorial[0] = 1;
    for (int i = 1; i <= 20; ++i)
        factorial[i] = 1LL*factorial[i-1]*i;
    ifstream fin ("numere7.in");
    ofstream fout ("numere7.out");
    fin >> n;--n;
    char q;
    while(fin >> q)
        ++v[q-'0'],
        ++p;
    for (int i = 1; i <= p; ++i){
        int in;
        for (int j = 1; j <= 9; ++j)
            if(v[j]){
                in = j;
                break;
            }
        for  (int j = 1; j <= 9; ++j)
            if(v[j]){
                long long sum = factorial[p-i];
                --v[j];
                for (int k = 1; k <= 9; ++k)
                    sum /= factorial[v[k]];
                ++v[j];
                if(n >= sum){
                    n -= sum;
                    for (int k = j+1; k <= 9; ++k)
                        if(v[k]){
                            in = k;
                            break;
                        }
                }else break;
            }
        --v[in];
        //cout << in << "\n";
        sol[i] = in;
    }
    for (int i = 1; i <= p; ++i)
        fout << sol[i];
    fin.close();
    fout.close();
    return 0;
}

