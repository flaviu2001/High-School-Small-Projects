#include <bits/stdc++.h>
 
using namespace std;
 
int n, aib[100005], v[100005], p[100005];
vector<int> sol;
 
void update(int idx, int val)
{
    while(idx <= n){
        aib[idx] += val;
        idx += (idx&(-idx));
    }
}
 
int read(int idx)
{
    int sum = 0;
    while(idx){
        sum += aib[idx];
        idx -= (idx&(-idx));
    }
    return sum;
}
 
int main()
{
    ifstream fin ("permsort2.in");
    ofstream fout ("permsort2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        p[v[i]] = i;
    }
    for (int t = n; t >= 2; --t){
        int pos = p[t]-read(p[t]-1);
        update(p[t], 1);
        if(pos < n){
            sol.push_back(pos+1);
            sol.push_back(pos);
        }
    }
    fout << sol.size()+1 << "\n";
    for (auto x : sol)
        fout << "S " << x << "\n";
    fout << "S 2\n";
    return 0;
}
