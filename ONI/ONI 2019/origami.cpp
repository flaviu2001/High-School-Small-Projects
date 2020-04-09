#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const string file = "origami2";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1000006;

string s[nmax], s2[nmax];
int n, m, *r[nmax], e[nmax], spr[nmax];
ll sol1 = 1, sol2 = 1;

void manacher(string S, int P[])
{
    string t;
    t.push_back(S[0]);
    for (int i = 1; i < S.length(); ++i){
        t.push_back('#');
        t.push_back(S[i]);
    }
    vector<int> v, p;
    p.push_back(0);
    int l = 0, r = 0, c = 0;
    for (int i = 1; i < t.length(); ++i){
        int i_ = c*2-i;
        if(i_ <= l || i_-p[i_] <= l){
            if(i > r)
                l = i, r = i, c = i;
            else
                c = i, l = i*2-r;
            while(l >= 0 && r < t.length() && t[l] == t[r])
                --l, ++r;
            ++l, --r;
            p.push_back(r-c);
        }else p.push_back(p[i_]);
        if(t[i] == '#')
            v.push_back(p[i]+p[i]%2);
    }
    for (int i = 0; i < v.size(); ++i)
        P[i] = v[i];
}

void origami(int n, int m, ll &sol)
{
    for (int j = 0; j < m-1; ++j){
        e[j] = r[1][j];
        for (int i = 2; i <= n; ++i)
            e[j] = min(e[j], r[i][j]);
    }
    int lf = m-1;
    for (int j = m-2; j >= 0; --j){
        spr[j] = spr[j+1];
        if(j+e[j]/2 >= lf){
            ++spr[j];
            lf = j;
        }
    }
    sol += spr[0];
    lf = -1;
    for (int j = 0; j <= m-2; ++j){
        if(j-e[j]/2 <= lf){
            sol += spr[j+1]+1;
            lf = j;
        }
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fin >> s[i];
        r[i] = new int[m];
        manacher(s[i], r[i]);
    }
    origami(n, m, sol1);
    for (int i = 1; i <= n; ++i)
        delete r[i];
    memset(e, 0, sizeof(e));
    memset(spr, 0, sizeof(spr));
    for (int j = 0; j < m; ++j){
        string c;
        for (int i = 1; i <= n; ++i)
            c.push_back(s[i][j]);
        s2[j+1] = c;
        r[j+1] = new int[n];
        manacher(s2[j+1], r[j+1]);
    }
    origami(m, n, sol2);
    fout << 1ll*sol1*sol2 << "\n";
    return 0;
}
