#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, test, s[1005], v[1000005], val[1000005], p[1000005];
 
int main()
{
    ifstream fin ("aiacuxor.in");
    ofstream fout ("aiacuxor.out");
    fin >> n >> test >> m;
    for (int i = 0; i < m; ++i)
        fin >> s[i];
    for (int i = 0; i < n; ++i)
        v[i] = (s[i/m]^s[i%m])+i;
    for (int i = 0; i < n; ++i)
        val[0] ^= v[i];
    for (int i = 2; i < n; i += 2){
        if(i+1 > (n+1)/2){
            break;
        }
        val[i] = val[i-2];
        val[i] ^= v[n-i];
        if(n-1 != i-1)
            val[i] ^= v[i-1];
    }
    val[1] = v[0] ^ v[n-1];
    for (int i = 3; i < n; i += 2){
        if(i+1 > (n+1)/2)
            break;
        val[i] = val[i-2];
        val[i] ^= v[n-i];
        if(n-i != i-1)
            val[i] ^= v[i-1];
    }
    for (int i = (n+1)/2; i < n; ++i)
        val[i] = val[n-i-1];
    p[0] = val[0];
    for (int i = 1; i < n; ++i)
        p[i] = p[i-1]^val[i];
    int x, y, a, b, c, d;
    fin >> x >> y >> a >> b >> c >> d;
    for (int i = 1; i <= test; ++i){
        fout << (p[x-2] ^ p[y-1]) << "\n";
        int newx = (x*a+y*b)%n+1;
        int newy = (y*c+((p[x-2] ^ p[y-1])%n)*d)%n+1;
        if(newy < newx)
            swap(newx, newy);
        x = newx;
        y = newy;
    }
    return 0;
}
