#include <bits/stdc++.h>

using namespace std;

int n, v[5005];
int a[5005], u[5005];

int main()
{
    ifstream fin ("subsir2.in");
    ofstream fout ("subsir2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    a[n] = 1;
    u[n] = n;
    for (int i = n-1; i > 0; --i){
        int vmin = 2000000000, amin = 2000000000, U = i;
        for (int j = i+1; j <= n; ++j){
            if(v[j] >= v[i] && a[j] <= amin && v[j] < vmin){
                amin = a[j];
                U = j;
            }
            if(v[j] >= v[i])
                vmin = min(vmin, v[j]);
        }
        if(amin == 2000000000)
            amin = 0;
        a[i] = amin+1;
        u[i] = U;
    }
    int in = 1, vmin = v[1], amin = a[1];
    for (int i = 2; i <= n; ++i){
        if(a[i] <= amin && v[i] < vmin){
            amin = a[i];
            in = i;
        }
        vmin = min(vmin, v[i]);
    }
    fout << amin << "\n";
    for (; u[in] != in; in = u[in])
        fout << in << " ";
    fout << in << "\n";
    fin.close();
    fout.close();
    return 0;
}

