#include <bits/stdc++.h>

using namespace std;

vector<int> v[100005];
vector< pair<int, int> >t;
int test, n, mx = -2000000000;
int c[100005], p[100005];
bool ok[100005];

void dfs(int x)
{
    ok[x] = 1;
    int C, P;
    if(t.size() == 0){
        C = c[x];
        P = p[x];
    }else{
        C = t.back().first+c[x];
        P = t.back().second+p[x];
    }
    t.push_back(make_pair(C, P));
    if(C <= test)
        mx = max(mx, P);
    else{
        int lo = 0, hi = t.size()-1, ans = -1, a = C-test;
        for (int m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
            if(t[m].first >= a){
                hi = m-1;
                ans = m;
            }else
                lo = m+1;
        mx = max(mx, P-t[ans].second);
    }
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[*it])
            dfs(*it);
    t.pop_back();
}

int main()
{
    ifstream fin ("spiridusi.in");
    ofstream fout ("spiridusi.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i)
        fin >> c[i];
    for (int i = 1; i <= n; ++i)
        fin >> p[i];
    for (int i =  1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    fout << mx << "\n";
    fin.close();
    fout.close();
    return 0;
}

