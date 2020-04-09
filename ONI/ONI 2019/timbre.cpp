#include <bits/stdc++.h>

using namespace std;

struct node{
    int pos, val;
    node(){
        pos = -1;
        val = 2000000000;
    }
    bool operator<(const node &obj)const{
        if(val!=obj.val)
            return val < obj.val;
        return pos < obj.pos;
    }
}aint[800005];

int n, m, d;
multiset<int> v[100005];

void update(int nod, int st, int dr, int pos, int val, bool type)
{
    if(st == dr){
        aint[nod].pos = pos;
        if(type == 0)
            aint[nod].val = min(aint[nod].val, val);
        else{
            v[pos].erase(v[pos].begin());
            if(v[pos].size() == 0)
                aint[nod].val = val;
            else aint[nod].val = *v[pos].begin();
        }
    }else{
        int mid = (st+dr)/2;
        if(mid >= pos)
            update(nod*2, st, mid, pos, val, type);
        else update(nod*2+1, mid+1, dr, pos, val, type);
        aint[nod] = min(aint[nod*2], aint[nod*2+1]);
    }
}

node query(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return aint[nod];
    int mid = (st+dr)/2;
    node ans;
    if(mid >= l)
        ans = query(nod*2, st, mid, l, r);
    if(mid+1 <= r)
        ans = min(ans, query(nod*2+1, mid+1, dr, l, r));
    return ans;
}

int main()
{
    ifstream fin ("timbre.in");
    ofstream fout ("timbre.out");
    fin >> n >> m >> d;
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        v[x].insert(y);
        update(1, 1, 200000, x, y, 0);
    }
    int rb = n, ans = 0;
    while(rb >= 1){
        node now = query(1, 1, 200000, rb, 200000);
        ans += now.val;
        update(1, 1, 200000, now.pos, 2000000000, 1);
        rb -= d;
    }
    fout << ans << "\n";
    return 0;
}

