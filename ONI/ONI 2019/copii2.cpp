#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const int inf = 2147483647;
const ll Inf = 9223372036854775807ll;
const string file = "copii2";

int n, k;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> k;
    int ans = 0, x = n-1;
    while(x){
        ++ans;
        x /= k;
    }
    fout << ans << "\n";
    int pw = 1;
    for (int t = 1; t <= ans; ++t){
        vector<int> v[k];
        int pk = 0, rem = pw;
        for (int j = 0; j < n; ++j){
            int x = j;
            if(x == 0)
                x = n;
            v[pk].push_back(x);
            --rem;
            if(rem == 0){
                ++pk;
                rem = pw;
            }
            if(pk == k)
                pk = 0;
        }
        fout << k << "\n";
        for (int i = 0; i < k; ++i){
            fout << v[i].size() << " ";
            for (auto x : v[i])
                fout << x << " ";
            fout << "\n";
        }
        pw *= k;
    }
    return 0;
}

