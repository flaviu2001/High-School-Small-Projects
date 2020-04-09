#include <bits/stdc++.h>
 
using namespace std;
 
vector<long long> v[100005], s[100005];
long long n, test, tt[100005], p[100005], pi = 1, r[30][100005];
char c[100005], m[100005];
 
void df(long long x)
{
    if(x != 1){
        if(r[m[x]-'a'][p[tt[x]]] == 0)
            r[m[x]-'a'][p[tt[x]]] = ++pi;
        p[x] = r[m[x]-'a'][p[tt[x]]];
    }
    for (vector<long long>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        df(*it);
}
 
int main()
{
    ifstream fin ("aiacupalindroame.in");
    ofstream fout ("aiacupalindroame.out");
    fin >> n >> test;
    for (long long i = 2; i <= n; ++i){
        long long x;
        fin >> x;
        tt[i] = x;
        v[x].push_back(i);
    }
    for (long long i = 2; i <= n; ++i)
        fin >> m[i];
    p[1] = 1;
    df(1);
    while(test--){
        long long x, y;
        fin >> x >> y;
        fout << (p[x] == p[y]) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
