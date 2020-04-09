#include <bits/stdc++.h>

using namespace std;

const int nmax = 2000005;
char a[nmax], b[nmax];
int n, m, urm[nmax];
vector<int> sol;

int main()
{
    ifstream fin ("strmatch.in");
    ofstream fout ("strmatch.out");
    fin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    int k = 0;
    urm[0] = 0;
    for (int i = 1; i < n; ++i){
        while(k > 0 && a[k] != a[i])
            k = urm[k-1];
        if(a[k] == a[i])
            ++k;
        urm[i] = k;
    }
    k = 0;
    for (int j = 0; j < m; ++j){
        while(k > 0 && a[k] != b[j])
            k = urm[k-1];
        if(a[k] == b[j])
            ++k;
        if(k == n)
            sol.push_back(j-n+1);
    }
    fout << sol.size() << "\n";
    for (int i = 0; i < sol.size() && i < 1000; ++i)
        fout << sol[i] << " ";
    return 0;
}

