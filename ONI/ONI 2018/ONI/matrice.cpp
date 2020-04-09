#include <bits/stdc++.h>

using namespace std;

int n, m, a[1005][1005], b[1005][1005], v[1005], aux, I1, I2, J1, J2, solI1, solI2, solJ1, solJ2, mx2;

void build_b(int v[], int r[])
{
    int t1 = -1, t2 = -1, t3 = -1;
    for (int i = m; i > 0; --i){
        if(t1 == -1){
            r[i] = m-i+1;
        }else if (t2 == -1){
            r[i] = m-i+1;
        }else if (t3 == -1){
            if(t1 == i+1)
                r[i] = m-i+1;
            else r[i] = t2-i;
        }else{
            if(t1 == i+1)
                r[i] = t3-i;
            else r[i] = t2-i;
        }
        if(i > 2){
            bool isT = (v[i] > v[i-1] && v[i-1] < v[i-2]) || (v[i] < v[i-1] && v[i-1] > v[i-2]);
            if(isT){
                if(t1 == -1){
                    t1 = i;
                }else if (t2 == -1){
                    t2 = t1;
                    t1 = i;
                }else{
                    t3 = t2;
                    t2 = t1;
                    t1 = i;
                }
            }
        }
    }
}

int calc()
{
    int mx;
    aux = n;
    for (int i = 2; i <= n; ++i)
        if(v[i] < v[1]){
            aux = i-1;
            break;
        }
    mx = aux*v[1];
    mx2 = v[1];
    I1 = 1;
    I2 = aux;
    aux = 1;
    for (int i = n-1; i; --i)
        if(v[i] < v[1]){
            aux = i+1;
            break;
        }
    if((n-aux+1)*v[n] > mx){
        mx = (n-aux+1)*v[n];
        mx2 = v[n];
        I1 = aux;
        I2 = n;
    }
    for (int i = 2; i <= n-1; ++i){
        aux = 1;
        for (int j = i-1; j; --j)
            if(v[j] < v[i]){
                aux = j+1;
                break;
            }
        int st = aux;
        aux = n;
        for (int j = i+1; j <= n; ++j)
            if(v[j] < v[i]){
                aux = j-1;
                break;
            }
        int dr = aux;
        if((dr-st+1)*v[i] > mx){
            mx = (dr-st+1)*v[i];
            mx2 = v[i];
            I1 = st;
            I2 = dr;
        }
    }
    return mx;
}

int main()
{
    ifstream fin ("matrice1.in");
    ofstream fout ("matrice1.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];
        build_b(a[i], b[i]);
    }
    int mx = -1;
    for (int j = 1; j <= m; ++j){
        for (int i = 1; i <= n; ++i)
            v[i] = b[i][j];
        int ergnreog = calc();
        if(ergnreog > mx){
            solI1 = I1;
            solI2 = I2;
            solJ1 = j;
            solJ2 = j+mx2-1;
            mx = ergnreog;
        }
    }
    fout << solI1 << " " << solJ1 << " " << solI2 << " " << solJ2 << "\n";
    fin.close();
    fout.close();
    return 0;
}

