#include <bits/stdc++.h>
#define M 30103

using namespace std;

long long n;

int main()
{
    ifstream fin ("patrat.in");
    ofstream fout ("patrat.out");
    fin >> n;
    long long k = ((n+1)*(n+2)/2)%M;
    k = (k*(k+1)/2)%M;
    fout << k << "\n";
    fin.close();
    fout.close();
    return 0;
}

