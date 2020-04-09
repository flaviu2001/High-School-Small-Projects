#include <fstream>
#include <algorithm>

using namespace std;

const long long m = 666013;
long long n, p = 2, x1 = 1, x2 = 0, a, b, current_pascal = 1, v[200005], pascal[200005], factorial[200005], inv[200005];

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

long long invers_modular(long long a)
{
    long long x, y;
    gcd(x, y, a, m);
    if(x < 0)
        x = m + x%m;
    return x;
}

long long combinari(int n, int k)
{
    long long sol = factorial[n];
    long long invk = inv[k];
    long long invn_k = inv[n-k];
    return (sol * invk * invn_k) % m;
}

int main()
{
    ifstream fin ("permheap.in");
    ofstream fout ("permheap.out");
    fin >> n;
    v[1] = 1;
    v[2] = 1;
    pascal[0] = 1;
    pascal[1] = 1;
    factorial[1] = 1;
    for (long long i = 2; i < 200005; ++i)
        factorial[i] = (factorial[i-1] * i) % m;
    for (long long i = 1; i <= n; ++i)
        inv[i] = invers_modular(factorial[i]);
    for (long long i = 3; i <= n; ++i){
        ++current_pascal;
        if(x1+1 == p){
            if(x2 < x1)
                ++x2;
            else{
                ++x1;
                p *= 2;
            }
        }else
            ++x1;
        pascal[x1] = combinari(current_pascal, x1);
        v[i] = pascal[x1] * v[x1] * v[x2];
        v[i] %= 666013;
    }
    fout << v[n] << "\n";
    return 0;
}

