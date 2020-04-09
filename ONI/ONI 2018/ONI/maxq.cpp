#include <bits/stdc++.h>
 
using namespace std;
 
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
        if (vu32 <= 9) {
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
 
struct arb{
    long long val = -200000000000000000, st = -2000000000000000, dr = -2000000000000000, sum = 0;
} r[4*200005], sol;
 
long long n, v[200005], test;
 
void update(long long nod, long long st, long long dr, long long pos, long long val)
{
    if(st == dr){
        r[nod].sum = val;
        r[nod].st = val;
        r[nod].dr = val;
        r[nod].val = val;
        return;
    }
    long long m = (st+dr)/2;
    if(m >= pos)
        update(nod*2, st, m, pos, val);
    else update(nod*2+1, m+1, dr, pos, val);
    r[nod].sum = r[nod*2].sum + r[nod*2+1].sum;
    r[nod].st = max(r[nod*2].st, r[nod*2].sum+r[nod*2+1].st);
    r[nod].dr = max(r[nod*2+1].dr, r[nod*2+1].sum+r[nod*2].dr);
    r[nod].val = max(r[nod*2].val, r[nod*2+1].val);
    r[nod].val = max(r[nod].val, r[nod*2].dr+r[nod*2+1].st);
}
 
void query (long long nod, long long st, long long dr, long long l, long long f)
{
    if(st >= l && dr <= f){
        sol.val = max(sol.val, r[nod].val);
        sol.val = max(sol.val, sol.dr+r[nod].st);
        sol.st = max(sol.st, sol.sum+r[nod].st);
        sol.dr = max(r[nod].dr, r[nod].sum+sol.dr);
        sol.sum = sol.sum + r[nod].sum;
        return;
    }
    long long m = (st+dr)/2;
    if(m >= l)
        query(nod*2, st, m, l, f);
    if(m < f)
        query(nod*2+1, m+1, dr, l, f);
}
 
int main()
{
    InParser fin ("maxq.in");
    OutParser fout ("maxq.out");
    fin >> n;
    for (long long i = 1; i <= n; ++i){
        fin >> v[i];
        update(1, 1, n, i, v[i]);
    }
    fin >> test;
    while(test--){
        long long t, x, y;
        fin >> t >> x >> y;
        ++x;
        if(t == 0)
            update(1, 1, n, x, y);
        else{
            ++y;
            sol.val = -20000000000000000;
            sol.st =  -20000000000000000;
            sol.dr =  -20000000000000000;
            sol.sum = 0;
            query(1, 1, n, x, y);
            if(sol.val < 0)
                sol.val = 0;
            fout << sol.val << "\n";
        }
    }
    return 0;
}
