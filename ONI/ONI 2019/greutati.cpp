#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "greutati";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647, M = 1000000007;

struct elem{
    int p, f;
    bool operator<(const elem &obj)const{
        return p < obj.p;
    }
};

int lgp(int x, int y)
{
    int p = 1;
    while(y)
        if(y%2 == 0){
            x = (1ll*x*x)%M;
            y /= 2;
        }else{
            p = (1ll*p*x)%M;
            --y;
        }
    return p;
}

int n, m, pr[100005], pw2[30];
elem v[100005];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    pw2[0] = 1;
    for (int i = 1; i <= 30; ++i)
        pw2[i] = pw2[i-1]*2;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> v[i].p >> v[i].f;
    sort(v+1, v+n+1);
    reverse(v+1, v+n+1);
    int diff = 0, fdif = 0, last = 1, p = 1, ans = 0;
    while(p <= n){
        if(fdif != 0){
            if(diff-v[p].p >= 30)
                break;
            ll F = 1ll*fdif*pw2[diff-v[p].p];
            if(F > 2000000000)
                break;
            fdif = F;
            diff = v[p].p;
            if(fdif <= v[p].f){
                v[p].f -= fdif;
                diff = 0;
                fdif = 0;
            }else
                fdif -= v[p].f;
        }
        if(fdif == 0){
            last = p;
            if(v[p].f%2 == 0){
                ++p;
                continue;
            }
            diff = v[p].p;
            fdif = 1;
        }
        ++p;
    }
    if(fdif != 0){
        int rem = 0;
        for (int i = n; i > last; --i)
            rem = (rem+((1ll*lgp(2, v[i].p)*v[i].f)%M))%M;
        int all = lgp(2, v[last].p);
        all = (all-rem+M)%M;
        fout << all << "\n";
    }else fout << "0\n";
    return 0;
}
