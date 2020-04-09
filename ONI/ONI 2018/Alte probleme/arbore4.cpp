#include <bits/stdc++.h>

using namespace std;

const int64_t M = 666013;
vector<int64_t> v[100005];
int64_t fact[100005], sol = 1, d[100005], n;

void gcd(int64_t &x, int64_t &y, int64_t a, int64_t b)
{
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    gcd(x, y, b, a%b);
    int64_t aux = x;
    x = y;
    y = aux - y * (a/b);
}

int64_t invers_modular(int64_t a, int64_t m)
{
    int64_t x, y;
    gcd(x, y, a, m);
    if(x < 0)
        x = M + x%M;
    return x;
}

int64_t combinari(int64_t n, int64_t k)
{
    int64_t sol = fact[n];
    sol = (sol * invers_modular(fact[k], M))%M;
    sol = (sol * invers_modular(fact[n-k], M))%M;
    return sol;
}

void dfs(int64_t x, int64_t pred = 0)
{
    d[x] = 1;
    for (vector<int64_t>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(*it != pred){
            dfs(*it, x);
            d[x] += d[*it];
        }
    int64_t sofar = d[x]-1;
    for (vector<int64_t>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(*it != pred){
            sol = (sol * combinari(sofar, d[*it]))%M;
            sofar -= d[*it];
        }
}

int main()
{
    ifstream fin ("arbore4.in");
    ofstream fout ("arbore4.out");
    fact[0] = 1;
    for (int64_t i = 1; i <= 100000; ++i)
        fact[i] = (fact[i-1]*i)%M;
    fin >> n;
    for (int64_t i = 1; i < n; ++i){
        int64_t x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

