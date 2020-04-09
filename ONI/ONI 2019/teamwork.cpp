#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll nmax = 1000006, inf = 1ll<<60;
ll n, sol = -inf, v[nmax], pr[nmax], mxl[nmax], mxr[nmax], mnpl[nmax], mxpr[nmax], lft[nmax], rgt[nmax];

int main()
{
    ifstream fin ("teamwork.in");
    ofstream fout ("teamwork.out");
    fin >> n;
    mxl[0] = mxr[n+1] = mxpr[n+1] = -inf;
    mnpl[0] = inf;
    for (ll i = 1; i <= n; ++i){
        fin >> v[i];
        pr[i] = pr[i-1]+v[i];
        if(mnpl[i] != mnpl[i-1])
            mxl[i] = v[i];
        else
            mxl[i] = max(mxl[i-1], v[i]);
        mnpl[i] = min(mnpl[i-1], pr[i]);
    }
    for (ll i = n; i >= 1; --i){
        mxpr[i] = max(mxpr[i+1], pr[i]);
        if(mxpr[i] != mxpr[i+1])
            mxr[i] = v[i];
        else
            mxr[i] = max(mxr[i+1], v[i]);
    }
    for (ll i = 1; i <= n; ++i){
        ll mx = v[i], ans = v[i];
        if(i != 1){
            ll addl = pr[i-1];
            addl -= mnpl[i-1];
            if(addl >= 0){
                mx = max(mx, mxl[i-1]);
                ans += addl;
            }
        }
        if(i != n){
            ll addr = mxpr[i+1]-pr[i];
            if(addr >= 0){
                mx = max(mx, mxr[i+1]);
                ans += addr;
            }
        }
        sol = max(sol, mx*ans);
    }
    lft[1] = 0;
    stack<ll> s;
    s.push(1);
    for (ll i = 2; i <= n; ++i){
        while(!s.empty() && v[s.top()] <= v[i])
            s.pop();
        if(s.empty())
            lft[i] = 0;
        else lft[i] = s.top();
        s.push(i);
    }
    rgt[n] = n+1;
    while(!s.empty())
        s.pop();
    s.push(n);
    for (ll i = n-1; i >= 1; --i){
        while(!s.empty() && v[s.top()] <= v[i])
            s.pop();
        if(s.empty())
            rgt[i] = n+1;
        else rgt[i] = s.top();
        s.push(i);
    }
    for (ll i = 1; i <= n; ++i){
        ll mx = v[i], ans = pr[rgt[i]-1]-pr[lft[i]];
        sol = max(sol, mx*ans);
    }
    fout << sol << "\n";
    return 0;
}

