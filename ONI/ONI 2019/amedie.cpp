#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "amedie";
const ll Inf = 9223372036854775807ll;
const int inf = 2147483647;

int n, m, test, aib[100005], v[802][802], rem;
bool ok[802][802];

void update(int idx, int val)
{
    while(idx <= 100000){
        aib[idx] += val;
        idx += (idx & (-idx));
    }
}

int read(int idx)
{
    int sum = 0;
    while(idx){
        sum += aib[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}


int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> test;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            fin >> v[i][j];
            update(v[i][j], 1);
        }
    rem = n*m;
    while(test--){
        char t;
        fin >> t;
        if(t == 'Q'){
            int st = 1, dr = 100000, mid, lf = (rem+1)/2, ans = 0;
            for (mid = (st+dr)/2; st <= dr; mid = (st+dr)/2)
                if(read(mid) >= lf){
                    ans = mid;
                    dr = mid-1;
                }else st = mid+1;
            fout << ans << "\n";
        }else{
            int p;
            fin >> p;
            if(t == 'L'){
                for (int j = 1; j <= m; ++j)
                    if(!ok[p][j]){
                        ok[p][j] = 1;
                        update(v[p][j], -1);
                        --rem;
                    }
            }else for (int i = 1; i <= n; ++i)
                    if(!ok[i][p]){
                        ok[i][p] = 1;
                        update(v[i][p], -1);
                        --rem;
                    }
        }
    }
    return 0;
}
