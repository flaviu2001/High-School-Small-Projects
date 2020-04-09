#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "manacher";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1000006;

string b;
int r[nmax*2];

void manacher(string s, int p[]) //p[i] = how many indices to move to left and right to get maximum palindrome on position i.
{
    string t;
    t.push_back(s[0]);
    for (int i = 1; i < s.length(); ++i){
        t.push_back('#');
        t.push_back(s[i]);
    }
    p[0] = 0;
    int l = 0, r = 0, c = 0;
    for (int i = 1; i < t.length(); ++i){
        int i_ = c*2-i;
        if(i_ <= l || i_-p[i_] <= l){
            if(i > r)
                l = i, r = i, c = i;
            else{
                c = i;
                l = c*2-r;
            }
            while(l >= 0 && r < t.length() && t[l] == t[r])
                --l, ++r;
            ++l, --r;
            p[i] = r-c;
        }else p[i] = p[i_];
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> b;
    manacher(b, r);
    return 0;
}
