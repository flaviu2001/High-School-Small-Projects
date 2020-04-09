#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long v[2100], n, p = 1;

long long max(long long x, long long y)
{
    return x > y ? x : y;
}

long long sum_one_way(long long x, long long y, long long &mxcv)
{
    long long xx = x, yy = y;
    if(x == y)
        return 0;
    vector<long long> v1, v2;
    while(x){
        v1.push_back(x%10);
        x /= 10;
    }
    while(y){
        v2.push_back(y%10);
        y /= 10;
    }
    if(v1.size() == 0)
        v1.push_back(0);
    if(v2.size() == 0)
        v2.push_back(0);
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    bool distinct = true;
    for (long long i = 0; i < v1.size() && distinct; ++i)
        for (long long j = 0; j < v2.size() && distinct; ++j)
            if(v1[i] == v2[j])
                distinct = false;
    if(distinct)
        return 0;

    long long mxnr = 0, mxdg = 0;
    for (long long r = 0; r < v1.size(); ++r){
        vector<long long> v3;
        for (long long i = 1; i <= r; ++i)
            v3.push_back(-1);
        for (long long i = 0; i < v2.size(); ++i)
            v3.push_back(v2[i]);
        vector<long long> s;
        long long dg = 0, nr = 0;
        for (long long i = 0; i < max(v1.size(), v3.size()); ++i){
            long long w = 0;
            if(i < v1.size() && i < v3.size()){
                if(v1[i] != v3[i])
                    s.push_back(v1[i]+v3[i]+(v3[i] == -1));
                else if(v1[i] == v3[i] && v1[i] != -1)
                    ++dg;
            }
            else{
                if(i < v1.size())
                    w += v1[i];
                if(i < v3.size())
                    w += v3[i];
                s.push_back(w);
            }
        }
        reverse(s.begin(), s.end());
        long long rest = 0;
        for (long long i = 0; i < s.size(); ++i){
            s[i] += rest;
            rest = s[i]/10;
            s[i] %= 10;
        }
        if(rest > 0)
            s.push_back(1);
        reverse(s.begin(), s.end());
        for (long long i = 0; i < s.size(); ++i)
            nr = nr*10 + s[i];
        if(dg > mxdg){
            mxdg = dg;
            mxnr = nr;
        }else if(dg == mxdg && mxnr < nr)
            mxnr = nr;
        //printf("%d %d\n", nr, dg);
    }
    //printf("\n\n");
    mxcv = mxdg;
    return mxnr;
}

long long sum(long long x, long long y)
{
    long long cv1 = 0, cv2 = 0;
    long long xxx = sum_one_way(x, y, cv1);
    long long yyy = sum_one_way(y, x, cv2);
    if(cv1 > cv2)
        return xxx;
    else if(cv1 < cv2)
        return yyy;
    if(xxx > yyy)
        return xxx;
    return yyy;
}

long long termen();

long long eval()
{
    long long r = termen();
    ++p;
    while(v[p] >= -1){
        r = sum(r, termen());
        ++p;
    }
    return r;
}

long long termen()
{
    long long r = 0;
    if(v[p] == -1){
        ++p;
        r = eval();
    }
    else if(v[p] >= 0) r = v[p];
    return r;
}

long long adancime()
{
    long long x = 0, mx = 0;
    for (long long i = 1; i <= n; ++i){
        if(v[i] == -1)
            ++x;
        if(v[i] == -2)
            --x;
        mx = max(mx, x);
    }
    return mx;
}

int main()
{
    ifstream fin ("plus.in");
    ofstream fout ("plus.out");
    fin >> n;
    for (long long i = 1; i <= n; ++i)
        fin >> v[i];
    v[n+1] = -3;

    fout << adancime() << "\n" << eval() << "\n";
    return 0;
}

