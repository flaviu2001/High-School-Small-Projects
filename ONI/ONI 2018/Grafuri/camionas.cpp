#include <bits/stdc++.h>

using namespace std;

int n, m, t, d[50005];
vector< pair<int, int> > v[50005];
set< pair<int, int> > s;

int main()
{
    ifstream fin ("camionas.in");
    ofstream fout ("camionas.out");
    fin >> n >> m >> t;
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        z = z < t;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    for (int i = 1; i <= n; ++i)
        d[i] = 2000000000;
    d[1] = 0;
    s.insert(make_pair(0, 1));
    while(!s.empty()){
        int k = s.begin()->second;
        s.erase(s.begin());
        for (vector< pair<int, int> >::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(d[it->first] > d[k] + it->second){
                if(d[it->first] != 2000000000)
                    s.erase(s.find(make_pair(d[it->first], it->first)));
                d[it->first] = d[k] + it->second;
                s.insert(make_pair(d[it->first], it->first));
            }
    }
    fout << d[n] << "\n";
    fin.close();
    fout.close();
    return 0;
}

