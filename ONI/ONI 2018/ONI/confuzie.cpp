#include <bits/stdc++.h>

using namespace std;

int n, test, p, depth[200005], tt[200005], subtree[200005], carelant[200005], poslant[200005];
bool ok[200005];
vector<int> v[200005], lnt[200005];
vector< pair<int, int> > arb[200005];
pair<int, int> vl[200005];

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

    InParser& operator >> (long long &n) {
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

    OutParser& operator << (long long vu64) {
        if (vu64 <= 9) {
            write_ch(vu64 + '0');
        } else {
            (*this) << (vu64 / 10);
            write_ch(vu64 % 10 + '0');
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

void dfs (int x, int pred = 0)
{
    tt[x] = pred;
    ok[x] = 1;
    depth[x] = depth[tt[x]]+1;
    subtree[x] = 1;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[*it]){
            dfs(*it, x);
            subtree[x] += subtree[*it];
        }
}

void dfLanturi(int x)
{
    ok[x] = 0;
    int care = 0, mx = -1;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(ok[*it]){
            dfLanturi(*it);
            if(subtree[*it] > mx){
                care = *it;
                mx = subtree[*it];
            }
        }
    if(care == 0){
        ++p;
        lnt[p].push_back(x);
        poslant[x] = lnt[p].size()-1;
        carelant[x] = p;
    }else{
        lnt[carelant[care]].push_back(x);
        poslant[x] = lnt[carelant[care]].size()-1;
        carelant[x] = carelant[care];
    }
}

pair<int, int> max(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first ? p1 : p2;
}

void build(int nod, int lo, int hi, int carearb)
{
    if(lo == hi){
        arb[carearb][nod] = vl[lnt[carearb][lo]];
        return;
    }
    int m = (lo+hi)/2;
    build(nod*2, lo, m, carearb);
    build(nod*2+1, m+1, hi, carearb);
    arb[carearb][nod] = max(arb[carearb][nod*2], arb[carearb][nod*2+1]);
}

void update(int nod, int lo, int hi, pair<int, int> val, int pos, int carearb)
{
    if(lo == hi){
        arb[carearb][nod] = val;
        return;
    }
    int m = (lo+hi)/2;
    if(m >= pos)
        update(nod*2, lo, m, val, pos, carearb);
    else update(nod*2+1, m+1, hi, val, pos, carearb);
    arb[carearb][nod] = max(arb[carearb][nod*2], arb[carearb][nod*2+1]);
}

pair<int, int> queryarb(int nod, int lo, int hi, int l, int r, int carearb)
{
    if(lo >= l && hi <= r)
        return arb[carearb][nod];
    pair<int, int> mx = make_pair(0, -1);
    int m = (lo+hi)/2;
    if(m >= l)
        mx = max(mx, queryarb(nod*2, lo, m, l, r, carearb));
    if(m < r)
        mx = max(mx, queryarb(nod*2+1, m+1, hi, l, r, carearb));
    return mx;
}

int hpd(int x, int y)
{
    pair<int, int> mx = make_pair(0, -1);
    while(1)
    {
        if(depth[tt[lnt[carelant[x]].back()]] < depth[tt[lnt[carelant[y]].back()]])
            swap(x, y);
        if(carelant[x] == carelant[y]){
            if(x == y)
                return max(mx, vl[x]).second;
            if(poslant[x] > poslant[y])
                swap(x, y);
            return max(mx, queryarb(1, 0, lnt[carelant[x]].size()-1, poslant[x], poslant[y], carelant[x])).second;
        }
        mx = max(mx, queryarb(1, 0, lnt[carelant[x]].size()-1, poslant[x], lnt[carelant[x]].size()-1, carelant[x]));
        x = tt[lnt[carelant[x]].back()];
    }
    return 0;
}

int main()
{
    InParser fin ("confuzie.in");
    OutParser fout ("confuzie.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i)
        vl[i] = make_pair(-1, i);
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    p = 0;
    dfLanturi(1);
    for (int i = 1; i <= p; ++i){
        arb[i].resize((lnt[i].size()+2)*4);
        build(1, 0, lnt[i].size()-1, i);
    }
    while(test--){
        int t, x, y;
        fin >> t >> x;
        if(t == 0){
            if(vl[x].first == -1)
                vl[x].first = 300001-depth[x];
            else
                vl[x].first = -1;
            update(1, 0, lnt[carelant[x]].size()-1, vl[x], poslant[x], carelant[x]);
        }
        else{
            fin >> y;
            fout << hpd(x, y) << "\n";
        }
    }
    return 0;
}

