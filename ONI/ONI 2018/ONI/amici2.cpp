#include <bits/stdc++.h>

using namespace std;

int test, n, m, lg[21005];
vector<int> v[21005];
int ok[21005];

int bfs(int prim)
{
    memset(ok, 0, sizeof(ok));
    queue<int> q;
    int mx = 0;
    ok[prim] = 1;
    q.push(prim);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (vector<int>::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(!ok[*it]){
                ok[*it] = ok[k] + 1;
                mx = max(mx, ok[*it]);
                q.push(*it);
            }
    }
    return mx-1;
}

int main()
{
    ifstream fin ("amici2.in");
    ofstream fout ("amici2.out");
    for (int i = 2; i <= 21000; ++i)
        lg[i] = lg[i/2]+1;
    fin >> test;
    while(test--){
        fin >> n >> m;
        for (int i = 1; i <= n; ++i)
            v[i].clear();
        while(m--){
            int x, y;
            fin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        fout << lg[bfs(1)]+1 << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

