#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

struct thing{
    int val, x, y;
}bx[1505][1505], by[1505][1505], bxy[1505][1505];
ifstream fin ("bemo.in");
ofstream fout ("bemo.out");
int n, m, v[1505][1505], sqn, sqm;

thing make_thing(int val, int x, int y)
{
    thing aux;
    aux.val = val;
    aux.x = x;
    aux.y = y;
    return aux;
}

thing min(thing a, thing b)
{
    if(a.val < b.val)
        return a;
    return b;
}

void precalculare_batog()
{
    sqn = sqrt(n);
    sqm = sqrt(m);
    for (int l = 1; l <= m; ++l)
        for (int i = 1; i <= n-sqn+1; i+=sqn){
            thing mn = make_thing(2000000000, 0, 0);
            for (int j = i; j < i+sqn; ++j)
                if(v[j][l] < mn.val){
                    mn.val = v[j][l];
                    mn.x = j;
                    mn.y = l;
                }
            by[i][l] = mn;
        }
    for (int c = 1; c <= n; ++c)
        for (int j = 1; j <= m-sqm+1; j+=sqm){
            thing mn = make_thing(2000000000, 0, 0);
            for (int i = j; i < j+sqm; ++i)
                if(v[c][i] < mn.val){
                    mn.val = v[c][i];
                    mn.x = c;
                    mn.y = i;
                }
            bx[c][j] = mn;
        }
    for (int i = 1; i <= n-sqn+1; i += sqn)
        for (int j = 1; j <= m-sqm+1; j += sqm){
            thing mn = make_thing(2000000000, 0, 0);
            for (int i1 = i; i1 < i+sqn; ++i1)
                for (int j1 = j; j1 < j+sqm; ++j1)
                    if(v[i1][j1] < mn.val){
                        mn.val = v[i1][j1];
                        mn.x = i1;
                        mn.y = j1;
                    }
            bxy[i][j] = mn;
        }
}

thing batog(int i1, int j1, int i2, int j2)
{
    int b1, b2, i, j;
    for (b1 = 1; b1 < i1; b1 += sqn);
    for (b2 = 1; b2 < j1; b2 += sqm);
    thing mn = make_thing(2000000000, 0, 0);
    if(!(b1+sqn-1 <= i2 && b2+sqm-1 <= j2)){
        for (int k = i1; k <= i2; ++k){
            int t;
            for (t = j1; t < b2 && t <= j2; ++t)
                if(v[k][t] < mn.val)
                    mn = make_thing(v[k][t], k, t);
            for (t = b2; t+sqm-1 <= j2; t += sqm)
                mn = min(mn, bx[k][t]);
            for (; t <= j2; ++t)
                if(v[k][t] < mn.val)
                    mn = make_thing(v[k][t], k, t);
        }
        return mn;
    }
    for (i = b1; i+sqn-1 <= i2; i += sqn)
        for (j = b2; j+sqm-1 <= j2; j += sqm)
            mn = min(mn, bxy[i][j]);
    for (int k = i1; k < b1 && k <= i2; ++k){
        int t;
        for (t = j1; t < b2 && t <= j2; ++t)
            if(v[k][t] < mn.val)
                mn = make_thing(v[k][t], k, t);
        for (t = b2; t+sqm-1 <= j2; t += sqm)
            mn = min(mn, bx[k][t]);
        for (; t <= j2; ++t)
            if(v[k][t] < mn.val)
                mn = make_thing(v[k][t], k, t);
    }
    for (int k = i; k <= i2; ++k){
        int t;
        for (t = j1; t < b2 && t <= j2; ++t)
            if(v[k][t] < mn.val)
                mn = make_thing(v[k][t], k, t);
        for (t = b2; t+sqm-1 <= j2; t += sqm)
            mn = min(mn, bx[k][t]);
        for (; t <= j2; ++t)
            if(v[k][t] < mn.val)
                mn = make_thing(v[k][t], k, t);
    }
    for (int k = j1; k < b2 && k <= j2; ++k){
        int t;
        for (t = i1; t < b1 && t <= i1; ++t)
            if(v[t][k] < mn.val)
                mn = make_thing(v[t][k], t, k);
        for (t = b1; t+sqn-1 <= i2; t += sqn)
            mn = min(mn, by[t][k]);
        for (; t <= i2; ++t)
            if(v[t][k] < mn.val)
                mn = make_thing(v[t][k], t, k);
    }
    for (int k = j; k <= j2; ++k){
        int t;
        for (t = i1; t < b1 && t <= i1; ++t)
            if(v[t][k] < mn.val)
                mn = make_thing(v[t][k], t, k);
        for (t = b1; t+sqn-1 <= i2; t += sqn)
            mn = min(mn, by[t][k]);
        for (; t <= i2; ++t)
            if(v[t][k] < mn.val)
                mn = make_thing(v[t][k], t, k);
    }
    return mn;
}

void solve(int i1, int j1, int i2, int j2)
{
    if(i1 == i2){
        for (int j = j1; j < j2; ++j)
            fout << v[i1][j] << " ";
        return;
    }
    if(j1 == j2){
        for (int i = i1; i < i2; ++i)
            fout << v[i][j1] << " ";
        return;
    }
    thing bt1 = batog(i1+1, j1, i2, j2-1);
    thing bt2 = batog(i1, j1+1, i1, j2);
    thing bt3 = batog(i1, j2, i2-1, j2);
    thing mn = min(bt1, bt2);
    mn = min(mn, bt3);
    solve(i1, j1, mn.x, mn.y);
    solve(mn.x, mn.y, i2, j2);
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    precalculare_batog();
    solve(1, 1, n, m);
    fout << v[n][m] << "\n";
    fin.close();
    fout.close();
    return 0;
}

