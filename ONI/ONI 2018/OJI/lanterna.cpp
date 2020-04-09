#include <bits/stdc++.h>

using namespace std;

struct edge{
    int x, d, w;
};

int n, t, s[52][5000], s2[52][1002], anses[5000];
bool bat[55];
vector<edge>v[55];

edge make_edge(int x, int d, int w)
{
    edge aux;
    aux.x = x;
    aux.d = d;
    aux.w = w;
    return aux;
}

int bell(int test)
{
    memset(s, -1, sizeof(s));
    memset(s2, -1, sizeof(s2));
    queue<edge> q;
    q.push(make_edge(1, 0, test));
    while(!q.empty()){
        edge k = q.front();
        if(bat[k.x])
            k.w = test;
        q.pop();
        for (vector<edge>::iterator it = v[k.x].begin(); it != v[k.x].end(); ++it)
            if (k.w-it->w >= 0 && s[it->x][k.d+it->d] < k.w-it->w && (s2[it->x][k.w-it->w] == -1 || s2[it->x][k.w-it->w] > k.d+it->d)){
                int W = k.w-it->w;
                s[it->x][k.d+it->d] = W;
                s2[it->x][k.w-it->w] = k.d+it->d;
                q.push(make_edge(it->x, k.d+it->d, W));
            }
    }
    for (int i = 0; i <= 5000; ++i)
        if(s[n][i] >= 0){
            anses[i] = min(anses[i], test);
            return i;
        }
    return -1;
}

int main()
{
    ifstream fin ("lanterna.in");
    ofstream fout ("lanterna.out");
    fin >> n >> t;
    for (int i = 0; i < 5000; ++i)
        anses[i] = 1000;
    for (int i = 1; i <= n; ++i)
        fin >> bat[i];
    int m;
    fin >> m;
    while(m--){
        int a, b, d, w;
        fin >> a >> b >> d >> w;
        v[a].push_back(make_edge(b, d, w));
        v[b].push_back(make_edge(a, d, w));
    }
    int lo = 1, hi = t-1, ans = bell(t);
    for (m = (lo+hi)>>1; lo <= hi; m = (lo+hi)>>1){
        int x = bell(m);
        if(x != ans)
            lo = m+1;
        else
            hi = m-1;
    }
    fout << ans << " " << anses[ans] << "\n";
    fin.close();
    fout.close();
    return 0;
}

