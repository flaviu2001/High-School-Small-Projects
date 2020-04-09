#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "multisum";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

int test, test2;
bool ciur[nmax];
vector<int> sol[nmax], divs[nmax];
int pd[nmax];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    for (int i = 2; i < nmax; ++i)
        if(!ciur[i])
            for (int j = i; j < nmax; j += i){
                ciur[j] = 1;
                divs[j].push_back(i);
            }
    pd[1] = pd[2] = 1;
    sol[1].push_back(1);
    sol[2].push_back(2);
    for (int t = 3; t < nmax; ++t){
        pd[t] = -1;
        for (auto d : divs[t-1])
            if((t-1)%d == 0)
                if(pd[(t-1)/d]+1 > pd[t]){
                    pd[t] = pd[(t-1)/d]+1;
                    sol[t].clear();
                    sol[t].push_back(1);
                    for (auto x : sol[(t-1)/d])
                        sol[t].push_back(x*d);
                }else if (pd[(t-1)/d]+1 == pd[t]){
                    vector<int> now;
                    now.push_back(1);
                    for (auto x : sol[(t-1)/d])
                        now.push_back(x*d);
                    sol[t] = min(sol[t], now);
                }
        for (auto d : divs[t])
            if(t%d == 0)
                if(pd[t/d] > pd[t]){
                    pd[t] = pd[t/d];
                    sol[t].clear();
                    for (auto x : sol[t/d])
                        sol[t].push_back(x*d);
                }else if (pd[t/d] == pd[t]){
                    vector<int> now;
                    for (auto x : sol[t/d])
                        now.push_back(x*d);
                    sol[t] = min(sol[t], now);
                }
    }
    fin >> test >> test2;
    while(test--){
        int a, b;
        fin >> a >> b;
        int mx = -1, f = 0;
        for (int i = a; i <= b; ++i){
            if(pd[i] > mx){
                mx = pd[i];
                f = 1;
            }else if (pd[i] == mx)
                ++f;
        }
        if(test2 == 1)
            fout << mx << "\n";
        else if (test2 == 2)
            fout << f << "\n";
        else{
            vector<int> ans = {inf};
            for (int i = a; i <= b; ++i)
                if(pd[i] == mx)
                    ans = min(ans, sol[i]);
            int ansx = 0;
            for (auto x : ans)
                ansx += x;
            fout << ansx << "\n";
        }
    }
    return 0;
}
