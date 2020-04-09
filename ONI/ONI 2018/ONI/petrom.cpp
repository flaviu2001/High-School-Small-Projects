#include <bits/stdc++.h>

using namespace std;

int n, k, sp[405], sm;
int v[405][405], g[405][405], r[405], last[30005], vec[405];

int sum(int lft, int rig, int val)
{
    int sol = val*(rig-lft+1);
    sol -= sp[rig]-sp[lft-1];
    sol = abs(sol);
    return sol;
}

int bounds(int lft, int rig)
{
    int mid = last[(r[rig]+r[lft])/2];
    int sol = sum(lft+1, mid, r[lft]) + sum(mid+1, rig-1, r[rig]);
    return sol;
}

int main()
{
    ifstream fin ("petrom.in");
    ofstream fout ("petrom.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i){
        fin >> r[i];
        sm += r[i];
        sp[i] = sm;
    }
    int I = 1;
    for (int i = 1; i <= 30000; ++i){
        if(r[I] == i)
            ++I;
        last[i] = I-1;
    }
    for (int i = 1; i <= n; ++i){
        v[i][1] = sum(1, i-1, r[i]);
        g[i][1] = 0;
    }
    for (int t = 2; t <= k; ++t){
        g[t][t] = t-1;
        for (int i = t+1; i <= n; ++i){
            v[i][t] = v[i-1][t-1];
            g[i][t] = i-1;
            for (int j = i-2; j >= t-1; --j)
                if(v[i][t] >= v[j][t-1] + bounds(j, i)){
                    v[i][t] = v[j][t-1] + bounds(j, i);
                    g[i][t] = j;
                }
        }
    }
    int sol = v[n][k], J = n; I = n;
    for (int j = n-1; j >= k; --j)
        if(sol > v[j][k] + sum(j+1, n, r[j])){
            sol = v[j][k] + sum(j+1, n, r[j]);
            I = j;
            J = j;
        }
    for (int i = k; i > 0; --i){
        vec[i] = J;
        J = g[J][i];
    }
    fout << sol << "\n";
    for (int i = 1; i <= k; ++i)
        fout << vec[i] << "\n";
    fin.close();
    fout.close();
    return 0;
}

