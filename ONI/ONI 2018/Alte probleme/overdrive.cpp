#include <bits/stdc++.h>

using namespace std;

vector<long long> a, b, v1, v2;
long long n, suma, sumb;

void make(vector<long long> r, vector<long long> &v)
{
    v.push_back(0);
    for (vector<long long>::iterator it = r.begin(); it != r.end(); ++it){
        long long End = v.size();
        for (long long i = 0; i < End; ++i)
            v.push_back((*it)+v[i]);
    }
    sort(v.begin(), v.end());
}

bool can_transport(long long d)
{
    long long i1 = 0, i2 = v2.size()-1;
    while(i1 < (int)v1.size() && i2 >= 0){
        long long s1 = v1[i1] + v2[i2], s2 = suma+sumb-s1;
        if(s1 > d)
            --i2;
        else if (s2 > d)
            ++i1;
        else return true;
    }
    return false;
}

int main()
{
    ifstream fin ("overdrive.in");
    ofstream fout ("overdrive.out");
    fin >> n;
    for (long long i = 1; i <= n; ++i){
        long long x;
        fin >> x;
        if(i <= n/2){
            a.push_back(x);
            suma += x;
        }else{
            b.push_back(x);
            sumb += x;
        }
    }
    make(a, v1);
    make(b, v2);
    long long lo = 0, hi = 32LL*2000000009LL, m, ans;
    for (m = (lo + hi)/2; lo <= hi; m = (lo + hi)/2){
        if(can_transport(m))
            ans = m,
            hi = m-1;
        else
            lo = m+1;
    }
    fout << ans << "\n";
    fin.close();
    fout.close();
    return 0;
}

