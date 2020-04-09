#include <bits/stdc++.h>

using namespace std;

int64_t test, fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55}, comb[55][55];

int64_t query(int64_t b)
{
    if(b == 0)
        return 0;
    if(b == 1)
        return 1;
    int64_t a = b, sol = 0, tot = 0;
    vector<int64_t> v;
    while(a){
        v.push_back(a%2);
        tot += v.back();
        a /= 2;
    }
    reverse(v.begin(), v.end());
    for (int64_t t = 0; t <= 8; ++t){
        if(tot == fib[t])
            ++sol;
        int64_t totdigs = fib[t], cur = 0;
        for (unsigned j = 0; j < v.size(); ++j)
            if(v[j] == 1){
                if(totdigs-cur <= v.size()-j-1 && v.size()-j-1 >= 0 && totdigs-cur >= 0)
                    sol += comb[v.size()-j-1][totdigs-cur];
                ++cur;
                if(cur > totdigs)
                    break;
            }
    }
    return sol;
}

int main()
{
    ifstream fin ("fibocel.in");
    ofstream fout ("fibocel.out");
    fin >> test;
    comb[0][0] = 1;
    for (int64_t i = 1; i < 55; ++i){
        comb[i][0] = 1;
        for (int64_t j = 1; j <= i; ++j)
            comb[i][j] = comb[i-1][j]+comb[i-1][j-1];
    }
    while(test--){
        int64_t a, b;
        fin >> a >> b;
        fout << query(b)-query(a-1) << "\n";
    }
    return 0;
}

