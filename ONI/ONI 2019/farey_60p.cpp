#include <bits/stdc++.h>

using namespace std;

struct fr{
    int x, y;
    bool operator<(const fr &obj)const{
        return x*obj.y < y*obj.x;
    }
};

short v[40005][10], sv[40005];
bool ciur[40005];
int n, test;

int nogcd(int m, int k)
{
    int ans = 0;
    for (int t = 0; t < (1<<sv[k]); ++t){
        int mult = 1;
        for (int j = 0; j < sv[k]; ++j)
            if(t&(1<<j))
                mult *= -v[k][j];
        ans += m/mult;
    }
    return ans;
}

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x%y));
}

int main()
{
    ifstream fin ("farey.in");
    ofstream fout ("farey.out");
    fin >> n >> test;
    for (int i = 2; i*i <= n; ++i)
        if(!ciur[i])
            for (int d = i*i; d <= n; d += i)
                ciur[d] = 1;
    for (int i = 2; i <= n; ++i)
        if(!ciur[i])
            for (int d = i; d <= n; d += i)
                v[d][sv[d]++] = i;
    double lo = 0, hi = 1, m;
    while(1){
        m = (2*lo+hi)/3;
        int all = 0;
        fr mx;
        mx.x = 0, mx.y = 1;
        for (int t = 1; t < n; ++t){
            int first = max(t+1, int(ceil(t/m)));
            if(first > n)
                continue;
            for (int r = first; r <= n; ++r)
                if(gcd(r, t) == 1){
                    fr aux; aux.x = t, aux.y = r;
                    mx = max(mx, aux);
                    break;
                }
            all += nogcd(n, t)-nogcd(first-1, t);
        }
        if(all == test){
            fout << mx.x << " " << mx.y << "\n";
            break;
        }
        if(all > test)
            hi = m;
        else lo = m;
    }
    return 0;
}

