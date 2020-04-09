#include <bits/stdc++.h>

using namespace std;

int a[10005], b[10005], v[10005], n, t1, t2, t3;

int main()
{
    ifstream fin ("log.in");
    ofstream fout ("log.out");
    fin >> n >> t1 >> t2 >> t3;
    for (int i = 1; i <= n; ++i){
        fin >> a[i] >> b[i];
        v[i] = (b[i]-a[i])*(b[i]-a[i])*t3+t1*(i!=1)+v[i-1];
        for (int j = i-1; j > 0; --j)
            if(b[j] == a[j+1]){
                v[i] = min(v[i], (a[j]-b[i])*(a[j]-b[i])*t3+t1*(j!=1) +v[j-1]+t2*(i-j));
            }else break;
    }
    fout << v[n] << "\n";
    fin.close();
    fout.close();
    return 0;
}

