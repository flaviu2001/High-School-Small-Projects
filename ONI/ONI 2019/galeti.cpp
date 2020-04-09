#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "galeti2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

ll n, m, v[100005], r[100005];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = n-1; i >= 1; --i)
        v[n-i] = i;
    --n;
    ll rem = n*(n+1)/2;
    for (int i = n; i >= 1; --i){
        ll del = min(rem-m, v[i]-1);
        v[i] -= del;
        rem -= del;
        r[i] = 1;
    }
    int I = n, l;
    while(v[I-1] == 1)
        --I;
    l = I-1;
    v[0] = n+1;
    r[0] = 1;
    while(1){
        fout << I+1 << " " << l+1 << "\n";
        r[l] += r[I];
        r[I] = 0;
        if(v[l] == r[l]){
            if(l == 0)
                break;
            while(l > 0 && r[l] == v[l]){
                fout << l+1 << " " << l << "\n";
                r[l-1] += r[l];
                r[l] = 0;
                --l;
            }
            if(l == 0 && r[l] == v[l])
                break;
        }
        ++I;
    }
    return 0;
}
