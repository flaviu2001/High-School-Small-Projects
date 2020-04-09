#include <bits/stdc++.h>

using namespace std;

long long n, v[250005];

long long divide(long long st, long long dr)
{
    if(st == dr)
        return 1;
    long long m = (st+dr)/2;
    long long divst = divide(st, m);
    long long divdr = divide(m+1, dr);
    map<long long, long long> frq, frq2;
    vector<long long> sol;
    for (long long i = m; i >= st; --i){
        ++frq[v[i]];
        if(frq[v[i]] >= (m-i+1)/2+1){
            sol.push_back(v[i]);
            frq[v[i]] = -2000000000;
        }
    }
    for (long long i = m+1; i <= dr; ++i){
        ++frq2[v[i]];
        if(frq2[v[i]] >= (i-m)/2+1 && frq[v[i]] >= 0){
            sol.push_back(v[i]);
            frq2[v[i]] = -2000000000;
        }
    }
    long long sum = 0;
    for (vector<long long>::iterator it = sol.begin(); it != sol.end(); ++it){
        //long long freq[2*(dr-st+2)] = {0};
        long long *freq = (long long*)malloc((2*(dr-st+2))*sizeof(long long));
        for (int i = 0; i < 2*(dr-st+2); ++i)
            freq[i] = 0;
        long long now = 0, offset = dr-st+1;
        ++freq[0+offset];
        for (long long i = st; i <= m; ++i){
            if(v[i] == *it)
                ++now;
            else --now;
            if(i != m)
                ++freq[now+offset];
        }
        for (long long i = -(dr-st+1)+1; i <= dr-st+1; ++i)
            freq[i+offset] += freq[i-1+offset];
        for (long long i = m+1; i <= dr; ++i){
            if(v[i] == *it)
                ++now;
            else --now;
            sum += freq[now-1+offset];
        }
    }
    sum += divst + divdr;
    return sum;
}

int main()
{
    ifstream fin ("bvarcolaci.in");
    ofstream fout ("bvarcolaci.out");
    fin >> n;
    for (long long i = 1; i <= n; ++i)
        fin >> v[i];
    fout << divide(1, n) << "\n";
    fin.close();
    fout.close();
    return 0;
}

