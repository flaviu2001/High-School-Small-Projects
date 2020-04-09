#include <bits/stdc++.h>

using namespace std;

deque< pair<int, int> > s;
int n, m, pr[500005], v[500005], tail = 0, ans = 1, ansmoves = 0;

int main()
{
    ifstream fin ("cuie.in");
    ofstream fout ("cuie.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        pr[i] = pr[i-1]+v[i];
    }
    s.push_back({v[1], 1});
    for (int i = 2; i <= n; ++i){
        while(!s.empty() && s.back().first >= v[i])
            s.pop_back();
        s.push_back({v[i], i});
        while(pr[i]-pr[tail]-s.front().first*(i-tail) > m){
            ++tail;
            if(tail == s.front().second)
                s.pop_front();
        }
        //cout << i-tail << " " << pr[i]-pr[tail]-s.front().first*(i-tail) << "\n";
        if(ans < i-tail){
            ans = i-tail;
            ansmoves = pr[i]-pr[tail]-s.front().first*(i-tail);
        }else if (ans == i-tail && ansmoves > pr[i]-pr[tail]-s.front().first*(i-tail))
            ansmoves = pr[i]-pr[tail]-s.front().first*(i-tail);
    }
    fout << ans << " " << ansmoves << "\n";
    return 0;
}

