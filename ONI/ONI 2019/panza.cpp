#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "panza";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 100005;

class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch() {
        ++sp;
        if (sp == 4096) {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
};

struct state{
    int n, m;
    bool hasm;
    ll d;
    bool operator<(const state &obj)const{
        return d > obj.d;
    }
};

int n, m, l[nmax];
pi in[nmax];
vector< vector<ll> > d[2];
vector< vector<bool> > inq[2];

int main()
{
    InParser fin ("panza.in");
    ofstream fout (file+".out");
    int s, f;
    fin >> n >> m >> s >> f;
    for (int i = 0; i < 2; ++i)
        for (int t = 0; t <= n+1; ++t){
            d[i].push_back(vector<ll>(m+2, INF));
            inq[i].push_back(vector<bool>(m+2, 0));
        }
    for (int i = 1; i <= m; ++i)
        fin >> l[i];
    for (int i = 1; i <= n; ++i)
        fin >> in[i].ff >> in[i].ss;
    state beg;
    beg.n = 1, beg.m = s, beg.d = 0;
    if(in[1].ff <= s && in[1].ss >= s)
        beg.hasm = 1;
    else beg.hasm = 0;
    d[beg.hasm][beg.n][beg.m] = 0;
    priority_queue<state> q;
    q.push(beg);
    while(!q.empty()){
        state now = q.top();
        q.pop();
        now.d = d[now.hasm][now.n][now.m];
        inq[now.hasm][now.n][now.m] = 0;
        state up, down, dr;
        up.n = down.n = dr.n = -1;
        if(now.m+1 <= m && (now.n == n || now.m+1 <= in[now.n].ff))
            up.n = now.n, up.m = now.m+1, up.hasm = now.hasm | (in[now.n].ff <= now.m+1 && in[now.n].ss >= now.m+1), up.d = now.d+1;
        if(now.m-1 >= 1)
            down.n = now.n, down.m = now.m-1, down.hasm = now.hasm | (in[now.n].ff <= now.m-1 && in[now.n].ss >= now.m-1), down.d = now.d+1;
        if(now.hasm && now.n < n)
            dr.n = now.n+1, dr.m = now.m, dr.hasm = (in[now.n+1].ff <= now.m && in[now.n+1].ss >= now.m), dr.d = now.d+l[now.m];
        if(up.n != -1 && d[up.hasm][up.n][up.m] > up.d){
            d[up.hasm][up.n][up.m] = up.d;
            if(!inq[up.hasm][up.n][up.m]){
                q.push(up);
                inq[up.hasm][up.n][up.m] = 1;
            }
        }
        if(down.n != -1 && d[down.hasm][down.n][down.m] > down.d){
            d[down.hasm][down.n][down.m] = down.d;
            if(!inq[down.hasm][down.n][down.m]){
                q.push(down);
                inq[down.hasm][down.n][down.m] = 1;
            }
        }
        if(dr.n != -1 && d[dr.hasm][dr.n][dr.m] > dr.d){
            d[dr.hasm][dr.n][dr.m] = dr.d;
            if(!inq[dr.hasm][dr.n][dr.m]){
                q.push(dr);
                inq[dr.hasm][dr.n][dr.m] = 1;
            }
        }
    }
    fout << d[1][n][f] << "\n";
    return 0;
}
