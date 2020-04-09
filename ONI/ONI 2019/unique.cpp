#include <bits/stdc++.h>

using namespace std; 
	
//parse for 100

struct qr{
    int l, r, val;	
};
	
const int nmax = 100005;
int test, n, v[nmax], r[nmax], l[nmax], aib[nmax], b[nmax], last[nmax], w[nmax];

void update(int pos)	
{
    while(pos <= n){
        ++aib[pos];
        pos += (pos & (-pos));
    }	
}

int query(int pos)	
{
    int sum = 0;
    while(pos){
        sum += aib[pos];
        pos -= (pos & (-pos));
    }
    return sum;
}
	
int main()	
{
    ifstream fin ("unique.in");
    ofstream fout ("unique.out");
    fin >> test;
    while(test--){
        fin >> n;
        for (int i = 1; i <= n; ++i)
            fin >> v[i];
        stack<int> s, s2;
        r[n] = n+1;
        s.push(n);
        for (int i = n-1; i >= 1; --i){
            while(!s.empty() && v[s.top()] <= v[i])
                s.pop();
            r[i] = (s.empty() ? n+1 : s.top());
            s.push(i);
        }
        l[1] = 0;
        s2.push(1);
        for (int i = 2; i <= n; ++i){
            while(!s2.empty() && v[s2.top()] <= v[i])
                s2.pop();
            l[i] = (s2.empty() ? 0 : s2.top());
            s2.push(i);
        }
        vector<qr> q[n+1];
        for (int i = 1; i <= n; ++i)
            q[l[i]+1].push_back({l[i]+1, r[i]-1, v[i]});
        memset(aib, 0, sizeof(aib));
        memset(last, 0, sizeof(last));
        memset(w, 0, sizeof(w));
        for (int i = 1; i <= n; ++i){
            b[i] = last[v[i]];
            w[b[i]] = i;
            if(b[i] == 0)
                update(i);
            last[v[i]] = i;
        }
        int sol = 0;
        for (int t = 1; t <= n; ++t){
            if(t != 1 && w[t-1] != 0)
                update(w[t-1]);
            for(auto Q : q[t]){
                int ans = query(Q.r)-(Q.l-1);
                if(ans == Q.val)
                    sol = max(sol, Q.r-Q.l+1);
            }
        }
        fout << sol << "\n";
    }
    return 0;	
}