#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "ciocolata";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

ll test, v[20], pd[(1<<17)+5];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test;
    pd[0] = 0;
    pd[1<<2] = 2;
    pd[1<<3] = -1;
    pd[(1<<2)+(1<<3)] = 1;
    for (int i = 1<<4; i < (1<<17); ++i)
        if((i&1) == (i&2) && (i&1) == 0){
            pd[i] = 3;
            if(i&4)
                pd[i] = min(pd[i], 2-pd[i^4]);
            if(i&8)
                pd[i] = min(pd[i], 1-pd[i^8^4]);
            for (int k = 4; (1<<k) <= i; ++k)
                if(i&(1<<k)){
                    pd[i] = min(pd[i], 1-pd[i^(1<<k)^(1<<(k-1))]);
                    for (int j = 2; j <= k-j; ++j){
                        int now = i^(1<<k)^(1<<j)^(1<<(k-j));
                        pd[i] = min(pd[i], -pd[now]);
                    }
                }
        }
    while(test--){
        int state = 0, sum = 0;
        for (ll i = 2; i <= 16; ++i){
            fin >> v[i];
            sum += v[i]*i;
            if(v[i]%2==1)
                state |= (1<<i);
        }
        fout << (sum+pd[state])/2 << " " << (sum-pd[state])/2 << "\n";
    }
    return 0;
}
