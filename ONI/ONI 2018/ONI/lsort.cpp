#include <bits/stdc++.h>

using namespace std;

int n, v[1005], over[1005][1005], where[1005];
pair<int, int> pd[1005][1005];
vector<int> sol;

void rec(int a, int b)
{
    if(pd[a][b].first != 0)
        return;
    if(a == b){
        pd[a][b] = {where[a], a};
        return;
    }
    rec(a+1, b);
    rec(a, b-1);
    pd[a][b] = pd[a+1][b];
    pd[a][b].second = a;
    pd[a][b].first += (b-a+1)*(where[a]-(over[where[a]][a+1]-over[where[a]][b+1]));
    int cost2 = (b-a+1)*(where[b]-(over[where[b]][a]-over[where[b]][b]));
    if(pd[a][b-1].first+cost2 < pd[a][b].first){
        pd[a][b].first = pd[a][b-1].first+cost2;
        pd[a][b].second = b;
    }
}

int main()
{
    ifstream fin ("lsort.in");
    ofstream fout ("lsort.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        where[v[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = n; j >= 1; --j)
            over[i][j] = over[i][j+1] + (where[j] <= i);
    rec(1, n);
    fout << pd[1][n].first << "\n";
    int x = 1, y = n;
    for (int i = 1; i <= n; ++i){
        sol.push_back(pd[x][y].second);
        int X = pd[x][y].second;
        if(X == y)
            y = X-1;
        else x = x+1;
    }
    for (int i = sol.size()-1; i >= 0; --i)
        fout << sol[i] << " ";
    return 0;
}

