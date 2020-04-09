#include <fstream>
#include <vector>

using namespace std;

bool ok[1000005];
vector<long long> primes, dv;
long long t;

void ciur()
{
    for (int i = 4; i < 1000005; i += 2)
        ok[i] = 1;
    primes.push_back(2);
    for (int i = 3; i < 1000005; i += 2)
        if(!ok[i]){
            primes.push_back(i);
            for (int d = i + i; d < 1000005; d += i)
                ok[d] = 1;
        }
}

int main()
{
    ciur();
    ifstream fin ("pinex.in");
    ofstream fout ("pinex.out");
    fin >> t;
    while(t--){
        dv.clear();
        long long n, m, copy, sol = 0;
        fin >> n >> m;
        copy = m;
        for (unsigned i = 0; i < primes.size() && primes[i] <= copy; ++i){
            if(copy % primes[i] == 0){
                dv.push_back(primes[i]);
                while(copy % primes[i] == 0)
                    copy /= primes[i];
            }
            if(primes[i] * primes[i] > copy && copy > 1){
                dv.push_back(copy);
                copy = 1;
            }
        }
        long long log = (1<<(dv.size()-1));
        for (long long i = 1; i < (1<<dv.size()); ++i){
            long long prod = 1, nr = 0, x = i;
            for (long long j = log, d = 0; j > 0; j /= 2, ++d)
                if(j <= x){
                    x -= j;
                    prod *= dv[d];
                    ++nr;
                }
            if(nr%2 == 1)
                sol += n/prod;
            else sol -= n/prod;
        }
        fout << n-sol << "\n";
    }
    return 0;
}
