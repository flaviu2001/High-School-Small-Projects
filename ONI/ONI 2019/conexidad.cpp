#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "conexidad";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int n, m, c[nmax], rng[nmax], free1[nmax], free2[nmax];

int find(int x)
{
    if(c[x] == x)
        return x;
    return c[x] = find(c[x]);
}

void unite(int x, int y, int val)
{
    if(x == y)
        return;
    if(rng[x] < rng[y]){
        c[x] = y;
        free1[y] = val;
    }else{
        c[y] = x;
        free1[x] = val;
    }
    if(rng[x] == rng[y])
        ++rng[x];
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    int edgesadd = n-1, sol = 1;
    for (int i = 1; i <= n; ++i)
        c[i] = i, rng[i] = 1, free1[i] = 1;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        if(find(x) != find(y))
            --edgesadd;
        unite(find(x), find(y), free1[find(x)]+free1[find(y)]);
    }
    vector<pi> ans;
    for (int t = 1; t <= edgesadd; ++t){
        bool foundsol = false;
        if(sol == 1){
            int mx = 0, I = -1;
            for (int i = 1; i <= n; ++i)
                if(free1[find(i)] > mx && free2[i] == 0){
                    mx = free1[find(i)];
                    I = i;
                }
            if(mx != 0){
                int mn = inf, I2 = -1;
                for (int i = 1; i <= n; ++i)
                    if(free1[find(i)] < mn && free2[i] == 0 && find(i) != find(I)){
                        mn = free1[find(i)];
                        I2 = i;
                    }
                if(mn != inf){
                    unite(find(I), find(I2), free1[find(I)]+free1[find(I2)]-2);
                    ++free2[I];
                    ++free2[I2];
                    ans.push_back({I, I2});
                    foundsol = true;
                }
            }
        }
        if(!foundsol){
            sol = 2;
            int I = -1;
            for (int i = 1; i <= n; ++i)
                if(free2[i] <= 1){
                    I = i;
                    break;
                }
            int I2 = -1;
            for (int i = 1; i <= n; ++i)
                if(find(I) != find(i) && free2[i] <= 1){
                    I2 = i;
                    break;
                }
            unite(find(I), find(I2), free1[find(I)]+free1[find(I2)]-2);
            ++free2[I];
            ++free2[I2];
            ans.push_back({I, I2});
        }
    }
    fout << sol << "\n" << edgesadd << "\n";
    for (auto x : ans)
        fout << x.ff << " " << x.ss << "\n";

    return 0;
}
