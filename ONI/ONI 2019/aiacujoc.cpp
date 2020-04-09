#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "aiacujoc";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int test, dudesa[2200006], dudesb[2200006];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test;
    while(test--){
        int a, b, k;
        fin >> a >> b >> k;++k;
        memset(dudesa, 0, sizeof(dudesa));
        memset(dudesb, 0, sizeof(dudesb));
        ll sol = 0;
        for (int i = 0; i < min(a, k); ++i)
            dudesa[(i%k)^((a-1-i)%k)] += (a-i+k-1)/k;
        for (int i = 0; i < min(b, k); ++i)
            sol += 1ll*dudesa[(i%k)^((b-1-i)%k)]*((b-i+k-1)/k);
        fout << sol << "\n";
    }
    return 0;
}
