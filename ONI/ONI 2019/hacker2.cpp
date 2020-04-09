#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

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

class OutParser {
private:
    FILE *fout;
    char *buff;
    int sp;

    void write_ch(char ch) {
        if (sp == 50000) {
            fwrite(buff, 1, 50000, fout);
            sp = 0;
            buff[sp++] = ch;
        } else {
            buff[sp++] = ch;
        }
    }


public:
    OutParser(const char* name) {
        fout = fopen(name, "w");
        buff = new char[50000]();
        sp = 0;
    }
    ~OutParser() {
        fwrite(buff, 1, sp, fout);
        fclose(fout);
    }

    OutParser& operator << (int vu32) {
        if(vu32 == -1){
            write_ch('-');
            write_ch('1');
        } else if (vu32 <= 9) {
            write_ch(vu32 + '0');
        } else {
            (*this) << (vu32 / 10);
            write_ch(vu32 % 10 + '0');
        }
        return *this;
    }

    OutParser& operator << (char ch) {
        write_ch(ch);
        return *this;
    }
    OutParser& operator << (const char *ch) {
        while (*ch) {
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
};


struct thing{
    int x, d;
    bool operator<(const thing &obj)const{
        return d < obj.d;
    }
};

int n, m, prv[nmax], d[nmax], furthest, tt[20][nmax], ctt[20][nmax], tt2[20][nmax], ctt2[20][nmax], depth[nmax], lg2[nmax*2], close[nmax], dist[nmax];
vector<pi> v[nmax];
bool ok[nmax], isdm[nmax];
thing pd[20][nmax];

void bfs(int nod)
{
    queue<int> q;
    q.push(nod);
    int mxn = 0;
    furthest = nod;
    prv[nod] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        ok[k] = 1;
        for (auto x : v[k])
            if(!ok[x.ff]){
                d[x.ff] = d[k] + x.ss;
                if(d[x.ff] > mxn){
                    mxn = d[x.ff];
                    furthest = x.ff;
                }
                prv[x.ff] = k;
                q.push(x.ff);
            }
    }
}

void dfs(int x, int pred = 0)
{
    tt[0][x] = pred;
    depth[x] = depth[pred]+1;
    for (auto y : v[x])
        if(y.ff != pred){
            ctt[0][y.ff] = y.ss;
            dfs(y.ff, x);
        }
}

void closest(int x, int now, int pred = 0)
{
    close[x] = now;
    for (auto y : v[x])
        if(y.ff != pred){
            if(isdm[y.ff])
                closest(y.ff, y.ff, x);
            else{
                dist[y.ff] = dist[x] + y.ss;
                closest(y.ff, now, x);
            }
        }
}

void dfs3(int x, int pred = 0)
{
    tt2[0][x] = pred;
    for (auto y : v[x])
        if(y.ff != pred){
            ctt2[0][y.ff] = y.ss;
            dfs3(y.ff, x);
        }
}

int main()
{
    InParser fin ("hacker2.in");
    OutParser fout ("hacker2.out");
    fin >> n >> m;
    for (int i = 1; i < n; ++i){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    bfs(1);
    ctt2[0][furthest] = inf;
    for (int i = 1; i <= 19; ++i)
        for (int j = 1; j <= n; ++j)
            ctt2[i][j] = inf;
    dfs3(furthest);
    for (int i = 1; (1<<i) <= n; ++i)
        for (int j = 1; j <= n; ++j){
            tt2[i][j] = tt2[i-1][tt2[i-1][j]];
            if(tt2[i][j] != 0)
                ctt2[i][j] = ctt2[i-1][j] + ctt2[i-1][tt2[i-1][j]];
        }
    memset(ok, 0, sizeof(ok));
    memset(d, 0, sizeof(d));
    bfs(furthest);
    int x = furthest;
    while(x){
        isdm[x] = 1;
        x = prv[x];
    }
    ctt[0][furthest] = inf;
    for (int i = 1; i <= 19; ++i)
        for (int j = 1; j <= n; ++j)
            ctt[i][j] = inf;
    dfs(furthest);
    lg2[2] = 1;
    for (int i = 3; i < nmax*2; ++i)
        lg2[i] = lg2[i/2]+1;
    for (int i = 1; (1<<i) <= n; ++i)
        for (int j = 1; j <= n; ++j){
            tt[i][j] = tt[i-1][tt[i-1][j]];
            if(tt[i][j] != 0)
                ctt[i][j] = ctt[i-1][j] + ctt[i-1][tt[i-1][j]];
        }
    closest(furthest, furthest);
    while(m--){
        int x, z, dd;
        fin >> x >> z;
        dd = dist[x];
        if(dd <= z){
            z -= dd;
            x = close[x];
            int x1 = x, z1 = z;
            for (int i = 19; i >= 0; --i){
                if(ctt[i][x1] < z1){
                    z1 -= ctt[i][x1];
                    x1 = tt[i][x1];
                }
            }
            if(x1 != furthest){
                fout << x1 << " " << tt[0][x1] << " " << z1 << "\n";
                continue;
            }
            int x2 = x, z2 = z;
            for (int i = 19; i >= 0; --i){
                if(ctt2[i][x2] < z2){
                    z2 -= ctt2[i][x2];
                    x2 = tt2[i][x2];
                }
            }
            fout << x2 << " " << tt2[0][x2] << " " << z2 << "\n";
        }else{
            for (int i = 19; i >= 0; --i){
                if(ctt[i][x] < z){
                    z -= ctt[i][x];
                    x = tt[i][x];
                }
            }
            fout << x << " " << tt[0][x] << " " << z << "\n";
        }
    }
    return 0;
}
