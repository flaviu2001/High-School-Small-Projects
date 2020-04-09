//https://www.infoarena.ro/problema/vmin

#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "vmin";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

struct line{
    int a, b, i;
    bool operator<(const line &obj)const{
        if(a != obj.a)
            return a > obj.a;
        return b < obj.b;
    }
} l[nmax];

int n, m;
vector<line> s;

bool check(line x, line y, line z)
{
    return 1ll*(y.b-x.b)*(x.a-z.a) >= 1ll*(x.a-y.a)*(z.b-x.b);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fin >> l[i].a >> l[i].b;
        l[i].i = i;
    }
    sort(l+1, l+n+1);
    s.push_back(l[1]);
    for (int i = 2; i <= n; ++i){
        if(l[i].a == s.back().a)
            continue;
        while(s.size() > 1 && check(s[s.size()-2], s[s.size()-1], l[i]))
            s.pop_back();
        s.push_back(l[i]);
    }
    int pointer = 0;
    for (int i = 1; i <= m; ++i){
        int t;
        fin >> t;
        while(pointer < s.size()-1 && 1ll*s[pointer].a*t+s[pointer].b > 1ll*s[pointer+1].a*t+s[pointer+1].b)
            ++pointer;
        fout << s[pointer].i << " ";
    }
    return 0;
}
