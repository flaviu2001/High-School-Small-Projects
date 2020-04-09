#include <fstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> primes;
char s[1005];
bool ok[1005];
int n, v[1005], f[300];

void ciur()
{
    for (int i = 4; i < 1005; i += 2)
        ok[i] = 1;
    for (int i = 3; i * i < 1005; i += 2)
        if(!ok[i])
            for (int d = i * i; d < 1005; d += i)
                ok[d] = 1;
    for (int i = 2; i < 1005; ++i)
        if(!ok[i])
            primes.push_back(i);
}

void adjust_vector(int y)
{
    for (int i = 2; i <= y; ++i){
        int x = i;
        for (int j = 0; primes[j] <= x; ++j)
            while(x % primes[j] == 0){
                x /= primes[j];
                --v[primes[j]];
            }
    }
}

void build_vector()
{
    for (int i = 2; i <= n; ++i){
        int x = i;
        for (int j = 0; primes[j] <= x && j < primes.size(); ++j)
            while(x % primes[j] == 0){
                x /= primes[j];
                ++v[primes[j]];
            }
    }
    for (int i = 'a'; i <= 'z'; ++i)
        if(f[i] > 1)
            adjust_vector(f[i]);
}

void read()
{
    ifstream fin ("anagrame.in");
    fin.getline(s, 1005);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        ++f[s[i]];
    fin.close();
}

void write()
{
    ofstream fout ("anagrame.out");
    for (int i = 2; i <= n; ++i)
        if(v[i] != 0)
            fout << i << " " << v[i] << "\n";
}

int main()
{
    ciur();
    read();
    build_vector();
    write();
    return 0;
}

