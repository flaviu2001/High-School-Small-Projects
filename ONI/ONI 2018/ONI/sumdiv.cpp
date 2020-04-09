#include <bits/stdc++.h>

using namespace std;

const int64_t M = 9901, nmax = 7100;
int64_t pd[1005], B;
bool ciur[nmax];
vector<int64_t> primes;
vector< pair<int64_t, int64_t> > divs;

int64_t lgp(int64_t a, int64_t b)
{
    int64_t p = 1;
    while(b)
        if(b%2 == 0){
            a = (a*a)%M;
            b /= 2;
        }else{
            p = (p*a)%M;
            --b;
        }
    return p;
}

void gcd(int64_t &x, int64_t &y, int64_t a, int64_t b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        int64_t aux = x;
        x = y;
        y = aux - (a/b)*y;
    }
}

int64_t invers(int64_t a)
{
    int64_t x, y;
    gcd(x, y, a, M);
    if(x < 0)
        x = M+x%M;
    return x;
}

int64_t sumgeom(int64_t p1, int64_t q1)
{
    int64_t x;
    x = q1*B;
    x = lgp(p1, x);
    --x;
    if(x < 0)
        x += M;
    x = (x*p1)%M;
    x = (x*invers(p1-1))%M;
    return x;
}

int main()
{
    ifstream fin ("sumdiv.in");
    ofstream fout ("sumdiv.out");
    int64_t a, b;
    fin >> a >> b;B=b;
    if(a == 1){
        fout << "1";
        return 0;
    }
    for (int64_t i = 4; i < nmax; i += 2)
        ciur[i] = 1;
    for (int64_t i = 3; i*i < nmax; ++i)
        if(!ciur[i])
            for (int64_t d = i*i; d < nmax; d += i)
                ciur[d] = 1;
    for (int64_t i = 2; i < nmax; ++i)
        if(!ciur[i])
            primes.push_back(i);
    for (vector<int64_t>::iterator it = primes.begin(); it != primes.end() && a != 1; ++it)
        if(a%*it == 0){
            int64_t divcnt = 0;
            while(a%*it == 0){
                ++divcnt;
                a /= *it;
            }
            divs.push_back({*it, divcnt});
        }
    if(a != 1)
        divs.push_back({a, 1});
    pd[divs.size()-1] = sumgeom(divs.back().first, divs.back().second);
    if(divs.back().first%M == 1)
        pd[divs.size()-1] = b%M;
    for (int i = divs.size()-2; i >= 0; --i){
        int mult = sumgeom(divs[i].first, divs[i].second);
        if(divs[i].first%M == 1){
            pd[i] = b%M;
            continue;
        }
        pd[i] = mult;
        mult = (mult*pd[i+1])%M;
        pd[i] += mult+pd[i+1];
        pd[i] %= M;
    }
    fout << pd[0]+1;
    return 0;
}

