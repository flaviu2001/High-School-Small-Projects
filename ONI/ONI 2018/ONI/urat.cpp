#include <bits/stdc++.h>
#define M 543217

using namespace std;

long long n;
long long sol1, sol2, prod[502000], f[10], pd[502000];
vector<long long> sol3;

void gcd(long long &x, long long &y, long long a, long long b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        long long aux = x;
        x = y;
        y = aux - y * (a/b);
    }
}

long long invers_modular(long long a, long long b)
{
    long long x, y;
    gcd(x, y, a, b);
    if(x < 0)
        x = b + x%b;
    return x;
}

void build_sol()
{
    sol1 += n-1;
    if(n%2 == 0)
        for (long long i = n-2; i >= 2; i -= 2)
            sol1 += 2*i;
    else{
        ++sol1;
        for (long long i = n-2; i >= 3; i -= 2)
            sol1 += i*2;
    }
    for (long long i = 1; i <= n; ++i)
        sol3.push_back(0);
    long long lo, hi, mx, mn;
    if(n%2 == 0)
        lo = (n-1)/2-1, hi = (n-1)/2+1, mx = n, mn = 2;
    else
        lo = n/2-1, hi = n/2+1, mx = n, mn = 2;
    sol3[lo+1] = 1;
    while(mn <= mx){
        if(mn <= mx && hi < n){
            sol3[hi] = mx;
            --mx;
            ++hi;
        }
        if(mn <= mx && lo >= 0){
            sol3[lo] = mx;
            --mx;
            --lo;
        }
        if(mn <= mx && hi < n){
            sol3[hi] = mn;
            ++mn;
            ++hi;
        }
        if(mn <= mx && lo >= 0){
            sol3[lo] = mn;
            ++mn;
            --lo;
        }
    }
    prod[2] = 2;
    prod[3] = 1; // 1/2
    prod[4] = 4;
    prod[5] = 1;
    prod[6] = 6;
    f[3] = 2;
    f[4] = 4;
    f[5] = 1;
    f[6] = 4;
    for (int i = 3; i <= 6; ++i){
        for (int j = i+4; j <= n+100; j += 4)
            prod[j] = (prod[j-4]+f[i])%M;
    }
    pd[2] = 2;
    pd[3] = 4;
    pd[4] = 2;
    for (int i = 5; i <= n; ++i)
        if(i%4 == 0)
            pd[i] = (pd[i-1]*prod[i-1]*invers_modular(2, M))%M;
        else
            pd[i] = (pd[i-1]*prod[i-1])%M;
    sol2 = pd[n];
}

int main()
{
    ifstream fin ("urat.in");
    ofstream fout ("urat.out");
    fin >> n;
    build_sol();
    fout << sol1 << "\n" << sol2 << "\n";
    for (vector<long long>::iterator it = sol3.begin(); it != sol3.end(); ++it)
        fout << *it << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

