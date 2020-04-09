#include <bits/stdc++.h>

using namespace std;

int n, m, sol;
vector<int> v[100005];

void solve(int x)
{
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(x < *it)
            for (vector<int>::iterator it2 = v[*it].begin(); it2 != v[*it].end(); ++it2)
                if(*it < *it2)
                    for(vector<int>::iterator it3 = v[*it2].begin(); it3 != v[*it2].end(); ++it3)
                        if(*it3 == x){
                            ++sol;
                            break;
                        }
}

int main()
{
    ifstream fin ("tric.in");
    ofstream fout ("tric.out");
    fin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;++x,++y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        solve(i);
    fout << sol << "\n";
    return 0;
}
