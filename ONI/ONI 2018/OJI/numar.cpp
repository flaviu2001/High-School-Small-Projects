#include <bits/stdc++.h>

using namespace std;

vector<int> m;
int n, t, v[105], r[105];

int main()
{
    ifstream fin ("numar.in");
    ofstream fout ("numar.out");
    fin >> n >> t;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        r[i] = v[i];
    }
    for (int i = 1; i <= t; ++i){
        int mn = 2000000000;
        for (int j = 1; j <= n; ++j)
            mn = min(mn, r[j]);
        for (int j = 1; j <= n; ++j)
            if(r[j] == mn)
                r[j] += v[j];
        m.push_back(mn);
    }
    fout << m.back() << "\n";
    fin.close();
    fout.close();
    return 0;
}
