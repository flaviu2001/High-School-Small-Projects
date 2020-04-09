#include <bits/stdc++.h>

using namespace std;

int n, m, k, tribe[100005], cnx[100005], p, trb, c[100005], rng[100005], sol[100005];
bool ok[100005], kk[100005];
vector<int> v[100005];
unordered_map<int, int> mp[100005];
pair<int, int> edg[150005];

void df(int x)
{
    cnx[x] = p;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(tribe[*it] == trb && cnx[*it] == 0)
            df(*it);
}

int find(int x)
{
    int R;
    for (R = x; c[R] != R; R = c[R]);
    while(c[x] != x){
        int y = c[x];
        c[x] = R;
        x = y;
    }
    return R;
}

void unite(int x, int y)
{
    if(x == y)
        return;
    if(rng[x] > rng[y])
        c[y] = x;
    else c[x] = y;
    if(rng[x] == rng[y])
        ++rng[y];
}

void df2(int x)
{
    if(tribe[x] == trb)
        kk[x] = 1;
    ok[x] = 1;
    bool ko = (tribe[x] == trb);
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(tribe[*it] == trb)
            ko = true;
    if(ko)
        for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(!ok[*it])
                df2(*it);
}

void ineficient()
{
    for (int i = 1; i <= n; ++i)
        if(!kk[i]){
            for (int j = 1; j <= n; ++j)
                ok[j] = 0;
            ++sol[tribe[i]];
            trb = tribe[i];
            df2(i);
        }
}

int main()
{
    ifstream fin ("tribes.in");
    ofstream fout ("tribes.out");
    fin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        fin >> tribe[i];
    for (int i = 1; i <= m; ++i){
        int x, y;
        fin >> x >> y;
        edg[i] = make_pair(x, y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(n <= 1000){
        ineficient();
        goto here;
    }
    for (int i = 1; i <= n; ++i)
        if(cnx[i] == 0){
            trb = tribe[i];
            ++p;
            df(i);
        }
    for (int i = 1; i <= n; ++i){
        c[i] = i;
        rng[i] = 1;
    }
    for (int i = 1; i <= n; ++i){
        for(vector<int>::iterator it = v[i].begin(); it != v[i].end(); ++it)
            if(tribe[*it] != tribe[i] && mp[i][tribe[*it]] == 0)
                mp[i][tribe[*it]] = cnx[*it];
            else if (tribe[*it] != tribe[i])
                unite(find(mp[i][tribe[*it]]), find(cnx[*it]));
    }
    for (int t = m; t >= 1; --t){
        int x = edg[t].first, y = edg[t].second;
        if(v[x].size() > v[y].size())
            swap(x, y);
        for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(tribe[*it] != tribe[x] && tribe[*it] != tribe[y] && mp[y].find(tribe[*it]) != mp[y].end())
                unite(find(mp[x][tribe[*it]]), find(mp[y][tribe[*it]]));
    }
    for (int i = 1; i <= n; ++i){
        if(!ok[find(cnx[i])])
            ++sol[tribe[i]];
        ok[find(cnx[i])] = 1;
    }
    here:
    for (int i = 1; i <= k; ++i)
        fout << sol[i] << "\n";
    fin.close();
    fout.close();
    return 0;
}

