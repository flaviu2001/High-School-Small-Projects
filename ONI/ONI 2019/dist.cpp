#include <bits/stdc++.h>

using namespace std;

struct ev{
    int x, y;
    bool operator<(const ev &obj)const{
        if(x != obj.x)
            return x < obj.x;
        return y < obj.y;
    }
} v[100005];

struct ev2{
    int x, mny, mxy;
};

int n;
vector<ev2> r, rup, rdown;

ev2 mk2(int x, int mny, int mxy)
{
    ev2 aux;
    aux.x = x;
    aux.mny = mny;
    aux.mxy = mxy;
    return aux;
}

bool cb(int k)
{
    if(r.back().x-r[0].x < k)
        return false;
    int it1 = 0, it2;
    for (int i = 1; 1; ++i)
        if(r[i].x-r[0].x >= k){
            it2 = i;
            break;
        }
    while(r.back().x-r[it1].x >= k){
        while(r[it2].x-r[it1].x < k)
            ++it2;
        if(abs(rup[it1].mxy-rdown[it2].mny) >= k)
            return true;
        if(abs(rdown[it2].mxy-rup[it1].mny) >= k)
            return true;
        ++it1;
    }
    return false;
}

int main()
{
    ifstream fin ("dist2.in");
    ofstream fout ("dist2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i].x >> v[i].y;
    }
    sort(v+1, v+n+1);
    r.push_back(mk2(v[1].x, v[1].y, v[1].y));
    for (int i = 2; i <= n; ++i){
        int x = v[i].x, y = v[i].y;
        if(r.back().x != x)
            r.push_back(mk2(x, y, y));
        else{
            r.back().mny = min(r.back().mny, y);
            r.back().mxy = max(r.back().mxy, y);
        }
    }
    rup.push_back(r[0]);
    rdown.push_back(r[0]);
    for(int i = 1; i < r.size(); ++i){
        rup.push_back(r[i]);
        rdown.push_back(r[i]);
        rup[i].mny = min(rup[i].mny, rup[i-1].mny);
        rup[i].mxy = max(rup[i].mxy, rup[i-1].mxy);
    }
    for (int i = r.size()-2; i >= 0; --i){
        rdown[i].mny = min(rdown[i].mny, rdown[i+1].mny);
        rdown[i].mxy = max(rdown[i].mxy, rdown[i+1].mxy);
    }
    int lo = 0, hi = 2000000, m, ans;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2){
        if(cb(m)){
            ans = m;
            lo = m+1;
        }else hi = m-1;
    }
    fout << ans << "\n";
    return 0;
}

