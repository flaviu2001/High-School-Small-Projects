#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//parser for 100

const ll nmax = 1e6+5;
ll n, B, v[nmax], pr[nmax], pr2[nmax], nxt[nmax];

int main()
{
    InParser fin ("calancea.in");
    ofstream fout ("calancea.out");
    fin >> n >> B;
    for (ll i = 1; i <= n; ++i)
        fin >> v[i];
    stack<ll> s;
    for (ll i = n; i >= 1; --i){
        pr2[i] = pr2[i+1]+v[i];
        while(!s.empty() && v[i] > v[s.top()])
            s.pop();
        if(s.empty())
            nxt[i] = n+1;
        else nxt[i] = s.top();
        s.push(i);
    }
    pr2[n] = v[n];
    pr[n] = v[n];
    for (int i = n-1; i >= 1; --i){
        pr[i] = pr[i+1]+v[i];
        pr2[i] = pr2[nxt[i]] + v[i]*(nxt[i]-i);
    }
    ll lft = n, ans = 0;
    stack<ll> r;
    deque<ll> q;
    while(lft >= 1 && pr2[lft]-pr[lft] <= B){
        while(!q.empty() && v[q.back()] <= v[lft])
            q.pop_back();
        q.push_back(lft);
        --lft;
    }
    ans += n-lft;
    for (int i = n-1; i >= 1; --i){
        if(q.front() > i)
            q.pop_front();
        while(!r.empty() &&  v[i+1] >= v[r.top()])
            r.pop();
        r.push(i+1);
        while(!r.empty() && v[q.front()] >= v[r.top()])
            r.pop();
        while(lft >= 1){
            ll nw;
            while(!r.empty() && max(v[q.front()], v[lft]) >= v[r.top()])
                r.pop();
            if(r.empty())
                nw = pr2[lft]-(n-i)*max(v[q.front()], v[lft])-(pr[lft]-pr[i+1]);
            else
                nw = pr2[lft]-pr2[r.top()]-(r.top()-i-1)*max(v[q.front()], v[lft])-(pr[lft]-pr[i+1]);
            if(nw <= B){
                while(!q.empty() && v[q.back()] <= v[lft])
                    q.pop_back();
                q.push_back(lft);
                while(!r.empty() && v[q.front()] >= v[r.top()])
                    r.pop();
                --lft;
            }else break;
        }
        ans += i-lft;
    }
    fout << ans << "\n";
    return 0;
}

