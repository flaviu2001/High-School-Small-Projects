#include <bits/stdc++.h>

using namespace std;

struct balls{ //100% arbitrary name i swaer
    int x, y, mn, mx;
};

balls v[1000006];
int p[1000006], n;
vector<int> sol;

balls make_balls(int x, int y, int mn, int mx)
{
    balls aux;
    aux.x = x;
    aux.y = y;
    aux.mn = mn;
    aux.mx = mx;
    return aux;
}

bool can_combine(balls b1, balls b2)
{
    if(b1.mn == b2.mx+1)
        return true;
    if(b1.mx == b2.mn-1)
        return true;
    return false;
}

balls combine(balls b1, balls b2)
{
    balls ret;
    ret.x = b1.x;
    ret.y = b2.y;
    ret.mn = min(b1.mn, b2.mn);
    ret.mx = max(b1.mx, b2.mx);
    return ret;
}

int main()
{
    ifstream fin ("permsplit.in");
    ofstream fout ("permsplit.out");
    fin >> n;
    v[0] = make_balls(0, 0, 2000000000, 2000000000);
    v[n+1] = make_balls(n+1, n+1, 2000000000, 2000000000);
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        v[i] = make_balls(i, i, x, x);
    }
    int idx = 1;
    while(idx < n){
        bool ok = true;
        while(ok){
            ok = false;
            if(can_combine(v[v[idx].x-1], v[idx])){
                ok = true;
                sol.push_back(v[idx].x-1);
                balls comb = combine(v[v[idx].x-1], v[idx]);
                v[comb.y] = comb;
                v[comb.x] = comb;
                continue;
            }
            if(can_combine(v[idx], v[idx+1])){
                ok = true;
                sol.push_back(idx);
                balls comb = combine(v[idx], v[idx+1]);
                v[comb.x] = comb;
                v[comb.y] = comb;
                ++idx;
            }
        }
        ++idx;
    }
    if(v[n].y == n && v[n].x == 1)
        for (int i = sol.size()-1; i >= 0; --i)
            fout << sol[i] << " ";
    else fout << "-1";
    fin.close();
    fout.close();
    return 0;
}

