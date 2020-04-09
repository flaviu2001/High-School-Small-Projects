#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "turnuri4";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, v[nmax], lg2[nmax], PD[20][nmax], s[nmax], d[nmax], s2[nmax], d2[nmax], rs[nmax], rd[nmax];

int rmq(int a, int b)
{
    if(a == b)
        return v[a];
    return max(PD[lg2[b-a]][a], PD[lg2[b-a]][b-(1<<lg2[b-a])]);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    lg2[2] = 1;
    for (int i = 3; i < nmax; ++i)
        lg2[i] = lg2[i/2]+1;
    v[0] = v[n+1] = inf;
    for (int i = 0; i <= n; ++i)
        PD[0][i] = max(v[i], v[i+1]);
    for (int t = 1; t <= lg2[n+1]; ++t)
        for (int i = 0; i <= n+1-(1<<t); ++i)
            PD[t][i] = max(PD[t-1][i], PD[t-1][i+(1<<(t-1))]);
    for (int i = 1; i <= n; ++i){
        int st, dr, m;
        st = i+1, dr = n+1;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(rmq(i+1, m) > v[i]){
                d[i] = m;
                dr = m-1;
            }else st = m+1;
        d2[i] = n+1;
        if(d[i] != n+1){
            st = d[i]+1, dr = n+1;
            for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
                if(rmq(d[i]+1, m) > v[i]){
                    d2[i] = m;
                    dr = m-1;
                }else st = m+1;
        }
        st = 0, dr = i-1;
        for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
            if(rmq(m, i-1) > v[i]){
                s[i] = m;
                st = m+1;
            }else dr = m-1;
        s2[i] = 0;
        if(s[i] != 0){
            st = 0, dr = s[i]-1;
            for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
                if(rmq(m, s[i]-1) > v[i]){
                    s2[i] = m;
                    st = m+1;
                }else dr = m-1;
        }

    }
    ll all = -n;
    for (int i = 1; i <= n; ++i){
        rs[s[i]] += s[i]-s2[i];
        rd[d[i]] += d2[i]-d[i];
        all += d[i]-s[i];
    }
    for (int i = 1; i <= n; ++i){
        ll sol = all+rs[i]+rd[i]-(d[i]-s[i]-1)+1;
        fout << sol << "\n";
    }
    return 0;
}
