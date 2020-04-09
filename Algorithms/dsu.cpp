#include <bits/stdc++.h>

using namespace std;

const string fisier = "disjoint";
const int nmax = 100005;
int n, test, c[nmax], rng[nmax];

int find(int x)
{
    if(x == c[x])
        return x;
    return c[x] = find(c[x]);
}

void unite(int x, int y)
{
	if(x == y)
		return;
    if(rng[x] > rng[y])
        c[y] = x;
    else c[x] = y;
    if(rng[x] == rng[y])
        ++rng[y];
}

int main()
{
    ifstream fin (fisier+".in");
    ofstream fout (fisier+".out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i)
        c[i] = i, rng[i] = 1;
    while(test--){
        int t, x, y;
        fin >> t >> x >> y;
        if(t == 1)
            unite(find(x), find(y));
        else fout << (find(x) == find(y) ? "DA\n" : "NU\n");
    }
    return 0;
}

