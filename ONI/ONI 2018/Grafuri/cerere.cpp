#include <bits/stdc++.h>

using namespace std;

int n, tt[100005], ans[100005], s[100005], vf, v[100005];
vector<int> fii[100005];

void df(int x)
{
    ++vf;
    for (vector<int>::iterator it = fii[x].begin(); it != fii[x].end(); ++it){
        if(v[*it] != 0)
            s[vf] = s[vf-v[*it]]+1;
        else
            s[vf] = 0;
        ans[*it] = s[vf];
        df(*it);
    }
    --vf;
}

int main()
{
    ifstream fin ("cerere.in");
    ofstream fout ("cerere.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        fii[x].push_back(y);
        tt[y] = x;
    }
    for (int i = 1; i <= n; ++i)
        if(tt[i] == 0){
            vf = 1;
            df(i);
        }
    for (int i = 1; i <= n; ++i)
        fout << ans[i] << " ";
    fin.close();
    fout.close();
    return 0;
}

