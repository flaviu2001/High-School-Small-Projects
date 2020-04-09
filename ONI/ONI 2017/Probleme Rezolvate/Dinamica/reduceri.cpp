#include <fstream>

using namespace std;

int v[105], n;
int r[105][105];

void read()
{
    ifstream fin ("reduceri.in");
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    fin.close();
}

int abs(int x)
{
    return x >= 0 ? x : -x;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int val(int i, int j)
{
    if(i != j)
        return abs(v[i]-v[j]) * (j-i+1);
    return v[i];
}

int calc(int p, int q)
{
    if(r[p][q] != 0)
        return r[p][q];
    if(p == q)
        return v[p];
    int mx = 0;
    for (int i = p; i < q; ++i){
        int x1 = calc(p, i), x2 = calc(i+1, q);
        r[p][i] = x1;
        r[i+1][q] = x2;
        mx = max(x1 + x2, mx);
    }
    mx = max(mx, val(p, q));
    return mx;
}

void write()
{
    ofstream fout ("reduceri.out");
    fout << calc(0, n-1) << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}
