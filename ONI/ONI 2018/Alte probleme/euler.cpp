#include <bits/stdc++.h>

using namespace std;

int n, x, tt[300000], s[600000], vf=0;
bool ok[300000];
vector<int> v;

int main()
{
    ifstream fin ("euler.in");
    ofstream fout ("euler.out");
    fin >> n;
    while(fin >> x){
        if(vf==0){
            tt[x] = 0;
            s[++vf] = x;
            ok[x] = 1;
        }else{
            s[++vf] = x;
            if(ok[x] == 1 && s[vf-2] != x){
                fout << "NU\n";
                return 0;
            }
            if(s[vf-2] == x){
                vf -= 2;
                ok[x] = 0;
            }else{
                tt[x] = s[vf-1];
                ok[x] = 1;
            }
        }
    }
    fout << "DA\n";
    for (int i = 1; i <= n; ++i)
        fout << tt[i] << " ";
    return 0;
}

