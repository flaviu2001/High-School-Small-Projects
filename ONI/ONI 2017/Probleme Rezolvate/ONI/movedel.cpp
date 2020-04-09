#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primes;
bool sieve[1000007];
int n, m;

void primeGen()
{
    for (int i = 2; i < 1000007; ++i)
        if (!sieve[i]){
            primes.push_back(i);
            for (int d = i + i; d < 1000007; d += i)
                sieve[d] = 1;
        }
    reverse(primes.begin(), primes.end());
}

void read()
{
    ifstream fin ("movedel.in");
    fin >> n >> m;
    fin.close();
}

int last()
{
    int k = 0;
    vector<bool> ok(n, 0);
    int t = -1, p = 0;
    while(k < n){
        p += primes.back();
        primes.pop_back();
        p %= n;
        if (!ok[p]){
            ok[p] = 1;
            ++k;
            t = p;
        }
    }
    return t;
}

void write()
{
    ofstream fout ("movedel.out");
    string a(n, 'x'), b(n, 'r');
    b[0] = 'a';
    a[last()] = 'a';
    fout << a << "\n" << b << "\n";
}

int main()
{
    primeGen();
    read();
    write();
    return 0;
}
