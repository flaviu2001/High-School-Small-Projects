#include <bits/stdc++.h>

using namespace std;

int n[2], v[2][10005], test;

int main()
{
    ifstream fin ("arc.in");
    ofstream fout ("arc.out");
    fin >> test >> n[0];
    for (int i = 1; i <= n[0]; ++i)
        fin >> v[0][i];
    int sq = 1;
    for (int i = 2; i <= n[0]; ++i)
        if(v[0][i] != v[0][i-1])
            ++sq;
    int now = 0;
    while(1){
        int mx = 1, I=1, cnt = 1;
        for (int i = 2; i <= n[now]; ++i)
            if(v[now][i] == v[now][i-1]){
                ++cnt;
                if(cnt > mx){
                    mx = cnt;
                    I = i;
                }
            }else cnt = 1;
        if(mx < 3)
            break;
        int del = v[now][I];
        int l, r = I+1;
        for (int i = I; i >= 1 && v[now][i] == del; --i){
            v[now][i] = -1;
            l = i-1;
        }
        while(l >= 1 && r <= n[now] && v[now][l] == v[now][r]){
            cnt = 2;
            if(l >= 2 && v[now][l-1] == v[now][l])
                ++cnt;
            if(r <= n[now]-1 && v[now][r] == v[now][r+1])
                ++cnt;
            if(cnt == 2)
                break;
            del = v[now][l];
            while(l >= 1 && v[now][l] == del){
                v[now][l] = -1;
                --l;
            }
            while(r <= n[now] && v[now][r] == del){
                v[now][r] = -1;
                ++r;
            }
        }
        n[1-now] = 0;
        for (int i = 1; i <= n[now]; ++i)
            if(v[now][i] != -1)
                v[1-now][++n[1-now]] = v[now][i];
        now = 1-now;
    }
    if(test == 1)
        fout << sq << "\n";
    else{
        fout << n[now] << "\n";
        for (int i = 1; i <= n[now]; ++i)
            fout << v[now][i] << "\n";
    }
    return 0;
}

