#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int n, test, v[nmax], pr[nmax];
pair<int, int> positive[nmax], negative[nmax];

int main()
{
    ifstream fin ("diff.in");
    ofstream fout ("diff.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        if(v[i] == 0)
            v[i] = -1;
        pr[i] = pr[i-1] + v[i];
    }
    int mn = 0, mx = pr[1], I = 1, J = 1, mnj = 0;
    for (int i = 2; i <= n; ++i){
        if(mn > pr[i]){
            mn = pr[i];
            mnj = i;
        }
        if(mx < pr[i]-mn){
            mx = pr[i]-mn;
            I = i;
            J = mnj+1;
        }
    }
    int now = 0;
    for (int i = J; i <= I; ++i){
        now += v[i];
        if(now > 0 && positive[now].second == 0)
            positive[now] = {J, i};
    }
    int mn2 = pr[1], mx2 = 0, mxj = 0; I = 1, J = 1;
    for (int i = 2; i <= n; ++i){
        if(mx2 < pr[i]){
            mx2 = pr[i];
            mxj = i;
        }
        if(mn2 > pr[i]-mx2){
            mn2 = pr[i]-mx2;
            I = i;
            J = mxj+1;
        }
    }
    now = 0;
    for (int i = J; i <= I; ++i){
        now += v[i];
        if(now < 0 && negative[-now].second == 0)
            negative[-now] = {J, i};
    }
    bool iszero = false;
    int poszero;
    for (int i = 2; i <= n; ++i){
        if(v[i-1]+v[i] == 0){
            iszero = true;
            poszero = i;
            break;
        }
    }
    while(test--){
        int x;
        fin >> x;
        if(x < mn2 || x > mx || (!iszero && x == 0))
            fout << "-1\n";
        else{
            if(x == 0)
                fout << poszero-1 << " " << poszero << "\n";
            else if (x < 0)
                fout << negative[-x].first << " " << negative[-x].second << "\n";
            else fout << positive[x].first << " " << positive[x].second << "\n";
        }
    }
    return 0;
}

