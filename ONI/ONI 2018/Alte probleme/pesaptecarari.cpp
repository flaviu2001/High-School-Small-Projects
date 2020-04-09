#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

    InParser& operator >> (ll &n) {
        char c;
        n = 0;
        while (!isdigit(c = read_ch()) && c != '-');
        long long sgn = 1;
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

struct node{
    int curr, x;
    bool operator<(const node &obj)const{
        return curr < obj.curr;
    }
    void operator=(const ll v[]){
        curr = v[0];
        x = v[1];
    }
};

const ll nmax = 100005, inf = 2000000000;
int d[nmax], prv[nmax], sol[nmax], add[nmax], sz, ans = inf, kdiv, n, m;
ll kpow, c[nmax];
vector<int> v[nmax];

void dijkstra(ll pw)
{
    queue<node> s;
    for (int i = 1; i <= n; ++i)
        d[i] = inf;
    d[1] = add[1];
    s.push({d[1], 1});
    while(!s.empty()){
        node now = s.front();
        s.pop();
        if(now.curr > d[now.x])
            continue;
        for (vector<int>::iterator it = v[now.x].begin(); it != v[now.x].end(); ++it)
            if(d[now.x]+add[*it] < d[*it]){
                prv[*it] = now.x;
                d[*it] = now.curr+add[*it];
                s.push({d[*it], *it});
            }
    }
    if(d[n]/kdiv < ans){
        ans = d[n]/kdiv;
        int now = n;
        sz = 0;
        while(now != 1){
            sol[sz++] = now;
            now = prv[now];
        }
        sol[sz++] = 1;
    }
}

int main()
{
    InParser fin ("pesaptecarari.in");
    ofstream fout ("pesaptecarari.out");
    fin >> n >> m >> kpow;
    for (ll i = 1; i <= n; ++i)
        fin >> c[i];
    for (ll i = 1; i <= m; ++i){
        ll x, y;
        fin >> x >> y;
        v[x].push_back(y);
    }
    for (ll i = 2; i*i <= kpow; ++i)
        if(kpow%i == 0){
            kdiv = 0;
            while(kpow%i == 0){
                ++kdiv;
                kpow /= i;
            }
            for (int j = 1; j <= n; ++j){
                add[j] = 0;
                ll var = c[j];
                while(var%i == 0){
                    ++add[j];
                    var /= i;
                }
            }
            dijkstra(i);
        }
    if(kpow != 1){
        kdiv = 1;
        for (int j = 1; j <= n; ++j){
            add[j] = 0;
            ll var = c[j];
            while(var%kpow == 0){
                ++add[j];
                var /= kpow;
            }
        }
        dijkstra(kpow);
    }
    fout << ans << "\n";
    for (int i = sz-1; i >= 0; --i)
        fout << sol[i] << " ";
    return 0;
}

