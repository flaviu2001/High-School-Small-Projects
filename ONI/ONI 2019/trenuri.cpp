#include <bits/stdc++.h>

using namespace std;

struct train0{
    int lim, i, c;
    bool operator<(const train0 &obj)const{
        return lim > obj.lim;
    }
};

struct train{
    int lim, y, i;
};

struct event{
    int x, y, i;
    bool operator<(const event &aux)const{
        return y < aux.y;
    }
};

struct stuff{
    int y, i;
    bool operator<(const stuff &obj)const{
        return y < obj.y;
    }
};

int n, m, p, ans[100005], go[100005], aint[400005], aintaux[100005], lazy[400005];
train0 aux[100005];
train t1[100005];
event r[100005];
multiset<stuff> st;
bool ok[100005], ok2[100005], used[100005];
multiset<int> canuse;

void build(int nod, int st, int dr)
{
    if(st == dr)
        aint[nod] = aintaux[st];
    else{
        int mid = (st+dr)/2;
        build(nod*2, st, mid);
        build(nod*2+1, mid+1, dr);
        aint[nod] = min(aint[nod*2], aint[nod*2+1]);
    }
}

void update(int nod, int st, int dr, int l, int r, int val)
{
    if(lazy[nod]){
        aint[nod] += lazy[nod];
        if(st != dr){
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(st > r || dr < l)
        return;
    if(st >= l && dr <= r){
        aint[nod] += val;
        if(st != dr){
            lazy[nod*2] += val;
            lazy[nod*2+1] += val;
        }
        return;
    }
    int mid = (st+dr)/2;
    update(nod*2, st, mid, l, r, val);
    update(nod*2+1, mid+1, dr, l, r, val);
    aint[nod] = min(aint[nod*2], aint[nod*2+1]);
}

int query()
{
    if(lazy[1]){
        aint[1] += lazy[1];
        lazy[1*2] += lazy[1];
        lazy[1*2+1] += lazy[1];
        lazy[1] = 0;
    }
    return aint[1];
}

int who(int x)
{
    int st = 1, dr = p, m, ans;
    for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
        if(t1[m].lim >= x){
            ans = m;
            dr = m-1;
        }else st = m+1;
    return ans;
}

int main()
{
    ifstream fin ("trenuri3.in");
    ofstream fout ("trenuri3.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fin >> aux[i].lim >> aux[i].c;
        aux[i].i = i;
    }
    sort(aux+1, aux+n+1);
    for (int i = 1; i <= n && p < m; ++i){
        int del = min(aux[i].c, m-p);
        for (int j = 0; j < del; ++j){
            t1[++p] = {aux[i].lim, 0, aux[i].i};
            st.insert({0, 0});
        }
    }
    reverse(t1+1, t1+p+1);
    for (int i = 1; i <= m; ++i){
        fin >> r[i].x >> r[i].y;
        r[i].i = i;
    }
    sort(r+1, r+m+1);
    aintaux[1] = 0;
    for (int i = 2; i <= p; ++i)
        aintaux[i] = p-i+1;
    build(1, 1, p);
    int sol = 0;
    for (int i = 1; i <= m; ++i){
        if(r[i].y > t1[p].lim)
            break;
        if(r[i].x < st.begin()->y)
            continue;
        multiset<stuff>::iterator it = st.upper_bound({r[i].x, 0});
        --it;
        update(1, 1, p, 1, who(it->y), 1);
        update(1, 1, p, 1, who(r[i].y), -1);
        if(query() < 0){
            update(1, 1, p, 1, who(it->y), -1);
            update(1, 1, p, 1, who(r[i].y), 1);
            continue;
        }
        ++sol;
        used[i] = 1;
        go[i] = it->i;
        stuff now2 = *it;
        st.erase(it);
        now2.i = i;
        now2.y = r[i].y;
        st.insert(now2);
    }
    for (int i = 1; i <= p; ++i)
        canuse.insert(i);
    for (int i = m; i >= 1; --i)
        if(!ok2[i] && used[i]){
            int I = who(r[i].y);
            I = *canuse.lower_bound(I);
            canuse.erase(canuse.find(I));
            I = t1[I].i;
            int y = i;
            while(y){
                ok2[y] = 1;
                ans[r[y].i] = I;
                y = go[y];
            }
        }
    fout << sol << "\n";
    for (int i = 1; i <= m; ++i)
        fout << ans[i] << "\n";
    return 0;
}
