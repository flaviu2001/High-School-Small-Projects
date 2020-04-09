#include <bits/stdc++.h>

using namespace std;

int n, v[50005], r[5005], test, d[5005], mn = 1000000000;
vector<int> e;

void dijkstra()
{
    priority_queue< pair<int, int> > q;
    q.push({0, 0});
    while(!q.empty()){
        int D = -q.top().first;
        int k = q.top().second;
        q.pop();
        for (auto x : e)
            if((d[(k+x)%mn] == 0 || d[(k+x)%mn] > D+x)){
                d[(k+x)%mn] = D+x;
                q.push({-(D+x), (k+x)%mn});
            }
    }
}

int main()
{
    ifstream fin ("banuti.in");
    ofstream fout ("banuti.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        mn = min(mn, v[i]);
    }
    for (int i = 0; i <= mn; ++i)
        r[i] = -1;
    for (int i = 1; i <= n; ++i)
        if(r[v[i]%mn] == -1)
            r[v[i]%mn] = v[i];
        else r[v[i]%mn] = min(r[v[i]%mn], v[i]);
    for (int i = 1; i < mn; ++i)
        if(r[i] != -1)
            e.push_back(r[i]);
    sort(e.begin(), e.end());
    dijkstra();
    int mx = 0, mn2 = 1;
    for (int i = 1; i < mn; ++i)
        mx = max(mx, d[i]),
        mn2 = min(mn2, d[i]);

    if(mn2 == 0)
        fout << "-1\n";
    else
        fout << mx-mn << "\n";
    return 0;
}

