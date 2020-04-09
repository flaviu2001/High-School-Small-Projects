#include <bits/stdc++.h>

using namespace std;

struct query{
    int t, x, y, c, i;
};

int n, test, ans[500005], aib[600][600];
vector<int> v[500005], r;
query q[500005];

query mkq(int t, int x, int y, int c, int i)
{
    query aux;
    aux.t = t;
    aux.x = x;
    aux.y = y;
    aux.c = c;
    aux.i = i;
    return aux;
}

void update(int x, int y, int val)
{
    for (int i = x; i <= n; i += (i&-i))
        for (int j = y; j <= n; j += (j&-j))
            aib[i][j] += val;
}

int ask(int x, int y)
{
    int sum = 0;
    for (int i = x; i > 0; i -= (i&-i))
        for (int j = y; j > 0; j -= (j&-j))
            sum += aib[i][j];
    return sum;
}

void dfs(int x)
{
    if(q[x].t == 1)
        update(q[x].x, q[x].y, q[x].c);
    if(q[x].t == 2)
        ans[x] = ask(q[x].x, q[x].y);
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        dfs(*it);
    if(q[x].t == 1)
        update(q[x].x, q[x].y, -q[x].c);
}

int main()
{
    ifstream fin ("undo.in");
    ofstream fout ("undo.out");
    fin >> n >> test;
    int t, x=0, y=0, c=0;
    r.push_back(0);
    for (int i = 1; i <= test; ++i){
        fin >> t;
        if(t == 1)
            fin >> x >> y >> c;
        else if (t == 2)
            fin >> x >> y;
        else fin >> x;
        q[i] = mkq(t, x, y, c, i);
        if(t <= 2){
            v[i-1].push_back(i);
            if(t == 1)
                r.push_back(i);
        }else{
            v[r[r.size()-x-1]].push_back(i);
            r.push_back(i);
        }
    }
    dfs(0);
    for (int i = 1; i <= test; ++i)
        if(q[i].t == 2)
            fout << ans[i] << "\n";
    return 0;
}

