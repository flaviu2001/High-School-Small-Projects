#include <bits/stdc++.h>

using namespace std;

int test, n, ss[15005], pp[15005];

int solve(int t)
{
    int sol = 0, s[15005], p[15005];
    for (int i = 0; i <= n; ++i){
        s[i] = ss[i];
        p[i] = pp[i];
    }
    sol += t;
    s[0] -= t;
    p[0] -= t;
    if(p[0] > 0){
        int r = p[0];
        if(s[n-1] < r)
            r = s[n-1];
        p[0] -= r;
        s[n-1] -= r;
        sol += r;
    }
    for (int i = 1; i < n; ++i){
        int r1 = p[i];
        if(s[i-1] < r1)
            r1 = s[i-1];
        sol += r1;
        p[i] -= r1;
        s[i-1] -= r1;
        if(p[i] > 0){
            int r2 = p[i];
            if(s[i] < r2)
                r2 = s[i];
            sol += r2;
            p[i] -= r2;
            s[i] -= r2;
        }
    }
    return sol;
}

int main()
{
    ifstream fin ("bile5.in");
    ofstream fout ("bile5.out");
    fin >> test;
    while(test--){
        fin >> n;
        for (int i = 0; i < n; ++i)
            fin >> ss[i] >> pp[i];
        if(n <= 10){
            for (int t = 0; t <= min(ss[0], pp[0]); ++t)
                fout << solve(t) << "\n";
        }else{
            int st = 0, dr = min(ss[0], pp[0])-1, m, ans1, ans2, mx = 0;
            for (m = (st+dr)/2; st <= dr; m = (st+dr)/2){
                int v1 = solve(m);
                int v2 = solve(m+1);
                mx = max(mx, max(v1, v2));
                if(v2 > v1){
                    ans1 = m+1;
                    st = m+1;
                }else{
                    ans1 = m;
                    dr = m-1;
                }
            }
            st = ans1, dr = min(ss[0], pp[0]);
            for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
                if(solve(m) < mx)
                    dr = m-1;
                else{
                    ans2 = m;
                    st = m+1;
                }
            vector<int> ans;
            for (int i = 1; ans1-i >= 0; ++i)
                ans.push_back(mx-i);
            sort(ans.begin(), ans.end());
            for (int i = ans1; i <= ans2; ++i)
                ans.push_back(mx);
            for (int i = 1; ans2+i <= min(ss[0], pp[0]); ++i)
                ans.push_back(mx-i);
            for (auto x : ans)
                fout << x << "\n";
        }
    }
    return 0;

}
