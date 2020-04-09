#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> v[100005];
long long area;
long long lattice_boundaries, n;

long long gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x%y);
}

int main()
{
    ifstream fin ("copaci.in");
    ofstream fout ("copaci.out");
    fin >> n;
    for (long long i = 1; i <= n; ++i)
        fin >> v[i].first >> v[i].second;
    for (long long i = 1; i < n; ++i){
        area += (v[i].first * v[i+1].second - v[i].second * v[i+1].first);
        lattice_boundaries += gcd(abs(v[i+1].first-v[i].first), abs(v[i+1].second-v[i].second))-1;
    }
    area += v[n].first * v[1].second - v[n].second * v[1].first;
    lattice_boundaries += gcd(abs(v[1].first-v[n].first), abs(v[1].second-v[n].second))+n-1;
    fout << (abs(area)-lattice_boundaries+2)/2 << "\n";
    fin.close();
    fout.close();
    return 0;
}

