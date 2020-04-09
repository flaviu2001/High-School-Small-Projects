#include <bits/stdc++.h>

using namespace std;

int test, n, p = 1, mats; //matrices
int pd[20][300005], tt[300005], g[300005], level[300005], mars[300005], lg2[300005];
queue<int> q;

int stramos(int x, int up)
{
    --up;
    if(up == 0)
        return x;
    while(up){
        int lg = lg2[up];
        x = pd[lg][x];
        up -= (1<<lg);
    }
    return x;
}

int main()
{
    ifstream fin ("inception.in");
    ofstream fout ("inception.out");
    fin >> test >> test >> mats;
    level[1] = 1;
    lg2[1] = 0;
    tt[1] = 0;
    for (int i = 2; i < 300005; ++i)
        lg2[i] = lg2[i/2]+1;
    while(test--){
        int test;
        fin >> test;
        if(test == 1){
            int x, burn;
            fin >> x >> burn >> burn;
            tt[++p] = x;
            ++g[x];
            x = p;
            level[x] = level[tt[x]]+1;
            pd[0][x] = tt[x];
            for (int i = 1; (1<<i) < level[x]; ++i)
                pd[i][x] = pd[i-1][pd[i-1][x]];
        }else{
            int x, up, val;
            fin >> x >> up >> val;
            mars[x] += val;
            mars[tt[stramos(x, up)]] -= val;
        }
    }
    n = p;
    for (int i = 1; i <= n; ++i)
        if(g[i] == 0)
            q.push(i);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        mars[tt[x]] += mars[x];
        --g[tt[x]];
        if(g[tt[x]] == 0)
            q.push(tt[x]);
    }
    while(mats--){
        int x;
        fin >> x;
        fout << mars[x] << " ";
    }
    return 0;
}

