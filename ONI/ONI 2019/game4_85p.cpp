#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "game4";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int pd[1<<20], test1, test2, n;
bool f[19], ok[1005];
vector<int> primes;
unordered_map<int, int> m;

struct PairHasher {
    int operator()(const pi &V) const {
        return V.ff^V.ss;
    }
};

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> test1 >> test2;
    for (int i = 2; i < 1005; ++i)
        if(!ok[i])
            for (int d = i+i; d < 1005; d += i)
                ok[d] = 1;
    for (int i = 2; i < 1005; ++i)
        if(!ok[i])
            primes.push_back(i);
    for (int cfg = 1; cfg < 1<<20; ++cfg){
        memset(f, 0, sizeof(f));
        for (int k = 1; (1<<k) <= cfg; ++k){
            int now = cfg;
            bool any = false;
            for (int j = k; (1<<j) <= cfg; ++j)
                if(cfg&(1<<j)){
                    any = true;
                    now ^= (1<<j);
                    now |= (1<<(j-k));
                }
            if(any)
                f[pd[now]] = 1;
        }
        for (int i = 0; i < 19; ++i)
            if(f[i])
                ++pd[cfg];
            else break;
    }
    while(test1--){
        m.clear();
        fin >> n;
        for (int i = 1; i <= n; ++i){
            int x;
            fin >> x;
            for (auto d : primes)
                if(x%d == 0){
                    int p = 0;
                    while(x%d == 0){
                        ++p;
                        x /= d;
                    }
                    m[d] |= (1<<p);
                }else if (d*d > x)
                    break;
            if(x != 1)
                m[x] |= (1<<1);
        }
        int sum = 0;
        for (auto x : m)
            sum ^= pd[x.ss];
        if(test2 == 1){
            if(sum == 0)
                fout << "Bob\n";
            else fout << "Alice\n";
        }else{
            if(sum != 0){
                int cnt = 0;
                for (auto x : m){
                    int target = sum^pd[x.ss];
                    for (int k = 1; (1<<k) <= x.ss; ++k){
                        int now = x.ss;
                        for (int j = k; (1<<j) <= x.ss; ++j)
                            if(x.ss&(1<<j)){
                                now ^= (1<<j);
                                now |= (1<<(j-k));
                            }
                        if(pd[now] == target)
                            ++cnt;
                    }
                }
                fout << cnt << "\n";
            }else{
                unordered_set<pi, PairHasher> s;
                for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
                    int target = pd[it->ss];
                    for (int k = 1; (1<<k) <= it->ss; ++k){
                        int now = it->ss;
                        for (int j = k; (1<<j) <= it->ss; ++j)
                            if((it->ss)&(1<<j)){
                                now ^= (1<<j);
                                now |= (1<<(j-k));
                            }
                        int old = it->ss;
                        it->ss = now;
                        target ^= pd[now];
                        for (auto x : m){
                            target ^= pd[x.ss];
                            for (int k = 1; (1<<k) <= x.ss; ++k){
                                int now2 = x.ss;
                                for (int j = k; (1<<j) <= x.ss; ++j)
                                    if((x.ss)&(1<<j)){
                                        now2 ^= (1<<j);
                                        now2 |= (1<<(j-k));
                                    }
                                if(pd[now2] == target)
                                    s.insert({x.ff, k});
                            }
                            target ^= pd[x.ss];
                        }
                        target ^= pd[now];
                        it->ss = old;
                    }
                }
                fout << s.size() << "\n";
            }
        }
    }
    return 0;
}
