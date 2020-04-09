#include <bits/stdc++.h>
#define ff first
#define ss second
	
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
	
const string file = "joc3";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;
	
int n, v[100005];
	
int main()	
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        if((n-i)%2 == 1)
            sum ^= v[i];
    }
    if(sum == 0)
        fout << sum-1 << "\n";
    else{
        for (int i = 1; i <= n; ++i)
            if((n-i)%2 == 1){
                int now = sum^v[i];
                if(v[i] > now){
                    fout << i << " " << v[i]-now << "\n";
                    break;
                }
            }
    }
    return 0;	
}