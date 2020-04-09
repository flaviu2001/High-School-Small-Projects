#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
int n, m, k, v[405][405], test, sz[405*405], mx, sol, I = 1, J = 1;
char c[405][405], t, C;
bool ok[405][405];

bool check(int i1, int j1)
{
    return i1 > 0 && j1 > 0 && i1 <= n && j1 <= m;
}

void fill(int i1, int j1)
{
    ok[i1][j1] = 1;
    v[i1][j1] = k;
    ++sz[k];
    for (int i = 0; i < 4; ++i)
        if(check(i1+dx[i], j1+dy[i]) && c[i1+dx[i]][j1+dy[i]] == t && !ok[i1+dx[i]][j1+dy[i]])
            fill(i1+dx[i], j1+dy[i]);
}

void changing_cell(int i1, int j1)
{
    vector<int> r;
    vector<char> r2;
    for (int i = 0; i < 4; ++i)
        if(check(i1+dx[i], j1+dy[i]) && v[i1][j1] != v[i1+dx[i]][j1+dy[i]]){
            for (vector<int>::iterator it = r.begin(); it != r.end(); ++it)
                if(*it == v[i1+dx[i]][j1+dy[i]])
                    goto here;
            r.push_back(v[i1+dx[i]][j1+dy[i]]);
            r2.push_back(c[i1+dx[i]][j1+dy[i]]);
            here:
            {
                // if i didn't put these accolades here the compiler would complain
            }
        }
    if(r.size() == 1){
        if(sol < sz[r.back()] + 1){
            sol = sz[r.back()] + 1;
            I = i1;
            J = j1;
            C = r2.back();
        }
    }else if (r.size() > 1){
        int mx2 = 0;
        char cc;
        for (unsigned i = 0; i < r.size()-1; ++i)
            for (unsigned j = i+1; j < r.size(); ++j)
                if(r2[i] == r2[j] && mx2 < sz[r[i]] + sz[r[j]]){
                    mx2 = sz[r[i]] + sz[r[j]];
                    cc = r2[i];
                }
        if(r.size() > 2)
            for (unsigned i = 0; i < r.size()-2; ++i)
                for (unsigned j = i+1; j < r.size()-1; ++j)
                    for (unsigned l = j+1; l < r.size(); ++l)
                        if(r2[i] == r2[j] && r2[j] == r2[l] && mx2 < sz[r[i]] + sz[r[j]] + sz[r[l]]){
                            mx2 = sz[r[i]] + sz[r[j]] + sz[r[l]];
                            cc = r2[i];
                        }
        if(r.size() > 3)
            for (unsigned i = 0; i < r.size()-3; ++i)
                for (unsigned j = i+1; j < r.size()-2; ++j)
                    for (unsigned l = j+1; l < r.size()-1; ++l)
                        for (unsigned o = l+1; o < r.size(); ++o)
                            if(r2[i] == r2[j] && r2[j] == r2[l] && r2[l] == r2[o] && mx2 < sz[r[i]] + sz[r[j]] + sz[r[l]] + sz[r[o]]){
                                mx2 = sz[r[i]] + sz[r[j]] + sz[r[l]] + sz[r[o]];
                                cc = r2[i];
                        }
        if(mx2+1 > sol){
            sol = mx2+1;
            I = i1;
            J = j1;
            C = cc;
        }
    }
}

int main()
{
    ifstream fin ("ferma3.in");
    ofstream fout ("ferma3.out");
    fin >> test >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> c[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(!ok[i][j]){
                ++k;
                t = c[i][j];
                fill(i, j);
                mx = max(mx, sz[k]);
            }
    sol = mx; C = c[1][1];
    if(test == 1)
        fout << mx << "\n";
    else{
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                changing_cell(i, j);
        fout << I << " " << J << "\n" << C << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

