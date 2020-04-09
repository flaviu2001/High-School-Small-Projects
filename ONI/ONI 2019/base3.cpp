#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "base3";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 16005;

int n[3], valmax, c[nmax];
string s[3];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    for (int i = 0; i < 3; ++i){
        fin >> s[i];
        n[i] = s[i].length();
        valmax = max(valmax, n[i]);
    }
    for (int i = 0; i < nmax; ++i)
        c[i] = inf;
    c[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (int i = 0; i < 3; ++i){
            if(k-n[i] >= -valmax && c[abs(k)]+n[i] < c[abs(k-n[i])]){
                c[abs(k-n[i])] = c[abs(k)]+n[i];
                q.push(k-n[i]);
            }
            if(k+n[i] <= valmax && c[abs(k)]+n[i] < c[abs(k+n[i])]){
                c[abs(k+n[i])] = c[abs(k)]+n[i];
                q.push(k+n[i]);
            }
        }
    }
    int sol = inf;
    for (int t = 0; t < 3; ++t)
        for (int i = 0; i < n[t]; ++i)
            if(s[t][i] == '1' && c[abs(n[t]-1-2*i)] != inf)
                sol = min(sol, n[t]+c[abs(n[t]-1-2*i)]);
    fout << (sol == inf ? 0 : sol) << "\n";
    return 0;
}
