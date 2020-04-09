#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "munte4";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, v[2000006];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= n; ++i)
        v[i+n] = v[i];
    for (int i = 2; i <= n*2; ++i)
        v[i] += i-1;
    int I, mn = inf;
    deque<int> d;
    d.push_back(1);
    for (int i = 2; i <= n*2; ++i){
        if(i-d.front()==n)
            d.pop_front();
        while(!d.empty() && v[d.back()] <= v[i])
            d.pop_back();
        d.push_back(i);
        if(i >= n && v[d.front()]-(i-n) < mn){
            I = i-n+1;
            mn = v[d.front()]-(i-n);
        }
    }
    fout << I << " " << mn << "\n";
    return 0;
}
