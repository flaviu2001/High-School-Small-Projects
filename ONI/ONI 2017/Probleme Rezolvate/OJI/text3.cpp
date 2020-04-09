#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "text3";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, pred[20005], b[20005], pd[300], pdprev[300];
string s[20005];
vector<string> sol;

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    int mx = 0, I;
    while(fin >> s[++n]){
        b[n] = pd[s[n][0]]+1;
        pred[n] = pdprev[s[n][0]];
        if(b[n] > pd[s[n].back()]){
            pd[s[n].back()] = b[n];
            pdprev[s[n].back()] = n;
        }
        if(b[n] > mx){
            mx = b[n];
            I = n;
        }
    }
    --n;
    fout << n << "\n" << n-mx << "\n";
    while(I){
        sol.push_back(s[I]);
        I = pred[I];
    }
    reverse(sol.begin(), sol.end());
    for (auto x : sol)
        fout << x << "\n";
    return 0;
}
