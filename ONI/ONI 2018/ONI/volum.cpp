#include <bits/stdc++.h>

using namespace std;

struct thing{
    int x, y, val;
    bool operator<(const thing &obj)const{
        return val<obj.val;
    }
};

multiset<thing> s;
int v[1005][1005], n, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
long long sol;
bool ok[1005][1005];

thing make_thing(int x, int y, int val)
{
    thing aux;
    aux.x = x;
    aux.y = y;
    aux.val = val;
    return aux;
}

bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m && !ok[x][y];
}

int main()
{
    ifstream fin ("volum.in");
    ofstream fout ("volum.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];

    for (int i = 1; i <= n; ++i){
        ok[i][1] = ok[i][m] = 1;
        s.insert(make_thing(i, 1, v[i][1]));
        s.insert(make_thing(i, m, v[i][m]));
    }
    for (int j = 1; j <= m; ++j){
        ok[1][j] = ok[n][j] = 1;
        s.insert(make_thing(1, j, v[1][j]));
        s.insert(make_thing(n, j, v[n][j]));
    }
    while(!s.empty()){
        thing k = *s.begin();
        s.erase(s.begin());
        sol += k.val-v[k.x][k.y];
        for (int i = 0; i < 4; ++i)
            if(check(k.x+dx[i], k.y+dy[i]))
                if(v[k.x+dx[i]][k.y+dy[i]] <= k.val){
                    ok[k.x+dx[i]][k.y+dy[i]] = 1;
                    s.insert(make_thing(k.x+dx[i], k.y+dy[i], k.val));
                }else{
                    ok[k.x+dx[i]][k.y+dy[i]] = 1;
                    s.insert(make_thing(k.x+dx[i], k.y+dy[i], v[k.x+dx[i]][k.y+dy[i]]));
                }
    }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

