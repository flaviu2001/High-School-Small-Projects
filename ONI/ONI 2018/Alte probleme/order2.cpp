#include <bits/stdc++.h>

using namespace std;

const int nmax = 2005;
int v[nmax], sortedArray[nmax], where[5*nmax], n;

void flip(int x)
{
    if(x == 0 || x == n+1){
        for (int i = 1; i <= n; ++i)
            where[v[i]] = n-i+1;
        reverse(v+1, v+n+1);
        return;
    }
    if(x != 1){
        for (int i = 1; i < x; ++i)
            where[v[i]] = x-i;
        reverse(v+1, v+x);
    }
    if(x != n){
        int last = n;
        for (int i = x+1; i <= n; ++i)
            where[v[i]] = last--;
        reverse(v+x+1, v+n+1);
    }
}

int main()
{
    ifstream fin ("order2.in");
    ofstream fout ("order2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        sortedArray[i] = v[i];
        where[v[i]] = i;
    }
    sort(sortedArray+1, sortedArray+n+1);
    fout << where[sortedArray[1]]+1 << "\n";
    flip(where[sortedArray[1]]+1);
    for (int i = 2; i <= n; ++i){
        fout << where[sortedArray[i]] << "\n";
        flip(where[sortedArray[i]]);
        fout << where[sortedArray[i]]+1 << "\n";
        flip(where[sortedArray[i]]+1);
    }
    fout << "0\n";
    return 0;
}

