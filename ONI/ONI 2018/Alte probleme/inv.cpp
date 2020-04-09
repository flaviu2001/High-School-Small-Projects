#include <bits/stdc++.h>

using namespace std;

const int M = 9917;
int n, sol, aib[100005];
set< pair<int, int> > s;

void update(int idx, int x)
{
    while(idx <= n){
        aib[idx] += x;
        idx += (idx & -idx);
    }
}

int query(int idx)
{
    int sol = 0;
    while(idx){
        sol += aib[idx];
        idx -= (idx & -idx);
    }
    return sol;
}

int main()
{
    ifstream fin ("inv.in");
    ofstream fout ("inv.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        s.insert({x, i});
    }
    for (set< pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it){
        sol += it->second - query(it->second)-1;
        sol %= M;
        update(it->second, 1);
    }
    fout << sol << "\n";
    return 0;
}

