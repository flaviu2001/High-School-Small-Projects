#include <bits/stdc++.h>

using namespace std;

const int M = 30103;

int n, aib[705][2005], v[705];

void add(int &x, int y)
{
    x = (x+y)%M;
}

void update(int x, int y, int q)
{
    for(; x <= n; x += (x & (-x)))
        for(int o = y; o <= 2000; o += (o & (-o)))
            add(aib[x][o], q);
}

int query(int x, int y)
{
    int an = 0;
    for(; x; x -= (x & (-x)))
        for(int o = y; o; o -= (o & (-o)))
            add(an, aib[x][o]);
    return an;
}

int main()
{
    ifstream fin ("evantai.in");
    ofstream fout ("evantai.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = n-1; i >= 1; --i)
        for (int j = n; j > i; --j)
            update(j, v[i]+v[j], query(j-1, v[i]+v[j]-1)+1);
    fout << query(n, 2000) << "\n";
    return 0;
}
