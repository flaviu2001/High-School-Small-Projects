#include <bits/stdc++.h>

using namespace std;

int n, m, scm = 1, test, e[2000005];
vector<int> v[55], r[55];

int gcd(int x, int y)
{
    if(y == 0)
        return x;
    return gcd(y, x%y);
}

int cmmmc(int x, int y)
{
    return (x*y)/gcd(x, y);
}

int main()
{
    ifstream fin ("albinuta.in");
    ofstream fout ("albinuta.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i){
        fin >> m;
        v[i].push_back(0);
        for (int j = 1; j <= m; ++j){
            int x;
            fin >> x;
            v[i].push_back(x);
        }
        v[i][0] = v[i][m];
        scm = cmmmc(scm, m);
    }
    for (int i = 1; i <= n; ++i)
        r[i].resize(scm+20, 0);

    int pre, ciclu, x = 1;
    bool cont = true;

    e[1] = 1;
    for (int t = 2; cont; ++t){
        x = v[x][(t-1)%(v[x].size()-1)];
        e[t] = x;
        if(cont){
            int care = t%scm;
            if(care == 0)
                care = scm;
            if(r[x][care] != 0){
                pre = r[x][care];
                ciclu = t-pre;
                t += ((m-t)/(t-r[x][care]))*(t-r[x][care]);
                cont = false;
            }
            else r[x][care] = t;
        }
    }
    while(test--){
        fin >> m;
        m -= ((m-pre)/ciclu)*ciclu;
        fout << e[m] << "\n";
    }
    return 0;
}

