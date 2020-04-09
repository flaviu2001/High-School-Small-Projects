#include <bits/stdc++.h>

using namespace std;

long long test, v[100], n;

long long sum_and_pos(long long s, long long p)
{
    return 1LL * ((1LL*1<<(s-1)) - (1LL*1<<(s-p)));
}

long long get_smallest_pow(long long x)
{
    for (long long i = 0; ; ++i)
        if((1LL*1<<i) > x)
            return i-1;
}

int main()
{
    ifstream fin ("order3.in");
    ofstream fout ("order3.out");
    fin >> test;
    while(test--){
        long long t;
        fin >> t;
        if(t == 1){
            fin >> n;
            long long sum = 0, sol = 0;
            for (long long i = 1; i <= n; ++i){
                fin >> v[i];
                sum += v[i];
            }
            sol += (1LL*(1LL*1<<(sum-1)));
            for (int i = 1; i <= n; ++i){
                sol += sum_and_pos(sum, v[i]);
                sum -= v[i];
            }
            fout << sol << "\n";
        }else{
            fin >> n;
            long long sum = get_smallest_pow(n), i = 1;
            n -= (1LL*1<<sum);
            ++sum;
            for (i = 1; sum; ++i){
                long long p = 1;
                for (long long j = (1LL*1<<(sum-2)); n && j; j >>= 1)
                    if(n >= j){
                        n -= j;
                        ++p;
                    }else break;
                v[i] = p;
                sum -= p;
            }
            fout << i-1 << " ";
            for (long long j = 1; j <= i-1; ++j)
                fout << v[j] << " ";
            fout << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}

