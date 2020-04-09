#include <bits/stdc++.h>

using namespace std;

struct seg{
    int x1, y1, x2, y2;
};

const int nmax = 1005;
int n, szx, szy;
seg vx[nmax], vy[nmax];

int main()
{
    ifstream fin ("segmente.in");
    ofstream fout ("segmente.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        seg aux;
        fin >> aux.x1 >> aux.y1 >> aux.x2 >> aux.y2;
        if(aux.x1 > aux.x2)
            swap(aux.x1, aux.x2);
        if(aux.y1 > aux.y2)
            swap(aux.y1, aux.y2);
        if(aux.y1 == aux.y2)
            vx[szx++] = aux;
        else vy[szy++] = aux;
    }
    int sol = 2000000000, mn1, mn2, d;
    for (int i = 0; i < szx-1; ++i)
        for (int j = i+1; j < szx; ++j){
            mn1 = 2000000000, mn2 = 2000000000;
            for (int k = 0; k < szy; ++k){
                d = 0;
                if (vx[i].x2 < vy[k].x1)
                    d = vy[k].x1-vx[i].x2;
                else if (vx[i].x1 > vy[k].x1)
                    d = vx[i].x1-vy[k].x2;
                if (vy[k].y1 > vx[i].y1){
                    if(vy[k].y1-vx[i].y1 > d)
                        d = vy[k].y1-vx[i].y1;
                }else if (vy[k].y2 < vx[i].y1){
                    if (vx[i].y1-vy[k].y2 > d)
                        d = vx[i].y1-vy[k].y2;
                }
                if (vx[j].x2 < vy[k].x2){
                    if(vy[k].x1-vx[j].x2 > d)
                        d = vy[k].x1-vx[j].x2;
                }
                else if (vx[j].x1 > vy[k].x1){
                    if (vx[j].x1-vy[k].x2 > d)
                        d = vx[j].x1-vy[k].x2;
                }
                if (vy[k].y1 > vx[j].y1){
                    if(vy[k].y1-vx[j].y1 > d)
                        d = vy[k].y1-vx[j].y1;
                }
                else if (vy[k].y2 < vx[j].y1){
                    if(vx[j].y1-vy[k].y2 > d)
                        d = vx[j].y1-vy[k].y2;
                }
                if(d < mn1){
                    mn2 = mn1;
                    mn1 = d;
                }else if (d < mn2)
                    mn2 = d;
            }
            sol = min(sol, mn2);
        }
    fout << sol << "\n";
    return 0;
}

