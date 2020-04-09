#include <bits/stdc++.h>

using namespace std;

struct body{
    int x1, y1, x2, y2; //x2 - radius, y2=-1 if circle, positive if rectangle
    body(){
        x1 = x2 = y1 = y2 = -1;
    }
};

int n,  pd[2005];
body v[2005];
vector<int> g[2005];
bool ok[2005];

bool cuibareala(body a, body b)
{
    if(a.y2 == -1 && b.y2 == -1){
        if(a.x2 < b.x2)
            return false;
        return ((a.x1-b.x1)*(a.x1-b.x1)+(a.y1-b.y1)*(a.y1-b.y1)) <= (b.x2-a.x2)*(b.x2-a.x2);
    }
    if(a.y2 != -1 && b.y2 != -1)
        return a.x1 <= b.x1 && a.x2 >= b.x2 && a.y1 <= b.y1 && a.y2 >= b.y2;
    if(a.y2 == -1 && b.y2 != -1){
        if((a.x1-b.x1)*(a.x1-b.x1)+(a.y1-b.y1)*(a.y1-b.y1) > a.x2*a.x2)
            return false;
        if((a.x1-b.x1)*(a.x1-b.x1)+(a.y1-b.y2)*(a.y1-b.y2) > a.x2*a.x2)
            return false;
        if((a.x1-b.x2)*(a.x1-b.x2)+(a.y1-b.y1)*(a.y1-b.y1) > a.x2*a.x2)
            return false;
        if((a.x1-b.x2)*(a.x1-b.x2)+(a.y1-b.y2)*(a.y1-b.y2) > a.x2*a.x2)
            return false;
        return true;
    }
    if(b.x1-a.x1 < b.x2)
        return false;
    if(a.x2-b.x1 < b.x2)
        return false;
    if(b.y1-a.y1 < b.x2)
        return false;
    if(a.y2-b.y1 < b.x2)
        return false;
    return true;
}

void dfs(int x)
{
    ok[x] = 1;
    pd[x] = 0;
    for (auto y : g[x]){
        if(!ok[y])
            dfs(y);
        pd[x] = max(pd[x], pd[y]);
    }
    ++pd[x];
}

int main()
{
    ifstream fin ("cuiburi.in");
    ofstream fout ("cuiburi.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int tip;
        fin >> tip >> v[i].x1 >> v[i].y1 >> v[i].x2;
        if(!tip)
            fin >> v[i].y2;
        for (int j = 1; j < i; ++j)
            if(cuibareala(v[j], v[i]))
                g[j].push_back(i);
            else if(cuibareala(v[i], v[j]))
                g[i].push_back(j);
    }
    int mx = -1;
    for (int i = 1; i <= n; ++i)
        if(!ok[i]){
            dfs(i);
            mx = max(mx, pd[i]);
        }
    fout << mx << "\n";
    return 0;
}
}
