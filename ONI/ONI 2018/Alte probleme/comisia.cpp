#include <bits/stdc++.h>

using namespace std;

struct thing{
    int x, d;
};

int64_t sol = 2000000000000000000, pc[200005];
int n, v[200005], c[200005], lg2[200005];
thing pd[20][200005];

thing max(thing a, thing b)
{
    if(a.d > b.d)
        return a;
    return b;
}

thing make_thing(int x, int d)
{
    thing aux;
    aux.x = x;
    aux.d = d;
    return aux;
}

thing query(int x, int y)
{
    if (x == y)
        return make_thing(x, v[x]);
    int sz = lg2[y-x];
    thing aux = max(pd[sz][x], pd[sz][y-(1<<sz)]);
    return aux;
}

void solve_this_cunt(int l, int r)
{
    if(l > r || l < 1 || r > n)
        return;
    thing thng = query(l, r);
    int mx = thng.d, p = thng.x;
    if(l == r && v[l] == 1){
        sol = min(sol, int64_t(c[l]));
        return;
    }else if (l == r) return;
    if(r-l+1 < mx){
        solve_this_cunt(l, p-1);
        solve_this_cunt(p+1, r);
        return;
    }
    int st = p-mx+1, dr = p;
    if(st < l){
        dr += l-st;
        st = l;
    }
    sol = min(sol, int64_t(pc[dr]-pc[st-1]));
    while(st+1 <= p && dr+1 <= r){
        ++st;++dr;
        sol = min(sol, int64_t(pc[dr]-pc[st-1]));
    }
    solve_this_cunt(l, p-1);
    solve_this_cunt(p+1, r);
}

int main()
{
    ifstream fin ("comisia.in");
    ofstream fout ("comisia.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= n; ++i){
        fin >> c[i];
        pc[i] = pc[i-1] + c[i];
    }
    lg2[2] = 1;
    for (int i = 3; i < 200005; ++i)
        lg2[i] = lg2[i/2]+1;
    for (int i = 1; i < n; ++i){
        pd[0][i] = make_thing(i, v[i]);
        if(v[i] < v[i+1])
            pd[0][i] = make_thing(i+1, v[i+1]);
    }
    for (int t = 1; t <= lg2[n-1]; ++t)
        for (int i = 1; i <= n-(1<<t); ++i)
            pd[t][i] = max(pd[t-1][i], pd[t-1][i+(1<<(t-1))]);
    solve_this_cunt(1, n);
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

