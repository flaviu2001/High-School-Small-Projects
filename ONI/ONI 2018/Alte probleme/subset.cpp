#include <bits/stdc++.h>

using namespace std;

int64_t n, m;
vector<int64_t>sol;

int main()
{
    ifstream fin ("subset.in");
    ofstream fout ("subset.out");
    fin >> n >> m;
    sol.push_back(0);
    while(m){
        int64_t sz = n-sol.back();
        int64_t curr = sol.back()+1, add = 1LL<<(sz-1);
        while(add < m && m){
            ++curr;
            m -= add;
            add >>= 1;
        }
        --m;
        sol.push_back(curr);
    }
    for (vector<int64_t>::iterator it = sol.begin()+1; it != sol.end(); ++it)
        fout << *it << " ";
    return 0;
}

