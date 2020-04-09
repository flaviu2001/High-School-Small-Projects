#include <bits/stdc++.h>
#define BUF_SIZE 1<<17

using namespace std;

struct pentru_arbore{
    long long time, pos;

    bool operator< (const pentru_arbore &obj)const{
        return time<obj.time;
    }
};

struct thing{
    long long x, opn, y;

    bool operator< (const thing &obj)const{
        return x < obj.x;
    }
};

int pos=BUF_SIZE;
char buf[BUF_SIZE];
FILE *fin;

inline char nextch(){
    if(pos==BUF_SIZE) fread(buf, BUF_SIZE, 1, fin), pos=0;
    return buf[pos++];
}

inline int read(){
    int x=0;
    char ch=nextch();
    while(!isdigit(ch)) ch=nextch();
    while(isdigit(ch)){
        x=10*x+ch-'0';
        ch=nextch();
    }
    return x;
}

long long n, t, sol[100005];
vector< pair<long long, long long> > v;
vector<thing> q;
pentru_arbore arb[400005];

pentru_arbore make_pentru_arbore(long long time, long long pos)
{
    pentru_arbore aux;
    aux.time = time;
    aux.pos = pos;
    return aux;
}

thing make_thing(long long x, long long opn, long long y)
{
    thing aux;
    aux.x = x;
    aux.y = y;
    aux.opn = opn;
    return aux;
}

pentru_arbore max (pentru_arbore a, pentru_arbore b)
{
    return a < b ? b : a;
}

void update(long long nod, long long st, long long dr, long long poz, long long val)
{
    if(st == dr){
        arb[nod] = make_pentru_arbore(val, poz);
        return;
    }
    long long m = (st+dr)/2;
    if(m >= poz)
        update(2*nod, st, m, poz, val);
    else update(2*nod+1, m+1, dr, poz, val);
    arb[nod] = max(arb[nod*2], arb[nod*2+1]);
}

pentru_arbore ask(long long nod, long long st, long long dr, long long f, long long l)
{
    if(st >= f && dr <= l)
        return arb[nod];
    long long m = (st+dr)/2;
    pentru_arbore sl;
    if(m >= f)
        sl = ask(2*nod, st, m, f, l);
    if(m < l)
        sl = max(sl, ask(2*nod+1, m+1, dr, f, l));
    return sl;
}

int main()
{
    FILE *fout;
    fin=fopen("minuni.in", "r");
    fout=fopen("minuni.out", "w");
    n = read();
    t = read();
    v.push_back(make_pair(0, n+1)); //indexing from 1, deal with it
    for (long long i = 1; i <= t; ++i){
        long long x, y;
        x = read();
        y = read();
        q.push_back(make_thing(x, 0, i));
        q.push_back(make_thing(y, 1, i));
        v.push_back(make_pair(x, y));
    }
    sort(q.begin(), q.end());
    long long d = 1;
    for (vector<thing>::iterator it = q.begin(); it != q.end(); ++it){
        if(it->opn == 0){
            pentru_arbore pa = ask(1, 1, t, 1, it->y);
            long long bst = v[pa.pos].second, bstl = v[pa.pos].first, x = it->x, y = v[it->y].second;
            if(pa.pos != 0){
                sol[it->y] = (x-bstl)*(n-y+1)+(bst-y)*(x)-(x-bstl)*(bst-y);
            }else{
                sol[it->y] = x*(n-y+1);
            }
            update(1, 1, t, it->y, d);
        }else update(1, 1, t, it->y, -1);
        ++d;
    }
    for (long long i = 1; i <= t; ++i)
        fprintf(fout, "%lld\n", sol[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}

