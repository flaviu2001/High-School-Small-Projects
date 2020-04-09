#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "mostenire3";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, k, v[100005];
unordered_map< int, deque<int> > dudes;

bool good(int x)
{
    int p = 0, sum = 0;
    for (int i = 1; i <= n; ++i){
        sum += v[i];
        if(sum >= x){
            ++p;
            if(p == k)
                return true;
            sum = 0;
        }
    }
    return false;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    int st = 1, dr = 1000000000, m, ans;
    for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
        if(good(m)){
            ans = m;
            st = m+1;
        }else dr = m-1;
    fout << ans << "\n";
    vector<pi> sol;
    vector<int> r;
    int p = 0, sum = 0, cnt = 0;
    for (int i = 1; i <= n; ++i){
        sum += v[i];
        ++cnt;
        if(sum >= ans && p+1 < k){
            ++p;
            sol.push_back({sum, cnt});
            r.push_back(sum);
            cnt = 0;
            sum = 0;
        }
    }
    sol.push_back({sum, cnt});
    r.push_back(sum);
    sort(r.begin(), r.end());
    for (int i = 1; i <= r.size(); ++i)
        dudes[r[i-1]].push_back(r.size()-i+1);
    for (auto x : sol){
        fout << dudes[x.ff].front() << " " << x.ss << "\n";
        dudes[x.ff].pop_front();
    }
    return 0;
}
