#include <bits/stdc++.h>

using namespace std;

struct event{
    int t;
    pair<int, int> p;

    bool operator<(const event &obj) const{
        return p.first < obj.p.first;
    }
};

int first[110000], last[110000], n, m, k, arb[4*110000], arsi[4*110000];
vector<event> e;
vector<int> v[110000];

event make_event(int t, pair<int, int> p)
{
    event aux;
    aux.t = t;
    aux.p = p;
    return aux;
}

void df(int x)
{
    first[x] = ++k;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        df(*it);
    last[x] = k;
}

void build(int nod, int st, int dr)
{
    if(st == dr){
        arb[nod] = 1;
        return;
    }
    int M = (st+dr)/2;
    build(nod*2, st, M);
    build(nod*2+1, M+1, dr);
    arb[nod] = arb[nod*2]+arb[nod*2+1];
}

void update(int nod, int st, int dr, int l, int r, int val)
{
    if(st >= l && dr <= r){
        arsi[nod] -= val;
        if(arsi[nod] == 0)
            arb[nod] = (st == dr ? 1 : arb[nod*2]+arb[nod*2+1]);
        else arb[nod] = 0;
        return;
    }
    int M = (st+dr)/2;
    if(M >= l)
        update(nod*2, st, M, l, r, val);
    if(M < r)
        update(nod*2+1, M+1, dr, l, r, val);
    if(arsi[nod] == 0)
        arb[nod] = (st == dr ? 1 : arb[nod*2]+arb[nod*2+1]);
    else arb[nod] = 0;
}

int main()
{
    ifstream fin("curent.in");
    ofstream fout ("curent.out");
    fin >> n;
    for (int i = 2; i <= n; ++i){
        int x;
        fin >> x;
        v[x].push_back(i);
    }
    fin >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, t;
        fin >> x >> y >> t;
        e.push_back(make_event(t, make_pair(x, y)));
    }
    fin >> m;
    for (int i = 1; i <= m; ++i){
        int x;
        fin >> x;
        e.push_back(make_event(2, make_pair(x, 0)));
    }

    df(1);
    build(1, 1, k);

    sort(e.begin(), e.end());
    for(vector<event>::iterator it = e.begin(); it != e.end(); ++it)
        switch(it->t){
            case 0:
                update(1, 1, k, first[it->p.second], last[it->p.second], 1);
                break;
            case 1:
                update(1, 1, k, first[it->p.second], last[it->p.second], -1);
                break;
            case 2:
                fout << arb[1] << "\n";
                break;
        }
    fin.close();
    fout.close();
    return 0;
}

