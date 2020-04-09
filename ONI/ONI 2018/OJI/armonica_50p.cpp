#include <bits/stdc++.h>
#define dd (double)

using namespace std;

long long n;
vector< pair<long long, long long> > sol;

int main()
{
    ifstream fin ("armonica.in");
    ofstream fout ("armonica.out");
    fin >> n;
    sol.push_back(make_pair(n, n));
    if(n%2 == 1){
        double m = n;
        for (long long i = 1; i <= m; ++i)
            if((n)%i == 0){
                long long u = i, v = (n*n)/i;
                sol.push_back(make_pair((n+u)/2,(n+v)/2));
                sol.push_back(make_pair((n+v)/2,(n+u)/2));
            }
    }else{
        long long k = n/2;
        double m = (sqrt(k));
        for (long long i = 1; i < m; ++i)
            if((k*k)/i == 0){
                long long u = i, v = (k*k)/i;
                sol.push_back( make_pair ( k+u, k+v ) );
                sol.push_back( make_pair ( k+v, k+u ) );
            }
    }
    fout << sol.size() << "\n";
    for (vector< pair<long long, long long> >::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    fin.close();
    fout.close();
    return 0;
}

