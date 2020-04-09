#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int nmax = 100005;
int n, v[nmax], stm[nmax], stM[nmax], drm[nmax], drM[nmax], p[nmax*3], valMax;

int main()
{
    ifstream fin ("fotbal3.in");
    ofstream fout ("fotbal3.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        valMax = max(valMax, v[i]);
        p[v[i]] = i;
    }
    stack<int> s;
    s.push(1);
    for (int i = 2; i <= n; ++i){
        while(!s.empty() && v[s.top()] > v[i])
            s.pop();
        stm[i] = (s.empty() ? 0 : s.top());
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    s.push(1);
    for (int i = 2; i <= n; ++i){
        while(!s.empty() && v[s.top()] < v[i])
            s.pop();
        stM[i] = (s.empty() ? 0 : s.top());
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    s.push(n);
    drm[n] = n+1;
    for (int i = n-1; i >= 1; --i){
        while(!s.empty() && v[s.top()] > v[i])
            s.pop();
        drm[i] = (s.empty() ? n+1 : s.top());
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    s.push(n);
    drM[n] = n+1;
    for (int i = n-1; i >= 1; --i){
        while(!s.empty() && v[s.top()] < v[i])
            s.pop();
        drM[i] = (s.empty() ? n+1 : s.top());
        s.push(i);
    }
    ll ans = n;
    for (int i = 1; i <= n; ++i){
        int l = stm[i]+1, r = drm[i]-1;
        for (int x = v[i]*2; x <= valMax; x += v[i])
            if(p[x] != 0){
                if(p[x] > r || p[x] < l)
                    continue;
                int L = stM[p[x]]+1, R = drM[p[x]]-1;
                if(!(L <= i && i <= R))
                    continue;
                L = max(l, L);
                R = min(r, R);
                int st = min(i, p[x]), dr = max(i, p[x]);
                ans += 1ll*(st-L+1)*(R-dr+1);
            }
    }
    fout << ans << "\n";
    return 0;
}
