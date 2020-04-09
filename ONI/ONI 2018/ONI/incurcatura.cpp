#include <bits/stdc++.h>

using namespace std;

set<int> s[100005], v[100005], r[100005], sol;

int test, n, sz[100005];

int main()
{
    ifstream fin ("incurcatura.in");
    ofstream fout ("incurcatura.out");
    fin >> test >> n;
    for (int i = 1; i <= n; ++i){
        fin >> sz[i];
        for (int j = 0; j < sz[i]; ++j){
            int x;
            fin >> x;
            s[i].insert(x);
            s[x].insert(i);
            v[i].insert(x);
            r[x].insert(i);
        }
    }
    for (int i = 1; i <= n && sol.size() < test; ++i)
        if(sz[i] == s[i].size()){
            for(set<int>::iterator it = s[i].begin(); it != s[i].end(); ++it)
                if(v[*it].find(i) == v[*it].end() || r[*it].find(i) == r[*it].end())
                    sol.insert(*it);
        }
    if(test == 2 && sol.size() == 1){
        int x = *sol.begin();
        for(int i = 1; i <= n; ++i){
            if(s[i].find(x) != s[i].end())
                s[i].erase(s[i].find(x));
            if(v[i].find(x) != v[i].end()){
                --sz[i];
                v[i].erase(v[i].find(x));
            }
        }
        for (int i = 1; i <= n && sol.size() < test; ++i)
            if(sz[i] == s[i].size() && i != x){
                for(set<int>::iterator it = s[i].begin(); it != s[i].end(); ++it)
                    if(v[*it].find(i) == v[*it].end() || r[*it].find(i) == r[*it].end())
                        sol.insert(*it);
            }
    }
    for (set<int>::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << *it << " ";
    fin.close();
    fout.close();
    return 0;
}

