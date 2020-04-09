#include <bits/stdc++.h>

using namespace std;

struct thing{
    int x, i;
    bool operator<(const thing &obj)const{
        return x < obj.x;
    }
};

const int nmax = 100005;
int n, s, v[nmax], pr[nmax], p, sol;
thing q[nmax];

thing mkt(int x, int i)
{
    thing aux;
    aux.x = x;
    aux.i = i;
    return aux;
}

int main()
{
    ifstream fin ("secv9.in");
    ofstream fout ("secv9.out");
    fin >> n >> s;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        pr[i] = pr[i-1]+v[i];
        q[i] = mkt(pr[i]-s, i);
    }
    sort(q+1, q+n+1);
    p = n;
    for (int i = 0; i < n; ++i)
        while(p > 0 && pr[i] <= q[p].x){
            sol = max(sol, q[p].i-i);
            --p;
        }
    fout << sol << "\n";
    return 0;
}

