#include <bits/stdc++.h>
 
using namespace std;
 
int factorial[60005], q, I, J, M, a, b;
 
int paritate(int i1, int j1)
{
    int x = factorial[i1]-factorial[i1-j1]-factorial[j1];
    return x > 0;
}
 
int xormatrix(int i1, int j1)
{
    if(i1 == 0)
        return j1;
    if(j1 == 0)
        return 0;
    --i1;
    vector<int> v;
    for (int j = 0; j < j1; ++j)
        v.push_back(paritate(i1+j, i1));
    int i = j1, sol = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        if(*it == 0)
            sol ^= i;
        --i;
    }
    return sol;
}
 
int main()
{
    ifstream fin ("xor3.in");
    ofstream fout ("xor3.out");
    fin >> q >> I >> J >> a >> b >> M;
    if(q <= 50){
        for (int i = 2; i <= 60000; ++i){
            int x = 0;
            for (int j = i/2; j > 0; j /= 2)
                x += j;
            factorial[i] = x;
        }
        for (int i = 1; i <= q; ++i){
            fout << xormatrix(I, J) << "\n";
            I = (a*I+b)%M;
            J = (a*J+b)%M;
        }
    }else{
        int v[1005][1005];
        for (int i = 0; i <= 1000; ++i)
            v[0][i] = i;
        for (int i = 1; i <= 1000; ++i)
            for (int j = 0; j <= 1000; ++j)
                v[i][j] = v[i][j-1] ^ v[i-1][j];
        for (int i = 1; i <= q; ++i){
            fout << v[I][J] << "\n";
            I = (a*I+b)%M;
            J = (a*J+b)%M;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
