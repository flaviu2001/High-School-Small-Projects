//OJI 2002 codul

#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "codul";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 205;

int v[nmax][nmax];
string s1, s2, best[2][nmax];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> s1 >> s2;
    s1 = "#"+s1;
    s2 = "#"+s2;
    for (int i = 1; i < s1.length(); ++i)
        for (int j = 1; j < s2.length(); ++j)
            if(s1[i] == s2[j]){
                v[i][j] = v[i-1][j-1]+1;
                best[i%2][j] = best[1-(i%2)][j-1] + s1[i];
                if(v[i][j] == v[i-1][j] && best[1-(i%2)][j] > best[i%2][j])
                    best[i%2][j] = best[1-(i%2)][j];
                if(v[i][j] == v[i][j-1] && best[i%2][j-1] > best[i%2][j])
                    best[i%2][j] = best[i%2][j-1];
            }else{
                v[i][j] = v[i-1][j];
                best[i%2][j] = best[1-(i%2)][j];
                if(v[i][j-1] > v[i][j] || (v[i][j-1] == v[i][j] && best[i%2][j-1] > best[i%2][j])){
                    v[i][j] = v[i][j-1];
                    best[i%2][j] = best[i%2][j-1];
                }
            }
    fout << best[(s1.length()-1)%2][s2.length()-1] << "\n";
    return 0;
}
