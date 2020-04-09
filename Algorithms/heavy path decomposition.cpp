#include <bits/stdc++.h>

using namespace std;

int n, test, p, depth[100005], tt[100005], vl[100005], subtree[100005], carelant[100005], poslant[100005];
bool ok[100005];
vector<int> v[100005], lnt[100005], arb[100005];

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

void update(int nod, int lo, int hi, int val, int pos, int carearb)
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

int queryarb(int nod, int lo, int hi, int l, int r, int carearb)
{
    if(lo >= l && hi <= r)
        return arb[carearb][nod];
    int mx = -1, m = (lo+hi)/2;
    if(m >= l)
        mx = max(mx, queryarb(nod*2, lo, m, l, r, carearb));
    if(m < r)
        mx = max(mx, queryarb(nod*2+1, m+1, hi, l, r, carearb));
    return mx;
}

int hpd(int x, int y)
{
    int mx = -1;
    while(1)
    {
        if(depth[tt[lnt[carelant[x]].back()]] < depth[tt[lnt[carelant[y]].back()]])
            swap(x, y);
        if(carelant[x] == carelant[y]){
            if(x == y)
                return max(mx, vl[x]);
            if(poslant[x] > poslant[y])
                swap(x, y);
            return max(mx, queryarb(1, 0, lnt[carelant[x]].size()-1, poslant[x], poslant[y], carelant[x]));
        }
        mx = max(mx, queryarb(1, 0, lnt[carelant[x]].size()-1, poslant[x], lnt[carelant[x]].size()-1, carelant[x]));
        x = tt[lnt[carelant[x]].back()];
    }
    return 0;
}

int main()
{
    ifstream fin ("heavypath.in");
    ofstream fout ("heavypath.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i)
        fin >> vl[i];
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
        fin >> t >> x >> y;
        if(t == 0){
            vl[x] = y;
            update(1, 0, lnt[carelant[x]].size()-1, y, poslant[x], carelant[x]);
        }
        else
            fout << hpd(x, y) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

