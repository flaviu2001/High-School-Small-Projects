#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//need parser for 100

const ll inf = (1ll<<62);
int n, sq, test, v[100005];
ll bdif[400], bs[400];

int main()
{
    InParser fin ("kami.in");
    OutParser fout ("kami.out");
    fin >> n; sq = sqrt(n);
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 0; i < 400; ++i)
        bdif[i] = -inf;
    for (int i = n; i >= 1; --i){
        bdif[(i-1)/sq] = max(bdif[(i-1)/sq], v[i]-bs[(i-1)/sq]);
        bs[(i-1)/sq] += v[i];
    }
    fin >> test;
    while(test--){
        int t;
        fin >> t;
        if(t == 1){
            int p, I = -1;
            ll s;
            fin >> p;
            s = v[p];
            for (int i = p-1; i >= 1 && (i-1)/sq == (p-1)/sq; --i){
                if(s <= v[i]){
                    I = i;
                    break;
                }
                s += v[i];
            }
            if(I != -1){
                fout << I << "\n";
                continue;
            }
            int bucket = (p-1)/sq-1;
            while(bucket >= 0 && bdif[bucket] < s){
                s += bs[bucket];
                --bucket;
            }
            if(bucket == -1){
                fout << "0\n";
                continue;
            }
            for (int i = min((bucket+1)*sq, n); 1; --i){
                if(s <= v[i]){
                    I = i;
                    break;
                }
                s += v[i];
            }
            fout << I << "\n";
        }else{
            int x, y;
            fin >> x >> y;
            bs[(x-1)/sq] = 0;
            bdif[(x-1)/sq] = -inf;
            v[x] = y;
            for (int i = min(((x-1)/sq+1)*sq, n); i >= 1 && (i-1)/sq == (x-1)/sq; --i){
                bdif[(i-1)/sq] = max(bdif[(i-1)/sq], v[i]-bs[(i-1)/sq]);
                bs[(x-1)/sq] += v[i];
            }
        }
    }
    return 0;
}

