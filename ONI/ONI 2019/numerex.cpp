#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "numerex";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, test, sq;
ll v[100005], ba[1005], bk[1005], b2[1005];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> test;
    sq = sqrt(n);
    while(test--){
        ll t;
        fin >> t;
        if(t == 0){
            int a, b, k;
            fin >> a >> b >> k;
            --a;
            b = a+b-1;
            ll a0 = k;
            int nb = a;
            if(nb%sq != 0){
                nb -= nb%sq;
                nb += sq;
                nb = min(nb, b+1);
            }
            for (int i = a; i < nb; ++i){
                v[i] += a0;
                b2[i/sq] += a0;
                a0 += k;
            }
            a = nb;
            while(a+sq-1 <= b){
                ba[a/sq] += a0;
                bk[a/sq] += k;
                a0 += sq*k;
                a += sq;
            }
            for (int i = a; i <= b; ++i){
                v[i] += a0;
                b2[i/sq] += a0;
                a0 += k;
            }
        }else{
            int a, b;
            fin >> a >> b;
            --a, --b;
            ll ans = 0, add = ba[a/sq];
            int nb = a;
            if(nb%sq != 0){
                nb -= nb%sq;
                nb += sq;
                nb = min(nb, b+1);
            }
            add += bk[a/sq]*(a%sq);
            for (int i = a; i < nb; ++i){
                ans += add + v[i];
                add += bk[i/sq];
            }
            a = nb;
            while(a+sq-1 <= b){
                ans += b2[a/sq] + ba[a/sq]*sq+bk[a/sq]*(sq-1)*sq/2;
                a += sq;
            }
            add = ba[a/sq];
            for (int i = a; i <= b; ++i){
                ans += add+v[i];
                add += bk[i/sq];
            }
            fout << ans << "\n";
        }
    }
    return 0;
}
