#include <bits/stdc++.h>

using namespace std;

struct point{
    int x, y, z;
}go[33][33][33], sol[33];

int v[33][33][33], best[33][33][33], care[33][33][33], n, mx2;

point make_point(int x, int y, int z)
{
    point aux;
    aux.x = x;
    aux.y = y;
    aux.z = z;
    return aux;
}

int main()
{
    ifstream fin ("drum2.in");
    ofstream fout ("drum2.out");
    fin >> n;
    int whatever = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            for (int k = 1; k <= i; ++k){
                fin >> v[i][j][k];
                care[i][j][k] = ++whatever;
            }
    best[1][1][1] = v[1][1][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            for (int k = 1; k <= i; ++k){
                int mx = v[i][j][k];
                if(best[i-1][j-1][k-1]+v[i][j][k] > mx){
                    mx = best[i-1][j-1][k-1]+v[i][j][k];
                    go[i][j][k] = make_point(i-1, j-1, k-1);
                }
                if(best[i-1][j-1][k]+v[i][j][k] > mx){
                    mx = best[i-1][j-1][k]+v[i][j][k];
                    go[i][j][k] = make_point(i-1, j-1, k);
                }
                if(best[i-1][j][k-1]+v[i][j][k] > mx){
                    mx = best[i-1][j][k-1]+v[i][j][k];
                    go[i][j][k] = make_point(i-1, j, k-1);
                }
                if(mx != v[i][j][k]){
                    if(i == n && mx > mx2){
                        mx2 = mx;
                        point p = make_point(i, j, k);
                        for (int i1 = n; i1; --i1){
                            sol[i1] = p;
                            p = go[p.x][p.y][p.z];
                        }
                    }
                    best[i][j][k] = mx;
                }
            }
    fout << mx2 << "\n";
    for (int i = 1; i <= n; ++i)
        fout << care[sol[i].x][sol[i].y][sol[i].z] << " ";
    fin.close();
    fout.close();
    return 0;
}

