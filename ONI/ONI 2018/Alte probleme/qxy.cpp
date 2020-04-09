#include <bits/stdc++.h>

using namespace std;

int n, d[1005][1005], p = 1, v[10005];

int main()
{
    ifstream fin ("qxy.in");
    ofstream fout ("qxy.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x; v[i] = x;
        ++d[p][x];
        if(i%10==0)
            ++p;
    }
    for (int i = 1; i <= p; ++i)
        for (int j = 0; j <= 1000; ++j)
            d[i][j] += d[i-1][j];
    for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= 1000; ++j)
            d[i][j] += d[i][j-1];
    int q;
    fin >> q;
    for (int i = 1; i <= q; ++i){
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        int ans = 0;
        int b2 = (y-1)/10+1;
        int b1 = (x-1)/10+1;
        ans += d[b2][b]-d[b2][a-1] - (d[b1-1][b]-d[b1-1][a-1]);
        for (int j = (b1-1)*10+1; j < x; ++j)
            if (v[j] >= a && v[j] <= b)
                --ans;
        for (int j = y+1; j <= b2*10; ++j)
            if (v[j] >= a && v[j] <= b)
                --ans;
        fout << ans << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

